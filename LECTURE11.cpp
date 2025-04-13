

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////            COPY CONSTRUCTOR       /////////////////////////////////////////////////////
/////////////////////////////////////////                           ////////////////////////////////////////////////////   

#include<iostream>
using namespace std;

class number{

int a;
//int b;
public:

number(){
a=0;
}
number (int num){
a=num;
}
// copy comstructor ::
number (number & b){
a=b.a;
}


void rezult(){
cout<<"rezult is"<<a<<endl;
}
};

int main(){

number n1(5),n2,n3;
n1.rezult();
n2.rezult();
n3.rezult();


//    copy object :
// us eit individually
number n4(n1); 
n4.rezult();
number n5=n2;
n5.rezult();

/* number n1,n2,n3=number(5);
//number n2,n3;
n1.rezult();
n2.rezult();
n3.rezult();*/
}


