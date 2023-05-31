#include "array.h"

struct FixedArray *create_f_array(size_t capacity, enum TypeName fixed_type){
  if(capacity < 0){
    perror("Can't use a negtivie value as capacity.");
    return;
  }

  // Allocate the array in the memory.
  struct FixedArray *f_array = malloc(
    sizeof(struct FixedArray));

  // We are allocating the size of the array
  // in the memory.
  f_array->capacity = capacity;
  f_array->data = malloc(sizeof(void *) * f_array->capacity);
  f_array->fixed_type = fixed_type;
  f_array->size = 0;
  return f_array;
}

void append_to_f_array(struct FixedArray *f_array, void *element){
  if(typename(element) != typename(f_array->fixed_type)){
    perror("Can't accept the type of that value.");
  }
    
  if(f_array->size == f_array->capacity){
    f_array->capacity *= 2;
    f_array->data = realloc(
      f_array->data, f_array->capacity * sizeof(void *)
    );
  }

  f_array->data[f_array->size++] = element;
}

void *remove_f_array(struct FixedArray *f_array, int index){
  if (index >= f_array->size) {
    perror("Array is empty.");
  }

  // Shift all the elements after the index to the left.
  void* element = f_array->data[index];
  for (size_t i = index + 1; i < f_array->size; i++) {
    f_array->data[i - 1] = f_array->data[i];
    free(f_array->data[i - 1]);
  }

  // Decrement the size of the array.
  f_array->size--;
  return element;
}

void *pop_f_array(struct FixedArray *f_array){
  if (f_array->size == 0) {
    perror("Array is empty.");
  }

  void *element = f_array->data[f_array->size - 1];
  free(f_array->data[f_array->size - 1]);
  f_array->size--;
  return element;
}

int count_f_array(struct FixedArray *f_array, void *element){
  int count = 0;
  for (int i = 0; i < f_array->size; i++) {
    if(f_array->data[i] == element){
      count += 1;
    }
  }

  return count;
}

struct FixedArray *slice_f_array(struct FixedArray *f_array, int start, int end) {
  if (start < 0 || end < 0 || end < start) {
    if(start >= f_array->size || start > end){
      perror("Check again man.");
      return NULL;
    }
  }

  struct FixedArray *new_f_array = create_f_array(
    end - start, f_array->fixed_type
  );

  for (int i = start; i <= end; i++) {
    new_f_array->data[i - start] = f_array->data[i];
  }

  return new_f_array;
}

void reverse_f_array(struct FixedArray *f_array){
  if (f_array->size < 1) {
    perror("Can't have a size less than 1");
    return;
  }

  int start = 0;
  int end = f_array->size-1;

  while (end > start){
    void *temp = f_array->data[start];
    f_array->data[start] = f_array->data[end];
    f_array->data[end] = temp;

    start++; end--;
  }
}

void sort_f_array(struct FixedArray *f_array){
  if (f_array->size < 1) {
    perror("Can't have a size less than 1");
    return;
  }

  for(int i = 0; i < f_array->size - 1; i++){
    for(int j=1; i < f_array->size - 1; i++){
      if (f_array->data[j] > f_array->data[j + 1]) {
        void *temp = f_array->data[j];
        f_array->data[j] = f_array->data[j + 1];
        f_array->data[j + 1] = temp;
      }
    }
  }
}

void print_f_array(struct FixedArray *f_array){
  printf("[");
  for (int i = 0; i < f_array->size; i++) {
    if (f_array->fixed_type == PTR_T_STR) {
        printf("\"%s\"", (char*)f_array->data[i]);
    }
    else if (f_array->fixed_type == PTR_T_INT) {
        printf("%d", *(int*)f_array->data[i]);
    }

    if (i != f_array->size - 1) {
        printf(",");
    }
  }
  printf("]\n");
}