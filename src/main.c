#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char** argv) {
    if (argc == 1) {
        char** ptr = environ;
        while (*ptr) {
            printf("%s\n", *ptr);
            ptr++;
        }

        return 0;
    }

    for (int i = 1; i < argc; i++) {
        char* variable = getenv(argv[i]);
        if (variable != NULL) {
            while (*variable) {
                if (*variable == '=') {
                    variable++;
                    printf("%s\n", variable);
                    break;
                }

                variable++;
            }
        }
    }
}