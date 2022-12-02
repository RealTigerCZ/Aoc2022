#include <stdio.h>
#include <errno.h>
#include <string.h>

#define eprint(s, ...) fprintf(stderr, "[ERROR] "__FILE__ ":%u: "s" \n", __LINE__, __VA_ARGS__)

#if 1
#define INPUT_FILE "input_simple.txt"

#else
#define INPUT_FILE "input.txt"

#endif

int main(){
    FILE *file = fopen(INPUT_FILE, "r");
    if (!file) {
        eprint("Could not open file: %s. %s", INPUT_FILE, strerror(errno));
        return 1;
    }

    printf("File loaded");


    fclose(file);
    return 0;
}