#include "day01_helper.c"

#if 0
#define INPUT_FILE "input_simple.txt"

#else
#define INPUT_FILE "input.txt"

#endif

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort_three(int *a, int *b, int *c){
    if (*a > *b) swap(a, b);
    if (*b > *c) swap(b, c);
    if (*a > *b) swap(a, b);
}


int main() {
    IntArray callories;
    int err = load_file(&callories, INPUT_FILE);
    if (err) return err;

    int max1 = callories.items[0];
    int max2 = callories.items[1];
    int max3 = callories.items[2];

    sort_three(&max1, &max2, &max3);

    

    for (size_t i = 3; i < callories.len; i++){
        if (callories.items[i] > max1) {
            max1 = callories.items[i];
            sort_three(&max1, &max2, &max3);
        }
    }
   
    printf("max1: %d \nmax2: %d \nmax3: %d\n", max1, max2, max3);
    printf("--------------------------\n");
    printf("result = %d\n", max1 + max2 + max3);
    printf("--------------------------\n");
    

    int_array_clear(&callories);

    return 0;
}