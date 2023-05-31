#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "types.h"
#include "hash.h"


struct HashMapNode{
  char* key;
  void *data;
  struct HashMapNode *next;
};

struct HashMap{
  struct HashMapNode **bucket;
  char **keys;
  size_t capacity;
  size_t size;
};

struct HashMapNode *create_hash_map_node(char *key, void *data, struct HashMapNode *next);
struct HashMap *create_hash_map(size_t capacity);
void insert_hash_map(struct HashMap *hash_map, char* key, void *data);
void *get_hash_map(struct HashMap *hash_map, char* key);
bool check_key_hash_map(struct HashMap *hash_map, char* key);
void remove_key_hash_map(struct HashMap *hash_map, char* key);
void free_hash_map(struct HashMap *hash_map);