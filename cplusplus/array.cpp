#include <iostream>
using namespace std;

class Array
{
private:
 int *i_array;
 int i_length;

 public:
  Array(int*, int);
  ~Array(); 

 void print_me();

};

 Array::Array(int *arg, int length){
  i_length = length;
  i_array = arg;
 };

 Array::~Array(){
 cout<<"Array releasing Memory.";
};
 
 void Array::print_me(){
 for(int i=0;i < i_length;i++){
  cout<<i_array[i]<<" "; 
 }
 cout<< endl;
 cout<<"length:"<<i_length<<endl;
 };

int main(){
 int foo_array[] = {2,4,3,2,6};
 cout<<"Input array length:"<<(sizeof(foo_array)/sizeof(foo_array[0]))<<endl;
// Array a(foo_array, (sizeof(foo_array)/sizeof(int)));
 Array a(foo_array, 5);
 a.print_me();
}


