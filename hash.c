#include "hash.h"

unsigned int hash(const char* key) {
  unsigned int hash = 0;
  int len = strlen(key);
  for (int i = 0; i < len; i++) {
    hash = (hash << 5) + key[i];
    hash = hash ^ (hash >> 27);
  }
  return hash;
}