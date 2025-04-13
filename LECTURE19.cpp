

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////       INITIALIZATION SEGTION IN CONSTRUCTOR      //////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   

#include<iostream>
using namespace std;


class test{
int a,b;
public:
//test (int i,int j) : a(i+j) , b(i+j){
//test (int i,int j) : a(a+j) , b(a+j){ //garbage value in a
test (int i,int j) : a(b+j) , b(a+j){ // garbage in both a and b because a is declare fiest in line12 so due to garbage in a, b also show 
//                                        gabage bacause a is use in b 
//test (int i,int j) : a(j) , b(a+j){
cout<<"this is constructor"<<endl;
cout<<"value of a "<<a<<endl;
cout<<"value of b "<<b<<endl;
}
};

int main(){

test t(1,2);
}


