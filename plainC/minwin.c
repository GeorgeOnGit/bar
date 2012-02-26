#include <stdio.h>


/*
 *Given an array of 0's and 1's, and a number k, find the minimum window that contains k 0's. 
 * */
int main(){
int vector[]={1,1,0,0,0,0,0,1,0,0,0};
int k=3;
int counter, min_size=100;
int temp_p, w_index=0;
for(int i=0;i<sizeof(vector);i++){
   
  if(vector[i] == 0){
    if(i == 0){
     counter = 1;
     temp_p = 0;
    } else if(vector[i-1] == 1){
     counter = 1;
     temp_p = i;
    }else{
     counter++;
    }
  }else{
   if(i > 0){
    if (vector[i-1] == 0){
     if((counter < min_size) && (counter >= k)){
     w_index = temp_p;
     min_size = counter;
    }
   }
  }
 }
}
    if((counter < min_size) && (counter >= k)){
     w_index = temp_p;
     min_size = counter;
     }
 printf("window size %d, index %d \n",min_size, w_index);
 return min_size;
}
