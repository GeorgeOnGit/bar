#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;

void display_array(string *array){
 while(*array != NULL){
 printf("\n%s \n", *array);
 array++;
 }
}
/*Given a null terminated string, returns word count.*/
int word_count(string input){
 int wc = 0;
 while(*input!= '\0'){
  if(*input== ' '){
   wc++;
  }
 input++;
 }
 return ++wc;
}

/*Given a string, returns an array of pointers pointing to each word.*/
int split(char* input, string* array){
 int wc = 0;
 array[0] = input;

 while(*input != '\0'){
  if(*input == ' '){
   memset(input, '\0', 1);
   wc++;
   array[wc] = input+1;
  }
   input++;
 
 }
 return ++wc;
}

void join(string* array, string output){
  while(*array != NULL){
  strcat(output, *array);  
  strcat(output, " ");
  array++;
  }
  output[strlen(output)] =  '\0';
}

void reverse(string * array){
 int start=0, end=0;
 string temp;

 for(end=0; array[end] != NULL; end++){ 
 }
 end--;
 while(start < end){
  temp = array[start];
  array[start] = array[end];
  array[end] = temp;
  start++;
  end--;
 }
}


int main(void){
char input[500] = "This is a big string.";
char output[500];
string array[100];

 for(int i=0;i<100;i++){  array[i] = NULL; }
 for(int i=0;i<500;i++){ output[i] = '\0';}                  
                       
split(input, array);
display_array(array);
reverse(array);
join(array, output);
printf("\n%s\n", output);
}
