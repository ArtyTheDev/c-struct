# c-struct
Idk I wanted to see how C works so I search and I learn't plenty of things :)
- Note*: I'm not a C developer or very good with data structure
- Node*: I just wanted to learn how memory management work if this is impl is wrong let me know.
### Arrays
```c
#include "array.c"

int main(){
    struct FixedArray *array = create_f_array(3, PTR_T_STR);
    append_to_f_array(array, "Hello, World");
    append_to_f_array(array, "1234");
    append_to_f_array(array, "4568");
    append_to_f_array(array, "4568");
    
    print_f_array(array);
    free_f_array(array);
    return 0
} 
```

### Hash Map
```c
#include "hash_map.c"

int main(){
    struct HashMap *hash_map = create_hash_map(3);
    insert_hash_map(hash_map, "1", "2");
    printf("%s\n", get_hash_map(hash_map, "1"));
    remove_key_hash_map(hash_map, "1");
    free_hash_map(hash_map);
    return 0;
} 
```

### Linked List
```c
#include "linked_list.c"

int main(){
    struct LNode *l_node = create_l_node(
        "hello, world", create_l_node(
            "heaio", NULL
        )
    );

    free_l_list(l_node);
    return 0;
} 
```

### Queue
```c
#include "queue.c"

int main(){
    struct Queue *queue = create_queue(3);
    put_to_queue(queue, "Hello, world");
    printf("%s", queue);

    free_queue(queue);
    return 0;
} 
```
