#include <stdio.h>
#include <stdlib.h>
#include "types.h"

struct FixedArray{
    void **data;
    enum TypeName fixed_type;
    size_t size;
    size_t capacity;
};

struct FixedArray *create_f_array(size_t capacity, enum TypeName fixed_type);
void append_to_f_array(struct FixedArray *f_array, void *element);
void *remove_f_array(struct FixedArray *f_array, int index);
void *pop_f_array(struct FixedArray *f_array);
int count_f_array(struct FixedArray *f_array, void *element);
struct FixedArray *slice_f_array(struct FixedArray *f_array, int start, int end);
void reverse_f_array(struct FixedArray *f_array);
void sort_f_array(struct FixedArray *f_array);
void print_f_array(struct FixedArray *f_array);