#include "day01_helper.c"

#if 0
#define INPUT_FILE "input_simple.txt"

#else
#define INPUT_FILE "input.txt"

#endif

int main() {
    IntArray callories;
    int err = load_file(&callories, INPUT_FILE);
    if (err) return err;

    int max;
    int_array_max(&callories, &max);

    printf("%d", max);

    int_array_clear(&callories);
    return 0;
}