#include "hash_map.h"
#include "hash.c"

struct HashMapNode *create_hash_map_node(char *key, void *data, struct HashMapNode *next){
  struct HashMapNode *hash_map_node = malloc(
    sizeof(struct HashMapNode)
  );

  hash_map_node->key = key;
  hash_map_node->data = data;
  hash_map_node->next = next;
  return hash_map_node;
}

struct HashMap *create_hash_map(size_t capacity){
  struct HashMap *hash_map = malloc(
    sizeof(struct HashMap)
  );

  hash_map->bucket = malloc(sizeof(struct HashMapNode *));
  hash_map->keys = malloc(sizeof(char *) * capacity);
  hash_map->capacity = capacity;
  hash_map->size = 0;

  return hash_map;
}

void insert_hash_map(struct HashMap *hash_map, char* key, void *data){
  unsigned int hash_key = hash(key) % hash_map->capacity;
  
  struct HashMapNode *hash_map_node = create_hash_map_node(
    key, (void *)data, hash_map->bucket[hash_key]
  );
  hash_map->bucket[hash_key] = hash_map_node;
  hash_map->keys[hash_map->size++] = key;
}

void *get_hash_map(struct HashMap *hash_map, char* key){
  unsigned int hash_key = hash(key) % hash_map->capacity;

  struct HashMapNode *hash_map_node = hash_map->bucket[hash_key];
  while(hash_map_node != NULL){
    if(strcmp(hash_map_node->key, key) == 0){
      return hash_map_node->data;
    }
    else hash_map_node = hash_map_node->next;
  }

  return NULL;
}

bool check_key_hash_map(struct HashMap *hash_map, char* key){
  unsigned int hash_key = hash(key) % hash_map->capacity;

  struct HashMapNode *hash_map_node = hash_map->bucket[hash_key];
  while(hash_map_node != NULL){
    if(strcmp(hash_map_node->key, key) == 0){
      return true;
    }
    else hash_map_node = hash_map_node->next;
  }

  return false;
}

void remove_key_hash_map(struct HashMap *hash_map, char* key){
  unsigned int hash_key = hash(key) % hash_map->capacity;

  struct HashMapNode *hash_map_node = hash_map->bucket[hash_key];
  struct HashMapNode *prev = NULL;
  while(hash_map_node != NULL){
    if(strcmp(hash_map_node->key, key) == 0){
      if(prev == NULL){
        hash_map->bucket[hash_key] = hash_map_node->next;
      } else {
        prev->next = hash_map_node->next;
      }

      free(hash_map_node->key);
      free(hash_map_node->data);
      free(hash_map_node);
      hash_map->size--;
      break;
    }
    prev = hash_map_node;
    hash_map_node = hash_map_node->next;
  }
}
void free_hash_map(struct HashMap *hash_map){
  for (size_t i = 0; i < hash_map->capacity; i++) {
    unsigned int hash_key = hash(
      hash_map->keys[i]) % hash_map->capacity;
    
    free(hash_map->bucket[i]);
    free(hash_map->bucket[hash_key]);
  }

  free(hash_map->keys);
  free(hash_map->bucket);
  free(hash_map);
}