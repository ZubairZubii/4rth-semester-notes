

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////           SINGLE INHERITANCE       ////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   

#include<iostream>
using namespace std;

/*//public
class base{
int data1;
public:
int data2;
void setData();
int getData1();
int getData2();

};
void base :: setData(){
 data1=5;
  data2=10;
 }

int  base :: getData1(){
return data1;
}

int  base :: getData2(){
return data2;
}

class derived : public base{
public:
int data3;
void process(void);	
void display(void);	

};

void derived :: process(void){
data3=data2*getData1();
} 

void derived :: display(void){
cout<<getData1()<<endl;
cout<<data2<<endl;
cout<<data3<<endl;
}


int main(){
derived dr;
dr.setData();
dr.process();
dr.display();
}*/


/*//private
class base{
int data1;
public:
int data2;
void setData();
int getData1();
int getData2();

};
void base :: setData(){
 data1=5;
  data2=10;
 }

int  base :: getData1(){
return data1;
}

int  base :: getData2(){
return data2;
}

class derived : private base{
public:
int data3;
void process(void);	
void display(void);	

};

void derived :: process(void){
setData();
data3=data2*getData1();
} 

void derived :: display(void){
cout<<getData1()<<endl;
cout<<data2<<endl;
cout<<data3<<endl;
}


int main(){
derived dr;
dr.process();
dr.display();
}
*/



