

/////////////////////////////////////    CLASSES (PUBLIC AND PRIVATE MODIFIERS)    ///////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

class Employee{
private:
int a,b,c;
public:
int d,e;

void setdata(int a1,int b1,int c1);// DECLARATION
void getdata(){
cout<<a<<b<<c<<d<<e;
}

};
// if you use function out from the class and if you connect this function wuth your class then yow will use this syntax
//   IMPORTANT
void Employee::setdata(int a1,int b1,int c1){
a=a1;
b=b1;
c=c1;
}

int main(){
Employee zubair;
zubair.setdata(1,2,3);
zubair.d=4,
zubair.e=5,
//zubair.a=1; error
//zubair.b=2; error
//zubair.c=3; error 
// because we declare a b c previously private
zubair.getdata();
}




