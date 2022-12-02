#include <stdio.h>
#include <errno.h>
#include <stdint.h>
#include <limits.h>
#include <string.h>

#define INT_ARRAY_IMPLEMENTATION
#include "../Helper/dynamic_array.c"

#define eprintf(s, ...) fprintf(stderr, "[ERROR] "__FILE__ ":%u: "s" \n", __LINE__, __VA_ARGS__)
#define eprint(s) fprintf(stderr, "[ERROR] "__FILE__ ":%u: "s" \n", __LINE__)


int read_line(FILE *file){
    int c;
    int64_t num = 0;
    
    while (69420){
        c = fgetc(file);

        if (c == '\r') continue;

        if (c == '\n') return num;

        if (c == EOF)  {
            if (num) return num;
            return EOF;
        }

        if (c < '0' || c > '9') return -3;

        num *= 10;
        num += c - '0';
        if (num > INT_MAX) return -2;
    }
}


int load_file(IntArray *callories, const char* input_file){
    FILE *file = fopen(input_file, "r");
    if (!file) {
        eprintf("Could not open file: %s. %s", input_file, strerror(errno));
        return 1;
    }

    int_array_init(callories);

    int64_t num = 0;
    int tmp;
    int done = 0;
    while(!done){
        tmp = read_line(file);
        switch (tmp) {
        case -3:
            eprint("Found invalid number :(\n");
            fclose(file);
            return 1;

        case -2:
            eprint("Integer overflow :(\n");
            fclose(file);
            return 1;

        case -1:
            if (num) {
                if (int_array_append(callories, (int) num)) {
                    eprint("Alocation error :(\n");
                    fclose(file);
                    return 1;
                }
            }
            done = 1;
            break;

        case 0:
            if (int_array_append(callories, (int)num)){
                eprint("Alocation error :(\n");
                fclose(file);
                return 1;
            }
            num = 0;
            break;

        default:
            num += tmp;
            if (num > INT_MAX) {
                eprint("Integer overflow :(\n");
                fclose(file);
                return 1;
            }
            break;
        }
    }
    fclose(file);
    return 0;
}