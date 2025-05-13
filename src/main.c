#include <stdio.h>
#include <stdbool.h>


int main() {
    char line[256];

    while (fgets(line, sizeof(line), stdin)) {
        printf("%s", line);
    }
}
