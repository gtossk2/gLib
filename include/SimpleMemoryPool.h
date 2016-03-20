#ifndef _SIMPLE_MEMORY_POOL_
#define _SIMPLE_MEMORY_POOL_

/*
 * You can modify the data structure for your project
 * And also re-define your memory pool size (Default : 10)
 */

#include <stdlib.h>
#include <stdio.h>

#define MAX_MEMORY_POOL_NODES 10

// Forward Declare
typedef struct MemoryPool MEMORYPOOL;
MEMORYPOOL allocNode;

typedef struct node{
  int data;
  int nodeAllocated;
}NODE;

typedef struct MemoryPool{
  NODE *array[MAX_MEMORY_POOL_NODES];
  int nodeCounter;
}MEMORYPOOL;

/*
 * initial memory pool()
 */
void initialMemoryPool();

/*
 * get a node from memory pool()
 */
NODE *getTheFreeNodeFromPool();

/*
 *  Add the node to the memory pool
 */
void addTheNodeToMemoryPool(unsigned char uIndex);

/*
 *  DeallocateTheMemoryPool - Deallocate the memory pool
 */
void deallocateTheMemoryPool(void);

#endif
