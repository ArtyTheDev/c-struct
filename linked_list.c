#include "linked_list.h"

// i need to learn more about linked list.
// :p i'm to stupid i swear.
struct LNode *create_l_node(void* data, struct LNode *next){
  struct LNode *l_node = malloc(
      sizeof(struct LNode));

  l_node->data = data;
  l_node->next = next;
  return l_node;
}

void free_l_list(struct LNode *node){
  struct LNode *current = node;
  while (current != NULL){
    struct LNode *next = current->next;
    free(node);
    current = next;
  }
}