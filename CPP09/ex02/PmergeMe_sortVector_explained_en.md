# `PmergeMe::sortVector` — Detailed Walkthrough

This document explains **how my function works**, step by step, with concrete, reproducible mini‑examples.  


---

## High-level idea

my `sortVector` performs a **two-stage** process wrapped in a self-recursive lambda:

1. **Phase 1 — Pairwise block swapping (iterative, doubling `pairsize`)**  
   You sweep the array in blocks of size `pairsize`, comparing the **tail elements** of the two adjacent blocks.  
   If the right block's tail is smaller than the left block's tail, you **swap entire blocks**.  
   You then recurse with `pairsize *= 2` until `pairsize > vec.size()/2`.  
   This produces large, reasonably ordered blocks using very few comparisons.

2. **Phase 2 — 2D chunking + bounded insertion by Jacobsthal batches**  
   The vector is sliced into equal-sized **chunks** (`pairsize` each), each stamped with a **stable `id`**.  
   Chunks are split into a **main** sequence and a **pending** sequence (`pend`).  
   Elements of `pend` are inserted into `main` in **Jacobsthal-sized batches**, with a **search bound** defined by an **anchor chunk** `a_j`.  
   Insertion position is found by `std::lower_bound` on the **last element** of each chunk.  
   Once `pend` is empty, `main` is **flattened** back into `vec`.

Along the way, all value comparisons use my `CountingLess` comparator, which increments the global counter — making it easy to audit the number of comparisons during experiments.

---

## The code skeleton (for reference)

Key elements as they appear in my implementation (summarized, not verbatim):

- **Recursive driver** `mergeSortVec(self, pairsize, insert)`  
  - Phase 1 runs if `insert == false`:
    - Loop `i += pairsize * 2`
    - Compute `mid = i + pairsize`, `end = min(i + 2*pairsize, vec.size())`
    - Base condition: if `vec.size()/2 < pairsize` → set `insert = true; return;`
    - If both blocks fully present: compare `vec[end-1]` vs `vec[mid-1]` using `CountingLess`
      - If right tail `<` left tail → **swap the whole blocks** element-by-element
    - Recurse: `self(self, pairsize*2, insert)`
  - **Phase 2** (executes as recursion unwinds):
    - Build `temp` as a list of `VChunk{ data: vector<int>, id: size_t }`, each of length `pairsize` (full chunks only)
    - Partition into:
      - `main`: `temp[0]` (called `b1`), plus all **odd** indices (`a1, a2, ...`)
      - `pend`: all **even** indices `>= 2` (`b2, b3, ...`)
    - Initialize Jacobsthal window: `jacob = 3`, `jacob_prev = 1`
    - While `pend` not empty:
      - `batch = jacob - jacob_prev`
      - For `i in [0, batch)` pick the chunk **from the batch window** (by index within `pend`, counting from the end if needed)
      - Find its **original index** `j` in `temp` **by `id`**
      - Find **anchor** `a_j = temp[j+1]` (if exists); locate its position in `main` (by `id`) → `boundElement`
      - Compute **search bound**: if `boundElement == 0` → unbounded (`bound = main.size()`), else `bound = boundElement`
      - Binary search (`lower_bound`) on `main[0..bound)` comparing **last elements** of chunks (`A.data[pairsize-1]` vs `B.data[pairsize-1]`)
      - Insert selected chunk into `main` at that position and erase it from `pend`
      - If `pend` becomes empty, **flatten** `main` into `vec` and `return`
      - Advance Jacobsthal numbers: `jacob, jacob_prev = jacob + 2*jacob_prev, jacob`

---

## Phase 1 in action — Pairwise block swapping

### Tiny example: `vec = [4, 1, 5, 2, 6, 3, 7, 0]`

We trace the first rounds. Here `N = 8`, so `N/2 = 4`:

**Round `pairsize = 1`** (unit blocks):
- Compare tails of `[4] | [1]` → `1 < 4` → swap blocks → `vec = [1, 4, 5, 2, 6, 3, 7, 0]`
- Compare `[5] | [2]` → `2 < 5` → swap → `vec = [1, 4, 2, 5, 6, 3, 7, 0]`
- Compare `[6] | [3]` → swap → `vec = [1, 4, 2, 5, 3, 6, 7, 0]`
- Compare `[7] | [0]` → swap → `vec = [1, 4, 2, 5, 3, 6, 0, 7]`

**Round `pairsize = 2`** (2-sized blocks):
- Blocks: `[1,4] | [2,5]` tails `4` vs `5` → `5 < 4`? no → no swap
- Blocks: `[3,6] | [0,7]` tails `6` vs `7` → `7 < 6`? no → no swap

**Round `pairsize = 4`**:
- Blocks: `[1,4,2,5] | [3,6,0,7]` tails `5` vs `7` → `7 < 5`? no → no swap
- Next pair would exceed `N` → stop this round

**Round `pairsize = 8`** exceeds `N/2` → base condition triggers → return to previous frame.  
Now Phase 2 will execute with `pairsize = 4`.

> Intuition: After Phase 1, the array is arranged in **reasonably ordered blocks** of size `pairsize`.  
> Full sorting is driven by Phase 2’s batched insertions.

---

## Phase 2 — Build chunks and split into `main` and `pend`

Let’s use a slightly larger example so that `pend` is non-empty.

### Example setup
- `vec` length `N = 12`
- Assume Phase 1 concluded with `pairsize = 4`
- my code builds **full** chunks of size 4 (incomplete trailing parts are **skipped by design**)

Suppose after Phase 1 we have:
```
vec = [  7,  9, 12, 14,   2,  5, 11, 13,   3,  4,  6, 10 ]
          ^chunk0^        ^chunk1^          ^chunk2^
```
- `temp[0] = {data:[7,9,12,14], id:0}`
- `temp[1] = {data:[2,5,11,13], id:1}`
- `temp[2] = {data:[3,4,6,10],  id:2}`

**Partitioning (exactly as in my loop):**
- `main` gets `temp[0]` (named **b1**) and **all odd indices** → `temp[1]` (**a1**)  
  → `main = [ id:0 (b1), id:1 (a1) ]`
- `pend` gets **even indices ≥ 2** → `temp[2]` (**b2**)  
  → `pend = [ id:2 (b2) ]`

---

## Phase 3 — Jacobsthal-batched bounded insertions

You start with `jacob = 3`, `jacob_prev = 1`.  
So the first **batch size** is `batch = jacob - jacob_prev = 2` (you will attempt up to 2 insertions in this window, as available).

### Picking an element to insert
Within each batch you choose from `pend` based on a Jacobsthal window policy:
- If enough elements exist, you pick by the calculated index within the window (`pend[batch - 1 - i]`)
- Otherwise, you pick the **last** element of `pend`

In our example, `pend = [ id:2 ]` so the chosen chunk is always `id:2`.

### Finding the **bound** via anchor `a_j`
- Find `jIndex` of the chunk in `temp` **by `id`** (not by values)
  - Here `id:2` → `jIndex = 2`
- Compute its anchor `a_j = temp[jIndex + 1]` **if it exists**
  - Here `jIndex + 1 = 3` is **out of range**, so there is **no anchor**
- my code sets `boundElement = 0` if anchor not found (or if not in `main`), and then:
  - `bound = (boundElement == 0) ? main.size() : boundElement`
  - With no anchor, this means **unbounded search** (use entire `main`).

### Binary search key
Insertion position is found by:
```cpp
lower_bound(main.begin(), main.begin() + bound,
            num_to_insert,
            [&](const VChunk& A, const VChunk& B){
              return CountingLess()(A.data[pairsize - 1], B.data[pairsize - 1]);
            });
```
- Comparison is by the **last element** of each chunk.  
- For `pairsize = 4`, that’s `A.data[3]` and `B.data[3]`.
- This leverages the fact that **tails** carry enough ordering signal after Phase 1.

### Inserting and erasing
- The selected chunk is inserted into `main` at the `lower_bound` position (respecting `bound`)
- The exact chunk is then erased from `pend` **by `id`** using `std::find_if`

### Flattening
- When `pend` becomes empty inside the loop, you **flatten `main`** back into `vec` by concatenating chunk contents in order.  
- You also reset Jacobsthal variables and `return`.

---

## Worked mini-trace of Phase 3 (using the example)

- `main = [ id:0 ({...14}), id:1 ({...13}) ]`  
  (tails are `14` and `13` respectively)
- `pend = [ id:2 ({...10}) ]` (tail `10`)

**Batch 1** (`jacob=3`, `jacob_prev=1`, `batch=2`):
- Pick `id:2` from `pend`
- No anchor → `bound = main.size() = 2`
- `lower_bound` by tails on `main[0..2)`:
  - Compare `14` vs `10` → `10 < 14` → position before `id:0`
  - Insert `id:2` at the front
- Erase `id:2` from `pend` → `pend` is now empty
- **Flatten**: `vec = chunk(id:2) + chunk(id:0) + chunk(id:1)`

Resulting order respects the tail-based ordering within the chosen bound.

All comparisons here go through `CountingLess`, incrementing my global counter.

---

## Notes on control flow

- **Why Phase 2 runs once recursion stops:**  
  When the deepest recursive call hits `vec.size()/2 < pairsize`, it returns **without** running Phase 2.  
  Control unwinds to the previous frame (the last frame with `pairsize <= vec.size()/2`), and **that frame then continues** into Phase 2 using its `pairsize`.

- **Chunk completeness:**  
  The inner loop that constructs chunks requires `i + pairsize <= vec.size()`.  
  This means only **full chunks** are formed; any trailing remainder shorter than `pairsize` is intentionally **ignored** when building `temp`.

---

## Micro example showing `CountingLess` in Phase 1

Take `vec = [3, 1]`, `pairsize = 1`:
- `mid = 1`, `end = 2`
- Compare `vec[end-1]=1` with `vec[mid-1]=1`? (both `1`? No: `mid-1=0 → 3`, `end-1=1 → 1`)
- `CountingLess()(1, 3)` returns `true` and increments `g_comparisonCount`
- Blocks swap → `vec = [1, 3]`

In Phase 3, each step of `lower_bound` similarly triggers `CountingLess` comparisons on chunk tails.

---

## End-to-end micro run (N = 12)

1. **Phase 1** runs for `pairsize = 1, 2, 4`; base triggers at `pairsize = 8`
2. **Phase 2** runs with `pairsize = 4`:
   - Chunks: `temp[0], temp[1]` go to `main`; `temp[2]` goes to `pend`
   - Jacobsthal batch picks from `pend`, finds bound via anchor (or full range if none), inserts by tail
   - When `pend` empties, flatten `main` → `vec`

This is exactly the flow encoded in my function.