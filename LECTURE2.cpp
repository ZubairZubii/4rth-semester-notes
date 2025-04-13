

/////////////////////////////////////    NESTING MEMBER OF CLASSES   ///////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<string.h>
using namespace std;


class binary{

private:
string s;
void chkbinary(void);

public:
void readbinary(void);
void ones(void);
void display(void);
};

void binary:: readbinary(void){
cout<<"ENTER THE BINARY NUMBER"<<endl;
cin>>s;
}

void binary:: chkbinary(void){
for(int i=0;i<1;i++){
if(s.at(i)=='1' || s.at(i)=='0')
cout<<"YES NUMBER IS BINARY"<<endl;
else 
cout<<"NO NUMBER IS NOT BINARY"<<endl;
}
}

void binary:: ones(void){
 chkbinary();
for(int i=0;i<s.length();i++){
if(s.at(i)=='1')
s.at(i)='0';
else
s.at(i)='1';
}
}

void binary:: display(void){

for(int i=0;i<s.length();i++){
                 cout<<s.at(i);
}
cout<<endl;
}


int main(){
 
 binary b;
 b.readbinary();
 //b.chkbinary //error bec it is private
 b.ones();
 b.display();
}




