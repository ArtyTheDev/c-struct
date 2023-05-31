#include <stdio.h>
#include <stdlib.h>
#include "types.h"

struct Node{
  void* data;
  struct Node *next;
};


struct Node *create_node(void* data, struct Node *next);