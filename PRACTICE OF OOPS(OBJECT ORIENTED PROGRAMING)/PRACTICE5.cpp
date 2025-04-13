#include<iostream>
//#include "PRACTICE5.cpp"
using namespace std;

class A{

 int a;
static int b;

public:

A(){
a=0;
}
void func(int  cary){
a+=cary;
b+=cary;
}

int reta(){
return a;
}

int retb(){
return b;
}

static void func1(int);

};

void A :: func1(int cary1){
b+=cary1;
}
int A :: b=0;

class B{
int c;
B(){
c=0;
}
void func2(int,int);



};






int main(){

int size=5;
A arr[size];

int input;
for(int i=0;i<size;i++){
cin>>input;
arr[i].func(input);
}

int input1;
cin>>input1;
A :: func1(input1);

for(int i=0;i<size;i++){
cout<<arr[i].reta()<<endl;
}

cout<<arr[0].retb();


}




