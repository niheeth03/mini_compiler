# mini_compiler

A custom compiler project implementing a full toolchain: high‑level language, compiler, assembler/VM, and runtime — all built from scratch (using C / Yacc / Lex).

##  Project Overview

This project implements a complete compilation and execution pipeline:  
- A custom high‑level language  
- A compiler that translates high‑level code into lower-level/assembly (or intermediate code)  
- An assembler/VM for converting assembly to binary / interpreting intermediate code  
- (Optionally) ability to run programs on a simulated/target architecture  

This makes it possible to write code in a custom language and run it — useful for learning, research, or experimenting with compilers/VMs.

## Components

- `lex.yy.c`, `.l` files — lexical analysis using Lex  
- `.y`, parser files — syntax analysis with Yacc
- Compiler logic (in C) — processes parse tree / tokens, generates assembly or intermediate code  
- Example test files: `test1.c`, `test2.c`, … — sample input programs  
- `Makefile` — build automation for compiling the compiler + assembler + runtime  
- Output files (e.g. `y.tab.c`, compiled outputs) included for reference  

## Prerequisites

Make sure you have installed:

- GCC (or a C compiler)  
- `make`  
- `yacc` and `lex`  (for lexical and syntax parsing)  
- Standard Unix-like environment (Linux / macOS / WSL / etc.)  

## Build & Run Instructions

```bash
# At the root of the repo:
make clean      # optional, to clean previous build artifacts
make            # builds the compiler 

# To compile a test program (e.g. test1.c):
./parser     test1.c  

