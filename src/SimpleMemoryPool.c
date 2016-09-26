#include "SimpleMemoryPool.h"

/*
 * initial memory pool()
 */
void initialMemoryPool(){
  unsigned char uIndex;

  /* Initialize the memory for the Nodes */
  for(uIndex = 0; uIndex < MAX_MEMORY_POOL_NODES; uIndex++){
    allocNode.array[uIndex] = (NODE *) malloc(sizeof(NODE));
    allocNode.array[uIndex]->nodeAllocated = 0;

    allocNode.nodeCounter++;
  }
}

/*
 * Get a node from memory pool()
 */
NODE *getTheFreeNodeFromPool(){
  int uIndex;

  /* Get the memory from the pool of nodes */
  for(uIndex = 0; uIndex < MAX_MEMORY_POOL_NODES; uIndex++){
    if(allocNode.array[uIndex]->nodeAllocated == 0){
      allocNode.array[uIndex]->nodeAllocated = 1;
      allocNode.nodeCounter--;
      break;
    }
  }

  if(uIndex == MAX_MEMORY_POOL_NODES){
    printf("No free Nodes are avaiable\n");
    return NULL;
  }

  return allocNode.array[uIndex];
}

/*
 *  Add the node to the memory pool
 */
void addTheNodeToMemoryPool(unsigned char uIndex){
  /* Add the node to pool */
  if(allocNode.array[uIndex]->nodeAllocated == 1){
    allocNode.array[uIndex]->data = 0;
    allocNode.array[uIndex]->nodeAllocated = 0;
    allocNode.nodeCounter++;
  } 
  else{
    printf("No Nodes are added \n");
    return;
  }
}

/*
 *  DeallocateTheMemoryPool - Deallocate the memory pool
 */
void deallocateTheMemoryPool(void){
  unsigned char uIndex;

  for(uIndex = 0; uIndex < MAX_MEMORY_POOL_NODES; uIndex++){
    free(allocNode.array[uIndex]);
  }
}
