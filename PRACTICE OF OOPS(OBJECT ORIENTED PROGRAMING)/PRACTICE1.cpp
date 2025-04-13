

///////////////////////////////  FICTORIAL OF NUMBER USING CLASS IN OOPS   ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

class FACTORIAL{

int n;
int fact=1;
public:

void getData(int n1){
n=n1;
}
void CALCULATION(){
for(int i=1;i<=n;i++){
fact*=i;
}
}

void DisplayData(){
cout<<"your number factorial is:"<<fact<<endl;
}

};


int main(){
int num;
cout<<"enter the number"<<endl;
cin>>num;
if(num<0){
cout<<"sorry it is not possible"<<endl;
exit(0);
}
FACTORIAL f;
f.getData(num);
f.CALCULATION();
f.DisplayData();
}

































