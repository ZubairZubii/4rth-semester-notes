

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////         POINTER TO DERIVED CLASS                        ///////////////////////////////
///////////////////////////////////          VIRTUAL FUNCTON                              ///////////////////////////////   

#include<iostream>
using namespace std;


//POLYMORPHISM IN OOPS 
  /*POLYMORPHISM :
1=COMPILE TIME POLYMORPHISM
    -FUNCTION OVERLOADING
    -OPERATOR OVERLOADING

2=RUN TIME POLYMORPHISM 
    -VIRTUAL  FUNCTION */
    
    
/*//POINTER TO DERIVED CLASS
class base{
public:
int b;
void func(){
cout<<"my base var is "<<b<<endl;
}
};

class derived : public base{
public:
int d;
void func(){
cout<<"my base var is "<<b<<endl;
cout<<"my derived var is "<<d<<endl;
}
};


int main(){

base *bs;
base bobj;
derived dobj;
bs= &dobj;
bs->b=4;
bs->func();
derived *dr;
dr=&dobj;
dr->d=5;
dr->func();
}*/


/*//VIRTUAL FUNCTION
class base{
public:
int b;
virtual void func(){
cout<<"my base var is "<<b<<endl;
}
};

class derived : public base{
public:
int d;
void func(){
cout<<"my base var is "<<b<<endl;
cout<<"my derived var is "<<d<<endl;
}
};


int main(){

base *bs;
base bobj;
derived dobj;
bs= &dobj;
bs->b=4;
derived *dr;
dr=&dobj;
dr->d=5;
bs->func();

}*/


