#include <stdio.h>
#include <stdlib.h>
#include "types.h"

struct Queue{
  void **data;
  size_t size;
  size_t capacity;
  size_t front;
  size_t rear;
};