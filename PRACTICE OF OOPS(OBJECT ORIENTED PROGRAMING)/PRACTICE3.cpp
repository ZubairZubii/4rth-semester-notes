

////////////////////////////////     	       TONNY GEDIS QUESTION 11         /////////////////////////////////////////////////
#include <iostream>
using namespace std;

class Array{

int *arr;
int size;
int larg;
int small;
int s;
public:
Array(int s){
size=s;
arr = new int [size];
}

void storeArray(){
for(int i=0;i<size;i++){
arr[i]=i;
}
}

void Largest(){

larg=arr[0];
for(int i=0;i<size;i++){
if(arr[i]>larg)
larg=arr[i];
}
};

void smallest(){

small=arr[0];
for(int i=0;i<size;i++){
if(arr[i]<small)
small=arr[i];
}
}

void Average(){
//int avg;

for(int i=0;i<size;i++){
s+=arr[i];
s=s/size;
}
}

void ArrayDisplay(){
for(int i=0;i<size;i++){
cout<<"my original array is "<<arr[i]<<endl;
}
}


void Display(){
Largest();
smallest();
Average();
cout<<"my largest no in array "<<larg<<endl;
cout<<"my smallest no in array "<<small<<endl;  
cout<<"my array average "<<s<<endl;
}

};
int main(){

Array a(5);
a.storeArray();
a.ArrayDisplay();
a.Display();

}































