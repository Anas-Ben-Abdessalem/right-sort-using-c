# 🧮 rsort — Reverse Alphabetical Word Sorter

## 📌 Overview

`rsort` is a C program developed as part of an Operating Systems exercise at Ruhr University Bochum.  
It reads a list of words from standard input (`stdin`), sorts them in **reverse alphabetical order**, and writes the sorted output to standard output (`stdout`).

Each word must be on a separate line, and output formatting strictly follows the specification.

---

## ✨ Features

- ✅ Reads words from `stdin`, each on a new line
- 🔄 Sorts the words in **reverse alphabetical order**
- ⚠️ Skips empty lines silently
- 🚫 Rejects lines exceeding 100 characters with an error (to `stderr`)
- 📥 Dynamically allocates memory with `malloc()` / `realloc()`
- 🧠 Uses `qsort()` for sorting
- 📛 All error messages are printed to `stderr`
- 🧪 Compatible with redirection (`< input.txt > output.txt`)
- 🧼 Tested with `valgrind` to ensure memory safety

---

## ⚙️ Compilation

To compile the program with the required flags:
```bash
gcc -std=c11 -pedantic -Wall -Werror -D_XOPEN_SOURCE=700 -o rsort rsort.c
