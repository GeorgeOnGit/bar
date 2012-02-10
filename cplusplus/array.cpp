#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

class Array
{
private:
 int *i_array;
 int i_length;

 public:
  Array(int*, int);
  ~Array(); 

 void print_me_raw();

 void heap_sort();
 void build_heap();
 void max_heapify(int index, int end );
 int heap_left(int);
 int heap_right(int);
 int largest_of_the_three(int,int);
 void exchange(int first, int second);

};

 Array::Array(int *arg, int length){
  i_length = length;
  i_array = arg;
 };

 Array::~Array(){
 cout<<"Array releasing Memory.";
};
 
 void Array::print_me_raw(){
 for(int i=0;i < i_length;i++){
  cout<<i_array[i]<<" "; 
 }
 cout<< endl;
 };
//zero-based left= 2i+1 
 int Array::heap_left(int index){
  return 2*index+1;
 };
//zero-based right = 2i+2
 int Array::heap_right(int index){
  if(index == 0 ){
  return 2; 
  }else{
  return 2 * index + 2;
  }
 };
 //returns the index of the largest of the three nodes rooted at index.
 int Array::largest_of_the_three(int index, int end){
  int l, r, largest;
  l = heap_left(index);
  r = heap_right(index);

  if(l < i_length && (i_array[l] > i_array[index])){
   largest = l;
  }else{
   largest = index;
  }  
  if((r < i_length) && (i_array[r] > i_array[largest])){
   largest = r;
  }
 cout<<"Largest of the three at " << index <<" is "<< largest <<endl;
 return largest;
 };
 //swap values at first and second index.
 void Array::exchange(int first, int second){
  int h;
  h = i_array[first]; 
  i_array[first] = i_array[second];
  i_array[second] = h;
 };

 void Array::max_heapify(int index, int end){
  int l, r, largest;
  cout<<"Heapifying "<<index<<" "<<endl;
  l = heap_left(index);
  r = heap_right(index);
  largest = largest_of_the_three(index, end);
  if(largest != index){
  exchange(index, largest);
  max_heapify(largest, end);
  }
 };
 //zero-based array leaves starts at index = floor(length/2) 
 void Array::build_heap(){
  for(int top=floor(i_length/2)-1;top >= 0; top--){
  max_heapify(top, i_length-1);
  }
 }
 //
 void Array::heap_sort(){
  for(int end=i_length-1;end >= 1; end--){
  exchange(0, end);
  max_heapify(0, end-1);
  }
 }


int main(int argc, char* argv[]){
 int foo_array[] = {2,4,3,6,3};
 int root;

 root = atoi(argv[1]);

 cout<<"Input array length:"<<(sizeof(foo_array)/sizeof(foo_array[0]))<<endl;
 Array a(foo_array, (sizeof(foo_array)/sizeof(int)));
 cout<<"Before heapify "<< endl;
 a.print_me_raw();
 
 a.print_me_raw();
 a.build_heap();
 cout<<"After heap building"<< endl;
 a.print_me_raw();
 a.heap_sort();
 cout<<"After sorting"<< endl;
 a.print_me_raw();
}


