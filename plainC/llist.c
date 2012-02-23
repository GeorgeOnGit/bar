#include <stdio.h>
#include <stdlib.h>

struct NODE {
 int number;
 struct NODE *next;
 struct NODE *previous;
};


void append_node(struct NODE *llist, int num); 
void delete_node(struct NODE *llist, int num); 
void display_list(struct NODE *llist);


int main(void) {
 struct NODE *llist = (struct NODE*)malloc(sizeof(struct NODE)), *sentinal = (struct NODE*)malloc(sizeof(struct NODE));
 int number;
 
 for(number = 1; number < 150; number++){
  append_node(llist, number);
 }
 display_list(llist);
 sentinal->next = llist;
 delete_node(sentinal, 50);
 display_list(llist);
 return number;
}
/*append a node.*/
void append_node(struct NODE *llist, int num) {
 while(llist->next != NULL)
  llist = llist->next;

 llist->next = (struct NODE *)malloc(sizeof(struct NODE));
 llist->next->number = num;
 llist->next->next = NULL; 
}
/*delete all the nodes that has num.*/
void delete_node(struct NODE *root, int num) {
 struct NODE *temp;
 if(root->next == NULL){
  return;
 }else if(root->next->number == num){
  temp = root->next;
  root->next = root->next->next;
  free(temp);
 }else{
  root = root->next;
 }
  delete_node(root, num);
 return;
}

void display_list(struct NODE *llist){
 printf("\n-----------------------------------------");
 while(llist != NULL){
  printf("[node%d]", llist->number);  
  llist = llist->next;
 }
 return;
}
