#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_WORD_LENGTH 100 // Maximum allowed size of chars per word (without \n)

// Comparison function for qsort in a reversed alphabetical order
int compare_words(const void *a, const void *b) {
    const char *str_a = *(const char **)a;
    const char *str_b = *(const char **)b;
    return -strcmp(str_a, str_b);  // - sign to reverse order
}

int main() {
    char **words = NULL;
    int word_count = 0;
    int capacity = 0;
    char buffer[MAX_WORD_LENGTH + 2]; // +2 for \n and \0

    // Read words from stdin
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        // Check for empty line
        if (buffer[0] == '\n') {
            continue;
        }

        // Remove newline if present (strlen returns size_t)
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
            len--;
        }

        // Check for word length limit
        if (len > MAX_WORD_LENGTH) {
            fprintf(stderr, "Error: Line exceeds maximum length of %d characters: ignored\n", 
                    MAX_WORD_LENGTH);
            // Discard remaining characters of long line
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }

        // Allocate memory for the word
        char *word = malloc(strlen(buffer) + 1);  // +1 for null terminator
        if (word == NULL) {
            fprintf(stderr, "Error: malloc for word failed: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
        strcpy(word, buffer);

        // Grow the words array if needed
        if (word_count >= capacity) {
            capacity = capacity == 0 ? 1 : capacity * 2;
            char **temp = realloc(words, capacity * sizeof(char *));
            if (temp == NULL) {
                fprintf(stderr, "Error: realloc failed: %s\n", strerror(errno));
                free(word);
                exit(EXIT_FAILURE);
            }
            words = temp;
        }

        words[word_count++] = word;
    }

    // Check for read errors
    if (ferror(stdin)) {
        fprintf(stderr, "Error: Reading from stdin failed\n");
        exit(EXIT_FAILURE); // Broken input stream
    }

    // Sort the words
    qsort(words, word_count, sizeof(char *), compare_words);

    // Output the sorted words
    for (int i = 0; i < word_count; i++) {
        if (puts(words[i]) == EOF) {
            fprintf(stderr, "Error: Writing to stdout failed\n");
            free(words[i]);
            break;
        }
        free(words[i]); // Free each word as we print it
    }

    free(words); // Free the words array
    return 0;
}
