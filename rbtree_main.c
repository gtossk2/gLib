#include <stdlib.h>
#include <stdio.h>

#include "include/rbtree.h"

struct mynode{
  struct rb_node node;
  char *string;
};

struct rb_root myTree = RB_ROOT;

struct mynode* search_rbtree(struct rb_root *root, char *string);
int insert_rbtree(struct rb_root *root, struct mynode *data);
void free_rbtree(struct mynode *node);

void print_rbtree(const struct rb_root *root);
void _print(const struct rb_node *n);
void _print_node(const struct rb_node *n);

#define NUM_NODES 12
//int insertArray[NUM_NODES] = {2, 1, 4, 5, 9, 3, 6, 7};

int main(){
  
  struct mynode *mn[NUM_NODES];
  struct rb_node *node;
  struct mynode *data;
  int i = 0;

  /* insert */
  printf("insert node from 1 to 32 ... \n");
  for(i = 0; i < NUM_NODES; i++){
    mn[i] = (struct mynode *) malloc(sizeof(struct mynode));
    mn[i]->string = (char *) malloc(sizeof(char) * 4);
    sprintf(mn[i]->string, "%d", i);
    //sprintf(mn[i]->string, "%d", insertArray[i]);
    insert_rbtree(&myTree, mn[i]);
  }

  /* search */
  printf("search all nodes ... \n");
  for(node = rb_first(&myTree); node; node = rb_next(node)){
    printf("key = %s\n", rb_entry(node, struct mynode, node)->string);
  }

  /* delete */
  printf("delete node 10 : \n");
  data = search_rbtree(&myTree, "10");
  if(data){
    rb_erase(&data->node, &myTree);
    free_rbtree(data);
  }

  /* search */
  printf("search again ... \n");
  for(node = rb_first(&myTree); node; node = rb_next(node)){
    printf("key = %s\n", rb_entry(node, struct mynode, node)->string);
  }
  
  /* free the whole rbtree */
  printf("free ... \n");
  for(i = 0; i < NUM_NODES; i++){
    free(mn[i]->string);
    free(mn[i]);
  }

  printf("rbtree ... done!\n");

  return 0;
}

void print_rbtree(const struct rb_root *root){
  struct rb_node *node = root->rb_node;
  struct mynode *data = container_of(node, struct mynode, node);

  printf("Root is %s \n", data->string);
  _print(node);
}

void _print(const struct rb_node *n){
  struct mynode *data = container_of(n, struct mynode, node);

  if(!n){
    return;
  }

  if(n->__rb_parent_color == RB_RED) {
    printf("%s(Red)", data->string);
    _print_node(n);
  } else if(n->__rb_parent_color == RB_BLACK) {
    printf("%s(Black)", data->string);
    _print_node(n);
  } else {
    printf("%s", data->string);
    _print_node(n);
  }

  printf("\n");
  _print(n->rb_left);
  _print(n->rb_right);
}

void _print_node(const struct rb_node *n){
  struct mynode *data;

  if(n->rb_left){
    data = container_of(n->rb_left, struct mynode, node);
    printf(" Left = %s ", data->string);
  } else {
    printf(" Left = nil ");
  }
 
  if(n->rb_right){
    data = container_of(n->rb_right, struct mynode, node);
    printf(" Right = %s ", data->string);
  } else {
    printf(" Right = nil ");
  }
}


struct mynode* search_rbtree(struct rb_root *root, char *string){
  struct rb_node *node = root->rb_node;

  while(node){
    struct mynode *data = container_of(node, struct mynode, node);
    int result;

    result = strcmp(string, data->string);
    
    if(result < 0) {
      node = node->rb_left;
    } else if(result > 0) {
      node = node->rb_right;
    } else {
      return data;
    }
  }

  return NULL;
}

int insert_rbtree(struct rb_root *root, struct mynode *data){
  struct rb_node **new = &(root->rb_node),
                 *parent = NULL;

  /* Figure out where to put new node */
  while(*new){
    struct mynode *this = container_of(*new, struct mynode, node);
    int result = strcmp (data->string, this->string);

    parent = *new;
    if(result < 0) {
      new = &((*new)->rb_left);
    } else if (result > 0) {
      new = &((*new)->rb_right);
    } else {
      return 0;
    }
  }

  /* Add new node and rebalance tree */
  rb_link_node(&data->node, parent, new);
  rb_insert_color(&data->node, root);

  return 1;
}

void free_rbtree(struct mynode *node){
  if(node != NULL) {
    if(node->string != NULL) {
      free(node->string);
      node->string = NULL;
    }

    free(node);
    node = NULL;
  }
}
