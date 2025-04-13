

////////////////////////////////     	       TONNY GEDIS QUESTION 14         /////////////////////////////////////////////////
#include <iostream>
using namespace std;

class FBpoint{
signed int T;
bool flag;
public:
FBpoint(signed int t){
T=t;
}

int  EthylFreezing(){

if(T <=-173){
cout<<"this is the ethyl freezing point"<<endl;
return flag=true;}
else
return flag=false;
}

int  EthylBoiling(){
if(T >=172){
cout<<"this is the ethyl boiing point"<<endl;
return flag=true;}
else
return flag=false;
}

int WaterFreezing(){
if(T <=32){
cout<<"this is the water freezing point"<<endl;
return flag=true;}
else
return flag=false;
}

int WaterBoiling(){
if(T>=212){
cout<<"this is the water boiling point"<<endl;
return flag=true;}
else
return flag=false;
}

int OxygenFreezing(){
if(T <=-362){
cout<<"this is the oxygen freezing point"<<endl;
return flag=true;}
else
return flag=false;
}



int OxygenBoiling(){
if(T>=-306){
cout<<"this is the oxygen boiling point"<<endl;
return flag=true;}
else
return flag=false;
}

};




int main(){
FBpoint fb(-20);
int x;
cout<<"If output is 1 then show temperature is in range and if 0 then show not in range"<<endl;
cout<<endl;
x=fb.EthylFreezing();
cout<<x<<endl;
x=fb.EthylBoiling();
cout<<x<<endl;
cout<<endl;
x=fb.WaterFreezing();
cout<<x<<endl;
x=fb.WaterBoiling();
cout<<x<<endl;
cout<<endl;
x=fb.OxygenFreezing();
cout<<x<<endl;
x=fb.OxygenBoiling();
cout<<x<<endl;
}


