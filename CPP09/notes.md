NEED 

function FORD_JOHNSON(A):
    if size of A ≤ 1:
        return A

    Initialize MAIN_CHAIN as empty list
    Initialize TO_INSERT as empty list

    For each pair of elements (x, y) in A:
        if x > y:
            swap x and y
        Add x (the smaller) to MAIN_CHAIN
        Add y (the larger) to TO_INSERT

    If A has an odd number of elements:
        Add the last unpaired element to TO_INSERT

    Recursively sort MAIN_CHAIN using FORD_JOHNSON

    For each element in TO_INSERT:
        Insert it into MAIN_CHAIN at the correct position
        (use binary search to find the correct position)

    Return MAIN_CHAIN


Example:
Input: 5 2 8 3 7

Steps:

Pairs: (5,2), (8,3), and unpaired 7

MAIN_CHAIN: 2,3 (smaller of each pair)

TO_INSERT: 5,8,7 (larger of each pair + unpaired)

Recursively sort MAIN_CHAIN → 2,3

Insert 5 → 2,3,5

Insert 7 → 2,3,5,7

Insert 8 → 2,3,5,7,8

Output: 2 3 5 7 8

**merge-insert (Ford–Johnson) sort** clearly and give a **step-by-step pseudocode.**

The algorithm is designed to minimize the *number of comparisons* when sorting a sequence — it’s more efficient than merge sort or insertion sort in this metric, and is optimal for small $n$.

---

## 📖 Idea

Merge-insert sort combines two ideas:

* split into pairs, sort pairs
* recursively sort the largest elements of pairs
* insert the smaller elements of pairs into their proper place in the sorted sequence

So you first partially sort and then carefully insert the remaining elements in the right spots.

---

## 📝 Pseudocode

We assume we sort array $A[1..n]$.

---

### Function: `merge_insert_sort(A)`

```
function merge_insert_sort(A[1..n]):
    if n <= 1:
        return A

    // Step 1: Pair up elements
    pairs = []
    for i from 1 to floor(n/2):
        if A[2i-1] > A[2i]:
            swap A[2i-1], A[2i]
        pairs.append( (A[2i], A[2i-1]) )  // (larger, smaller)

    if n is odd:
        leftover = A[n]
    else:
        leftover = null

    // Step 2: Recursively sort the larger elements of each pair
    larger_elements = [pair[0] for pair in pairs]
    sorted_larger = merge_insert_sort(larger_elements)

    // Step 3: Insert smaller elements of pairs into sorted sequence
    for each pair in pairs:
        smaller = pair[1]
        insert smaller into sorted_larger at correct position

    // Step 4: If odd, insert the leftover element
    if leftover != null:
        insert leftover into sorted_larger at correct position

    return sorted_larger
```

---

### Explanation of steps:

🔷 Step 1: Pair the elements into $\lfloor n/2 \rfloor$ pairs.
Within each pair, sort so that larger is first.

🔷 Step 2: Recursively sort the larger elements — this is a key idea: you sort a smaller subset.

🔷 Step 3: Take each smaller element from each pair, and insert it (by binary search or linear scan) into the sorted sequence.
Since there are only $\lfloor n/2 \rfloor$ small elements, you only do $O(n \log n)$ work here.

🔷 Step 4: If $n$ is odd, one element is left unpaired — insert it at the end.

---

## 🧪 Example: Input `[5, 3, 8, 1]`

* Pair: `(5, 3)` → `(5, 3)`
* Pair: `(8, 1)` → `(8, 1)`
* Larger: `[5, 8]`, recursively sort → `[5, 8]`
* Insert `3` → `[3, 5, 8]`
* Insert `1` → `[1, 3, 5, 8]`
* Done.

---

### Complexity

* Comparison count is minimized, close to optimal: $\log_2(n!)$
* Still $O(n \log n)$ time complexity.

---


jacobsthal = [1]
while jacobsthal.back() < smalls.size():
    jacobsthal.push_back(jacobsthal[-1] + 2 * jacobsthal[-2])

for index in jacobsthal:
    if index-1 >= smalls.size(): break
    val = smalls[index-1]
    insert val into bigs (binary search)