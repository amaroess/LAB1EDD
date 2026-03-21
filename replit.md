# C ADT Lab - Lists and Stacks

## Overview
This is an educational C laboratory focused on implementing Abstract Data Types (ADTs) — specifically Lists and Stacks. Students implement exercises in `exercises.c` and run a test suite to validate their work.

## Project Structure
- `exercises.c` — Student implementation file (modify this to complete exercises)
- `arraylist.h` / `arraylist.c` — ArrayList ADT implementation
- `stack.h` — Stack ADT (header-only, wraps ArrayList)
- `test.c` — Test suite that validates student implementations
- `test.sh` — Build and run script (compiles and executes tests, handles Git tracking)
- `README.md` — Lab instructions in Spanish

## How to Run
The workflow `Start application` runs `bash test.sh`, which:
1. Checks for changes in `exercises.c`
2. Compiles with `gcc -g test.c -Wall -Werror -o a.out`
3. Runs `./a.out` to display test results
4. Optionally syncs progress to GitHub

## Workflow
- **Type:** Console (CLI application, no web server)
- **Command:** `bash test.sh`
- **Output type:** console

## Exercises
1. `crea_lista()` — Create a list with integers 1–10
2. `sumaLista()` — Sum all elements in a list
3. `eliminaElementos()` — Remove all occurrences of a value from a list
4. `copia_pila()` — Copy a stack while preserving order
5. `parentesisBalanceados()` — Check if parentheses in a string are balanced
