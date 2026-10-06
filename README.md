# ECE250 Practice Problems

A C++ workspace for data structures and algorithms classwork.

## Start here

Run the sample problem from PowerShell:

```powershell
.\run.ps1
```

Or pass a different source file:

```powershell
.\run.ps1 problems\example.cpp
```

The script compiles with C++20, writes executables to `build/`, and runs the result.

## Layout

- `problems/` — one `.cpp` file per practice problem
- `include/` — reusable data structures and helper headers
- `tests/` — tests and test data
- `notes/` — class notes, pseudocode, and complexity analyses

Copy `problems/example.cpp` when beginning a new problem. Use a descriptive filename such as `linked_list.cpp` or `binary_search_tree.cpp`.

## Useful Git commands

```powershell
git status
git add .
git commit -m "Solve linked list problem"
```

