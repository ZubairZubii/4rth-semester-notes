

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////      POINTER ARRAY  IN OOPS             //////////////////////////////////////////
///////////////////////////////////       tHIS POUNTER          ///////////////////////////////////////////////////////////   

#include<iostream>
using namespace std;

/*class store{
int id;
int price;
public:
void getData(int d,float p){
id=d;
price=p;
}
void displaydata(){
cout<<"your item id is"<<id<<endl;
cout<<"your item price is"<<price<<endl;
} 
};


int main(){
int size=3;
store *s=new store [size];
store *sitem=s;
int d;
float p;
for(int i=0;i<size;i++){
cout<<"enter the id and price of item"<<endl;
cin>>d>>p;
cout<<"id and item price is"<<i+1<<endl;
(*s).getData(d,p);
s++;
}

for(int i=0;i<size;i++){
(*sitem).displaydata();
sitem++;
}

}*/



/*class A{

int a;
public:
//void setData(int a){
A& setData(int a){
this->a=a;
return *this;
}

void getData(){

cout<<"valus of a"<<a<<endl;
}

};

int main(){
A a;
a.setData(2).getData();
a.getData();
}*/

















