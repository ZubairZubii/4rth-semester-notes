

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////  DYNAMIN INTIALIAZATION OF OBJECT USING COMSTRUCTOR     ////////////////////////////////
/////////////////////////////////////////                              //////////////////////////////////////////////////

#include<iostream>
using namespace std;

class bankAccount{
int principle;
int years;
float intrestRate;
float returnAmount;
public:
//this is impotant bankAccount(){}
bankAccount(){}
bankAccount(int p,int y,float r);
bankAccount(int p,int y,int R);
void show();

};

bankAccount :: bankAccount(int p,int y,float r){

principle=p;
years=y;
intrestRate=r;
returnAmount=principle;
for(int i=0;i<years;i++){
returnAmount=returnAmount *(1+intrestRate);	
}
}


bankAccount :: bankAccount(int p,int y,int R){

principle=p;
years=y;
intrestRate=float(R)/100;
returnAmount=principle;
for(int i=0;i<years;i++){
returnAmount*=(1+intrestRate);	
}
}

void bankAccount :: show(){
cout<<"your principle is"<<principle<<"after the year"<<years<<"is"<<returnAmount<<endl;
}


int main(){
cout<<"enter the value:"<<endl;
int p;
int y;
float r;
int R;
cin>>p>>y>>r;
//bankAccount b1=bankAccount(p, y, r); 
bankAccount b1,b2;
//bankAccount b1=bankAccount(p, y, r);
b1=bankAccount(p, y, r);
b1.show();

cin>>p>>y>>R;;
//bankAccount b2=bankAccount(p, y, R);
b2=bankAccount(p, y, R);
b2.show();
}






























