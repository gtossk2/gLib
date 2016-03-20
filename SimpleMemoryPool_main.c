#include <stdio.h>
#include <stdlib.h>

#include "include/SimpleMemoryPool.h"

int main(){
  unsigned char uIndex;
  int index;

  /* Step 1 */
  // Initialize the memory pool
  initialMemoryPool();

  /* Step 2 */
  // Get the node from the Memory pool
  for(uIndex = 0; uIndex < MAX_MEMORY_POOL_NODES; uIndex++){
    NODE *node = NULL;
    int data;

    node = getTheFreeNodeFromPool();

    if(node){
      printf("Enter the data to be added in the Linklist \n");
      scanf("%d", &data);

      node->data = data;
    }
  }

  // Display the data
  for(uIndex = 0; uIndex < MAX_MEMORY_POOL_NODES; uIndex++){
    printf("Index %d : %d \n", uIndex, allocNode.array[uIndex]->data);
  }

  /* Step 3 */
  // Add node to memory pool
  printf("Enter the node to be added node to free pool\n");
  scanf("%d", &index);

  addTheNodeToMemoryPool(index);

  // Display the data
  printf("Display data after adding Node to free pool\n");
  for(uIndex = 0; uIndex < MAX_MEMORY_POOL_NODES; uIndex++){
    printf("Index %d : %d \n", uIndex, allocNode.array[uIndex]->data);
  }

  /* Step 4 */
  // De allocate the memory pool
  deallocateTheMemoryPool();
  
  return 0;
}
