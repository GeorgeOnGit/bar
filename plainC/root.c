#include <stdio.h>
/*
 Calculate the square root of a number.
 * */
int main(void){
 float x,precision, root, beginning=0, end;
 double error;
 int iteration = 0;
 printf("Please enter a number and precision(e.g. 2, 100)\n:");
 scanf("%f, %f", &x, &precision);
 precision = 1/precision;
 end = x; 
 do{
   root = (beginning + end)/2;
   (root*root > x) ?  end = root :  beginning = root; 
   
   error = root * root - x ; 
   error = error > 0 ? error : -error;
   iteration++;
 }while(error >  precision);

 printf("The square root of %f is %f ", x, root);
 printf("error %f iteration %d\n",error, iteration);
 return root;
}
