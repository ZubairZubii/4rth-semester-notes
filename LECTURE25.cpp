
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////              TEMPLATES IN OOPS                        ///////////////////////////////
///////////////////////////////////                                                    ///////////////////////////////   

#include<iostream>
#include<cstring>
using namespace std;
/*//instant and local veriable
template <class T> 
class vector{
public:
T *arr;
int size;
   vector( int m){
   size=m;
arr = new T [size] ;
}

T product(vector &v){
T s=0;
for(int i=0;i<size;i++){
s+=this->arr[i] * v.arr[i];

}
return s;
}
};






int main(){
vector <float>v1(3);
v1.arr[0]=1.0;
v1.arr[1]=4.0;
v1.arr[2]=0.1;

vector <float>v2(3);
v2.arr[0]=0.1;
v2.arr[1]=4.1;
v2.arr[2]=1.1;
float sum=v1.product(v2);
cout<<sum;
}*/



/*//MULTIPLE TEMPLATE
template <class T1,class T2>
class A{
public:
T1 data1;
T2 data2;
A (T1 a,T2 b ){
data1=a;
data2=b;
}

void display(){
cout<<data1<<endl;
cout<<data2<<endl;
}

};

int main(){

A <int,char>obj(1,'a');
obj.display();
}*/


//TEMPLATE WUTH DEFAULT ARGUEMENT
/*template <class T1=int,class T2=char>
class A{
public:
T1 data1;
T2 data2;
A (T1 a,T2 b ){
data1=a;
data2=b;
}

void display(){
cout<<data1<<endl;
cout<<data2<<endl;
}

};

int main(){

A <>obj1(1,'a');
obj1.display();
A <float,char>obj2(1.0,'d');
obj2.display();
}*/





/*//TEMPLATE FUNCTION
template <class t1,class t2>
t1 avg(t1 a,t2 b){
t1 average=(a+b)/2;
return average;
}

int main(){

float g;
g=avg(1.0,6);
cout<<g;
}*/


/*//TEMPLATE MEMBER FUNCTION
template <class T>
class A{
public:
T data;
A (T a ){
data=a;
}
void display();
};

template <class T>
void A <T> :: display(){
cout<<data<<endl;
}


int main(){

A <int>obj(1);
obj.display();
}*/


/*//TEMPLATE OVERLOADING
void fun(int a){
cout<<"i am zubair"<<endl;
}

template <class t>
void fun(t a){
cout<<"i am temalized zubair"<<endl;
}
int main(){
// the functon is run ehich is exact match
fun(2);
}*/





















