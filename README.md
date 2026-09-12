# Competitive Programming

My competitive-programming journey in C++ and Java. This repository contains
solutions to programming problems, algorithm implementations, and reusable
templates.

## Repository structure

```text
.
├── algorithms/
│   ├── graph/          # BFS, DFS, cycle detection, shortest paths
│   └── search/         # Binary search and binary search on the answer
├── java/               # Java practice files
├── practice/           # Personal experiments and unsorted practice
├── solutions/
│   ├── codeforces/     # Codeforces solutions
│   ├── cses/           # CSES problem set solutions
│   └── usaco/          # USACO solutions
└── templates/          # Reusable competitive-programming templates
```

## Topics covered

- Graph algorithms: BFS, DFS, connected components, cycle detection, path reconstruction
- Shortest paths
- Binary search and binary search on the answer
- Prefix sums and subarray problems
- Greedy algorithms
- Trees and functional graphs

## Running a C++ solution

Compile a file with a C++17 compiler:

```bash
g++ -std=c++17 -O2 -Wall solutions/cses/Labyrinth.cpp -o solution
./solution
```

## Notes

- Each source file is intended to solve one problem independently.
- Generated files such as `.exe`, `.out`, and `.class` are ignored by Git.
