#include <stdio.h>
#include <stdbool.h>


int main() {
    for (int i = 1; i < argc; i++){
        printf("word %d: %s", i, argv[i]);
    }
    printf("argc: %d", argc);
    return 0;

}
