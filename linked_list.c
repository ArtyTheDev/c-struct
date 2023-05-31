#include "linked_list.h"

// i need to learn more about linked list.
// :p i'm to stupid i swear.
struct Node *create_node(void* data, struct Node *next){
    struct Node *node = malloc(
        sizeof(struct Node));

    node->data = data;
    node->next = next;
    return node;
}