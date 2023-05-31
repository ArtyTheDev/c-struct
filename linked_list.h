#include <stdio.h>
#include <stdlib.h>
#include "types.h"

struct LNode{
  void* data;
  struct Node *next;
};


struct LNode *create_l_node(void* data, struct LNode *next);