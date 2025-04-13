

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////        CONSTRUCTOR IN DERIVED CLASS     ///////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   

#include<iostream>
using namespace std;

class base1{
int data1;
public:
 base1 (int d1){
  data1=d1;
  cout<<"contructor pf base1 is called"<<endl;
 }

 void printData1(){
  cout<<"data1 is"<<data1<<endl;
 }

};

class base2{
int data2;
public:
 base2 (int d2){
  data2=d2;
  cout<<"contructor pf base2 is called"<<endl;
  }

 void printData2(){
  cout<<"data2 is"<<data2<<endl;
 }

};

class derived : public base1, public base2{
int derived1,derived2;
public:
 derived (int a,int b,int c,int d) : base1(a) , base2(b) {
  derived1=c;
  derived2=d;
  cout<<"contructor of derived class is called"<<endl;
 }


 void printDerived(){
  cout<<"Derived1 is"<<derived1<<endl;
  cout<<"Derived2 is"<<derived2<<endl;
 }

};

int main(){
derived dr(1,2,3,4);
dr.printData1();
dr.printData2();
dr.printDerived();

}

