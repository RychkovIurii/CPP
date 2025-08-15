# Choosing the Right STL Containers in Module 09 (Why It Matters, With Examples)

This note explains **why** container choice is essential in each exercise of Module 09, **given the module rules**:

- You **must** use standard containers to solve each exercise.
- **Once a container is used, it’s forbidden for the rest of the module.**
- Exercise 02 requires **two** different containers.
- Makefiles and compile flags are standardized (`-Wall -Wextra -Werror`), and you must use C++.

Because you cannot reuse containers, picking the **right container at the right time** ensures that the remaining exercises still have suitable options — without compromising performance, correctness, or code clarity.

---

## How to Think About Containers (Practical Criteria)

When selecting a container, focus on how your algorithm accesses and organizes data:

1. **Keyed lookup vs. positional access**  
   - Need fast lookup by a **key** with order semantics? → **`std::map`** (ordered, `O(log N)`, supports `lower_bound`).
   - Need index-based access with contiguous storage? → **`std::vector`**.
   - Need cheap push/pop at front/back with stable references? → **`std::deque`** or **`std::list`** (trade-offs differ).

2. **Ordering and range queries**  
   - Do you need “the closest prior element to some key”? → order-aware containers matter (e.g., `std::map::lower_bound`).

3. **Iteration and cache-friendliness**  
   - Heavy sequential iteration benefits from contiguous memory (**`std::vector`**).  
   - Frequent mid-sequence insertions/removals prefer **`std::list`** (but it sacrifices cache locality).

4. **Algorithmic constraints**  
   - Some problems naturally require **stack-like** (LIFO) behavior — use **`std::stack`** (adapter; typically backed by `std::deque`).

5. **Module planning**  
   Since containers are “consumed” once used, assign them **strategically** to match each exercise’s natural data access pattern.

> Below, we map typical problem needs to **sensible container choices** and show why they fit each exercise’s constraints.

---

## Exercise 00 — Bitcoin Exchange: Why `std::map` Fits Naturally

**Problem need**: Given a date from the input, multiply a value by the **exchange rate for that date**.  
If the exact date is **not** present, use the **closest earlier date** in the database.

**Why order matters**: You need to find “**the greatest key ≤ query**” — this is a classic ordered lookup.

**Container rationale**:  
- **`std::map<std::string, double>`** (or a date-typed key) keeps keys **sorted** and provides `lower_bound`/iterators.  
- You can do an `O(log N)` search to find the first element **not less than** the query key, then step back if needed.  
- Storing the entire CSV once at startup gives fast repeated lookups for the input file’s queries.

**Sketch**:
```cpp
// db: map<YYYY-MM-DD, rate>
std::map<std::string, double> db = load_csv("data.csv");

auto query = "2011-01-09"s;
auto it = db.lower_bound(query);

if (it == db.end()) {
    // All keys < query; use the last available date
    --it;
} else if (it->first != query) {
    // lower_bound is first key >= query
    if (it == db.begin()) {
        // No smaller date exists -> handle as an error or per spec
    } else {
        --it; // move to the closest *lower* date
    }
}
double rate = it->second;
// multiply rate by input value and print
```

**Why not a sequence container for the DB?** You would pay `O(N)` per lookup or need to sort and binary-search manually.  
`std::map` bakes in both **sorted order** and **logarithmic lookup** with clean, readable code — exactly matching the spec.

> **Planning note**: Using `std::map` here preserves `std::vector`/`std::deque` for Exercise 02.

---

## Exercise 01 — RPN: Why a `std::stack` (Adapter) Is a Perfect Fit

**Problem need**: Evaluate Reverse Polish Notation — a **LIFO** evaluation model.

**Container rationale**:  
- **`std::stack<T>`** provides exactly the operations you need: `push`, `pop`, `top`.  
- RPN naturally pushes operands and applies operators by popping the last two values — the stack models this directly.

**Sketch**:
```cpp
#include <stack>
#include <sstream>
#include <string>

int evalRPN(const std::string& expr) {
    std::stack<int> st;
    std::istringstream iss(expr);
    std::string tok;
    while (iss >> tok) {
        if (tok == "+" || tok == "-" || tok == "*" || tok == "/") {
            if (st.size() < 2) throw std::runtime_error("Error");
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            int r = 0;
            if (tok == "+") r = a + b;
            else if (tok == "-") r = a - b;
            else if (tok == "*") r = a * b;
            else if (tok == "/") { if (b == 0) throw std::runtime_error("Error"); r = a / b; }
            st.push(r);
        } else {
            st.push(std::stoi(tok));
        }
    }
    if (st.size() != 1) throw std::runtime_error("Error");
    return st.top();
}
```

**Why it fits**: The adapter **encapsulates the LIFO policy** cleanly; the intent is obvious and the interface minimal.  
(Under the hood it typically uses `std::deque`, but you interact through the stack abstraction — which is exactly what the task needs.)

> **Planning note**: Using `std::stack` here keeps other primary containers available for Exercise 02.

---

## Exercise 02 — PmergeMe (Ford–Johnson): Why Use Two Sequence Containers

**Problem need**: Implement merge-insert sort (Ford–Johnson), handle **≥ 3000 integers**, and display timings for **two different containers**.

**Natural choices**:  
- **`std::vector<int>`** — contiguous storage, strong **cache locality**, `operator[]`, and efficient traversal.  
- **`std::deque<int>`** — segmented contiguous blocks with efficient push/pop at both ends and stable complexity for large sequences.

**Why these two make sense together**:
- Both are **sequence containers** suited to index-like access and iteration, but they differ in memory layout and iterator invalidation rules.  
- Measuring both showcases how **data layout** and **iterator stability** impact performance for the **same algorithm**.  
- For Ford–Johnson, phases involving groupings, insertions, and binary searches often interact differently with `vector` and `deque` caches.

**Minimal driver shape** (illustrative sketch):
```cpp
// parse inputs -> std::vector<int> v; std::deque<int> d;
// run your Ford–Johnson on each
// report "Before", "After", and timings for both containers

// Timing illustration (use your own clock util)
auto t1 = now();
sortVector(v);
auto t2 = now();

auto t3 = now();
sortDeque(d);
auto t4 = now();

printBeforeAfter(...);
printTiming("vector", duration(t1, t2));
printTiming("deque",  duration(t3, t4));
```

**What you’ll observe**:  
- On many platforms, `vector` benefits from **contiguous memory** (fewer cache misses).  
- `deque` may handle certain insertion/removal patterns more gracefully without large reallocations.  
- The exercise explicitly asks you to **compare timings**, making these two a practical, instructive pair.

> **Planning note**: If you used `std::map` in Exercise 00 and `std::stack` in Exercise 01, both `vector` and `deque` remain available here, satisfying the “two containers” rule naturally.

---

## Why Picking the “Right” Container Protects You Later in the Module

Because containers are **single-use across the module**, an early “misfit” choice can leave you with **awkward leftovers** later. Proper pairing ensures:

- **Correctness with minimal code** (e.g., `map::lower_bound` exactly models “closest earlier date”).  
- **Performance that scales** (`O(log N)` lookups in ex00; good iteration/insertion profiles in ex02).  
- **Clarity for peer-evaluations** (container intent matches problem semantics: RPN ⇔ stack, ordered lookup ⇔ map).  
- **Compliance with rules** (you still have two solid sequence containers for the Ford–Johnson benchmark).

---

## Quick Decision Matrix

| Exercise | Core Need | Natural Container(s) | Why It Fits |
|---|---|---|---|
| **00 — Bitcoin Exchange** | Ordered keyed lookup; “closest lower date” | `std::map` | Sorted keys + `lower_bound` → clean `O(log N)` search for prior date |
| **01 — RPN** | LIFO evaluation of tokens | `std::stack` | Direct push/pop semantics; minimal surface and clear intent |
| **02 — PmergeMe** | Sequence sorting + timing comparison | `std::vector`, `std::deque` | Different memory layouts/behaviors; meaningful performance contrast |

---

## Final Takeaway

Choosing containers that **mirror your problem’s data semantics** makes the implementation **simpler, faster, and more explainable**, while also keeping you within the module’s **single-use** constraint. With ordered lookups (ex00), LIFO evaluation (ex01), and high-throughput sequence processing (ex02), the suggested matches are natural, robust, and evaluation-friendly.