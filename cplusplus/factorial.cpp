
#include <iostream>
#include <stdio>
using namespace std;

class ANumber
{
 int mynumber;

 public:
 ANumber(int);
 ~ANumber(); 

 int factorial(int); 
 int factorial();
 };

 ANumber::ANumber(int n) {
     mynumber= n;
 }

 ANumber::~ANumber() {
     cout<< mynumber <<" released memory."<<endl;
 }

 int ANumber::factorial(int n) {
   if(n==1)
    return 1;
   else {
    return n * factorial(n-1);
   }
 };
 int ANumber::factorial(){
  return factorial(mynumber);
 };

int main() {
 for(int i=1;i<10;i++){
 ANumber n(i);
 cout << "The Factorial of "<< i <<" is:" << n.factorial() << endl;
 }

}
