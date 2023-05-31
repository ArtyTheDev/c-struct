#include "queue.h"

struct Queue *create_queue(size_t capacity){
  if(capacity < 0){
    perror("Can't use a negtivie value as capacity.");
    return;
  }
  
  struct Queue *queue = malloc(
    capacity * sizeof(struct Queue));

  queue->capacity = capacity;
  queue->size = 0;
  queue->front = 0;
  queue->rear = 0;
  return queue;
}

void put_to_queue(struct Queue *queue, void *data){
  if(queue->size >= queue->capacity ){
    perror("The queue reached it capacity.");
    return;
  }
  
  queue->data[queue->rear] = data;
  queue->rear = (queue->rear + 1) % queue->capacity;
  queue->size++;
}

void *pop_from_queue(struct Queue *queue){
  if(queue->size == 0){
    perror("The queue reached it capacity.");
    return;
  }
  
  void *element = queue->data[queue->front];
  queue->front = (queue->front + 1) % queue->capacity;
  queue->size--;
  return element;
}