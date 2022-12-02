#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#define INT_ARRAY_INIT_SIZE 8
#define INT_ARRAY_ALLOC_CHUNK 8
#define INT_ARRAY_ALLOC_THRESHOLD 32
#define INT_ARRAY_ALLOC_PERCENT 1.25f

#include <stdlib.h>
#include <string.h>


#ifdef INT_ARRAY_IMPLEMENTATION

typedef struct{
    int *items;
    size_t len;
    size_t cap;
} IntArray;

IntArray *int_array_constructor(){
    IntArray *IA = malloc(sizeof(IntArray));
    if (IA == NULL) return NULL;

    IA->items = malloc(sizeof(int) * INT_ARRAY_INIT_SIZE);
    if (IA->items == NULL) {
        free(IA);
        return NULL;
    }

    IA->len = 0;
    IA->cap = INT_ARRAY_INIT_SIZE;

    return IA;
}

// return 0 on success, 1 on error
int int_array_init(IntArray *IA){
    if (IA == NULL) return 1;

    IA->items = malloc(sizeof(int) * INT_ARRAY_INIT_SIZE);
    if (IA->items == NULL) return 1;

    IA->len = 0;
    IA->cap = INT_ARRAY_INIT_SIZE;

    return 0;
}

void int_array_destructor(IntArray *IA){
    if (IA){
        free(IA->items);
    }
    free(IA);
}

int int_array_clear(IntArray *IA){
    if (IA == NULL) return 1;
    free(IA->items);
    IA->cap = 0;
    IA->len = 0;
    IA->items = NULL;
    return 0;
}

// 0 success, 1 allocation error, -1 other error
int int_array_resize(IntArray *IA, size_t new_cap){
    if (IA == NULL || new_cap == 0) return -1;
    
    int *tmp = realloc(IA->items, new_cap * sizeof(int));
    if (tmp == NULL) return 1;

    IA->items = tmp;
    IA->cap = new_cap;
    return 0;
}


int int_array_fill(IntArray *IA, int n, size_t size){
    if (IA == NULL) return 1; //TODO: asserty??
    if (IA->items == NULL) return 1;
    if (size == 0) return 1;

    if (size > IA->cap){
        int err = int_array_resize(IA, size); 
        if (err) return 1;
    }

    memset(IA->items, n, IA->cap * sizeof(int));
    IA->len = size;

    return 0;    
}

size_t __int_array_get_new_cap_by_one(size_t cap){
    if (cap <= INT_ARRAY_ALLOC_THRESHOLD) {
        return cap + INT_ARRAY_ALLOC_CHUNK;
    }
    return (size_t) ((float) cap * INT_ARRAY_ALLOC_PERCENT);
}


size_t __int_array_get_new_cap(size_t cap, size_t needed_space){
    if (cap >= needed_space) { //TODO: panic 
        return 0;
    } 
    cap = needed_space - cap;
    size_t remainder = INT_ARRAY_ALLOC_CHUNK - (needed_space % INT_ARRAY_ALLOC_CHUNK);
    
    if (cap + needed_space <= INT_ARRAY_ALLOC_THRESHOLD) {   
        return cap + needed_space + remainder;
    }

    return (size_t) ((float) (cap + needed_space + remainder) * INT_ARRAY_ALLOC_PERCENT);
}


int int_array_append(IntArray *IA, int elem){
    if (IA == NULL) return -1;
    if (IA->items == NULL) return -1;

    if (IA->len >= IA->cap){
        size_t new_cap = __int_array_get_new_cap_by_one(IA->cap);
        int err = int_array_resize(IA, new_cap);
        if (err) return 1;
    }

    IA->items[IA->len] = elem;
    IA->len += 1;

    return 0;
}

int int_array_insert_at(IntArray *IA, int idx, int elem){
    if (IA == NULL) return -1;
    if (IA->items == NULL) return -1;
    if (idx > (int) IA->len || idx < 0) return -1;

    if (IA->len >= IA->cap){
        size_t new_cap = __int_array_get_new_cap_by_one(IA->cap);
        int err = int_array_resize(IA, new_cap);
        if (err) return 1;
    }

    for (size_t i = IA->len; i > (size_t) idx; i--){
        IA->items[i] = IA->items[i - 1];
    }

    IA->items[idx] = elem;
    IA->len += 1;

    return 0;
}


int int_array_pop(IntArray *IA, int *to){
    if (IA == NULL || IA->items == NULL || IA->len == 0) return 1;

    *to = IA->items[IA->len-1];
    IA->len -= 1;

    if (IA->len > INT_ARRAY_INIT_SIZE && IA->len * 2 < IA->cap){
        int_array_resize(IA, IA->cap / 2);
    } 
    return 0;
}

int int_array_pop_at(IntArray *IA, int idx, int *to){
    if (IA == NULL || IA->items == NULL || IA->len == 0) return 1;
    if (abs(idx) >= IA->len) return 1;

    if (idx < 0){
        idx = IA->len + idx;
    }
     
    *to = IA->items[idx];
    IA->len -= 1;

    for (size_t i = idx; i < IA->len; i++) { //memmove?
        IA->items[i] = IA->items[i + 1];
    }

    if (IA->len > INT_ARRAY_INIT_SIZE && IA->len * 2 < IA->cap){
        int_array_resize(IA, IA->cap / 2);
    } 

    return 0;
}

int int_array_max(IntArray *IA, int *max){
    if (IA == NULL || IA->items == NULL) return 1;
    if (IA->len == 0) return 1;

    *max = IA->items[0];
    for (size_t i = 1; i < IA->len; i++) {
        if (IA->items[i] > *max) *max = IA->items[i];
    }
 
    return 0;
}

/*
int int_array_min

int int_array_sort
int int_array_reverse

*/

int int_array_merge(IntArray *IA1, IntArray *IA2) {
    if (IA1 == NULL || IA2 == NULL) return -1;
    if (IA1->items == NULL || IA2->items == NULL) return -1;

    if (IA1->len  + IA2->len > IA1->cap){
        size_t new_cap = __int_array_get_new_cap(IA1->cap, IA1->len + IA2->len);
        int err = int_array_resize(IA1, new_cap);
        if (err) return 1;
    }

    memcpy(&IA1->items[IA1->len], IA2->items, IA2->len * sizeof(int));
    IA1->len += IA2->len;

    return 0; 
}

void int_array_print(FILE *file, IntArray *IA){
    if (IA == NULL || IA->items == NULL){
        fprintf(file, "None");
        return;
    }

    if (IA->len == 0) {
        fprintf(file, "[]");
        return;
    }
    
    fprintf(file, "[");
    for (size_t i = 0; i < IA->len - 1; i++){
        fprintf(file, "%d, ", IA->items[i]);
    }
    fprintf(file, "%d]", IA->items[IA->len - 1]);
}

#endif // INT_ARRAY_IMPLEMENTATION
#endif // DYNAMIC_ARRAY_H
