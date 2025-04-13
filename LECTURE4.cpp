

/////////////////////////////////////   STATIC DATA MEMBER IN C++ OOPS   ////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;


//"if yoy donot use static variable then every object have different count lik zubair qasim umair;  
class Employee{
int id;
// in starting by default static variable initialize 0;
static int count;
public:
void getdata(void){
cout<<"enter the id"<<endl;
cin>>id;
count++;
}

void DisplayData(void){
cout<<id<<endl;
cout<<count<<endl;
}

   static void cont(void){
   cout<<"the static function"<<endl;
cout<<count<<endl;
}

};
// if you want to initialize some value to static count then here yoy initialize not above;
int Employee:: count=1000;

int main(){
Employee zubair,qasim,umair;
zubair.getdata();
zubair.DisplayData();
Employee::cont();


qasim.getdata();
qasim.DisplayData();
Employee::cont();

umair.getdata();
umair.DisplayData();
Employee::cont();
}



