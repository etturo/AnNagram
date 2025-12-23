# AnNagram

AnNagram is a C-based command-line tool designed to find multi-word anagrams for a given input string. It searches through a dictionary file to discover combinations of words that exactly match the characters of your input phrase.

## Features

- **Multi-word Anagrams:** Finds combinations of multiple words that form an anagram of the input.
- **Smart Filtering:** Efficiently filters the dictionary to only consider relevant words.
- **Text Normalization:** Handles case insensitivity and removes accents/diacritics (e.g., 'à' becomes 'a') to ensure robust matching.
- **Backtracking Algorithm:** Uses a backtracking approach to explore possible word combinations.

## Algorithm Implementation

The solution employs a **Backtracking** algorithm optimized with a pre-filtering step:

1.  **Frequency Mapping**: The input string is converted into a character frequency histogram (e.g., `hello` becomes `h:1, e:1, l:2, o:1`).
2.  **Dictionary Pruning**: Before starting the search, the entire dictionary is scanned. Words that cannot possibly be part of the solution (because they contain characters not present in the input or in higher quantities) are discarded. This drastically reduces the search space.
3.  **Recursive Backtracking**:
    -   The algorithm maintains the current state of available characters.
    -   It iterates through the valid words, attempting to build the anagram phrase word by word.
    -   When a word is chosen, its characters are subtracted from the available pool.
    -   If the pool becomes empty (all characters from the input are used), a valid anagram is found.
    -   If a branch is exhausted without using all characters, the algorithm backtracks, restoring the character pool and trying the next word.

## Prerequisites

- A C compiler (cc)
- Make

## Installation

1.  Clone the repository.
2.  Navigate to the project directory.
3.  Compile the project using the provided Makefile:

    ```bash
    make
    ```

    This will create an executable named `AnNagram`.

## Usage

Run the program by providing the string you want to find anagrams for as an argument:

```bash
./AnNagram "your phrase here"
```

### Example

```bash
./AnNagram "listen"
```

The program will read from `data/words.txt` and output all valid anagram combinations found, followed by the total count of solutions.

## Project Structure

- **`sources/`**: Contains the C source files.
    - `main.c`: Entry point, handles file reading and orchestration.
    - `checker.c`: Logic to verify if a word can be part of the anagram.
    - `word_comb.c`: Implements the backtracking algorithm to find word combinations.
    - `utility_functions.c`: String manipulation and normalization helpers.
    - `error_handling.c`: Error reporting functions.
- **`includes/`**: Header files.
- **`data/`**: Contains the dictionary file `words.txt`.
- **`Makefile`**: Build script.

## Data

The program relies on a dictionary file located at `data/words.txt`. Ensure this file exists and contains a list of valid words (one per line) for the program to work correctly.
