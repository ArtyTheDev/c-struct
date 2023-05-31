#include "hash_map.c"
#include "array.c"
#include "linked_list.c"
#include "queue.c"

int main(){
    struct Queue *queue = create_queue(3);
    put_to_queue(queue, "Hello, world");
    printf("%s", queue);

    free_queue(queue);
    return 0;
} 