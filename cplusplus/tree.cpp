
#include <iostream>
#include <stdlib.h>
using namespace std;

class Node{
 class Node *left;
 class Node *right;
 int data;

 public:
 Node(int);
 ~Node();

 bool compare_binary_tree(Node*, Node*);
 bool operator == (Node);
 void make_children(int, int*, int);
 int  size_of_tree();

};
//returns the size of the subtree starting at currtn node.
 int Node::size_of_tree(){
  int left_tree_size, right_tree_size;
   left_tree_size = left  == NULL ? 0 :  left->size_of_tree();
  right_tree_size = right == NULL ? 0 : right->size_of_tree();
  return 1 + left_tree_size + right_tree_size;
 };

 Node::Node(int param){
 data = param;
 left = NULL;
 right =NULL;
 };
//comparing two trees.
bool Node::compare_binary_tree(Node* first, Node* second){
  if ((first == NULL) && (second == NULL)) // both roots are NULL
   return true;
  else if ((first == NULL) || (second == NULL)){ //only one root is NULL
   return false;
  }else if(first->data != second->data){ // data not equal
    return false;
  }else{ //data equal.
    return compare_binary_tree(first->left, second->left) && compare_binary_tree(first->right, second->right);
   }
 }; 
//
bool Node::operator== (Node second){
 return (data == second.data) && (left == second.left) && (right == second.right)
}
//
//create a heap tree.
void Node::make_children(int current_index, int* array, int length){
  if (2*current_index + 1 < length){ 
   left = new Node(array[2*current_index + 1]);
   left->make_children(2*current_index + 1, array, length);
  }else{
   return;
  }
  if (2*current_index + 2 < length){ 
   right = new Node(array[2*current_index + 2]);
   right->make_children(2*current_index + 2, array, length);
  }else{
   return;
  }
};

int main(){
 int array[]={1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0};
 int array2[]={1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,1};
 Node* root1 = new Node(array[0]), *root2 = new Node(array2[0]);
 root1->make_children(0, array, sizeof(array)/sizeof(int));
 root2->make_children(0, array2, sizeof(array)/sizeof(int));
 cout << "size of root1 tree "<< root1->size_of_tree()<<endl;
 cout << " root1 == root 2? " << root1->compare_binary_tree(root1, root2);
}




