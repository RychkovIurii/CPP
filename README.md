# 42 C++ Modules Recap

This repository gathers my solutions to the 42 cursus C++ modules (CPP00–CPP09) plus assorted test material. Each module is a self-contained set of exercises exploring a specific language concept or STL usage.

## Module Highlights

### CPP00 — Warm Up & Basic Classes
- Command-line string manipulation with `megaphone.cpp`.
- Introduction to classes (`PhoneBook`, `Contact`) and simple I/O loops.
- Static class members and logging in the `Account` kata.

### CPP01 — Memory, Pointers, and References
- Zombie horde factory to practise dynamic allocation and stack/heap differences.
- Pointers vs references, random brain teaser classes, and string replacement utility.
- File I/O and resource management exercises capped off with pointer-to-member practice.

### CPP02 — Orthodox Canonical Form & Fixed-Point
- Implement canonical form (coplien form) across several fixed-point classes.
- Operator overloading (`+`, `-`, comparisons, stream insertion) for arithmetic types.
- Explore precision handling and const-correctness in value classes.

### CPP03 — Inheritance & Special Member Functions
- Diamond inheritance scenario with `ClapTrap` family, focusing on constructors/destructors.
- Method overriding, protected members, and the rule of three in derived classes.
- Introduces multiple inheritance through `DiamondTrap` behaviour composition.

### CPP04 — Polymorphism & Abstract Interfaces
- Polymorphic animals with deep copies to enforce proper resource ownership.
- Abstract base classes (`AMateria`, `ICharacter`) along with interfaces.
- Materia source implementation emphasises cloning and runtime polymorphism.

### CPP05 — Exceptions & Bureaucracy Simulation
- `Bureaucrat` grade validation backed by custom exception hierarchy.
- Chain of command with various `Form` derivatives and execute/grade rules.
- Introduces factories (`Intern`) and practice with try/catch blocks.

### CPP06 — C++ Casts & Serialization
- Scalar conversion utility highlighting `static_cast`, `reinterpret_cast`, etc.
- Serialization/deserialization of small structs using pointer casting.
- Type identification at runtime with `dynamic_cast` and polymorphic classes.

### CPP07 — Templates & Generic Programming
- Generic `swap`, `min`, `max`, and array iteration helpers.
- Template classes like `Array<T>` implementing range-safe indexing.
- Demonstrations of compile-time polymorphism with function/class templates.

### CPP08 — STL Containers & Algorithms
- `easyfind` exposes iterator-based search across containers.
- `Span` calculates shortest/longest span with bulk data insertion.
- `MutantStack` reveals iterator access on stack-adapter patterns.

### CPP09 — Algorithmic Containers & Parsing
- `BitcoinExchange` parses price histories and validates input formatting.
- Reverse Polish Notation evaluator with stack logic and robust error handling.
- `PmergeMe` implements Ford–Johnson merge-insert sort to benchmark vectors vs deques.


Each module includes its own `Makefile` where applicable; build individual exercises from inside their directory (`make && ./program`).
