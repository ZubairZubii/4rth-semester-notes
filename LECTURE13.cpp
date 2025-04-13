

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////            INHERITANCE BASIC       ////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   

#include<iostream>
using namespace std;

//base class
class employee{
public:
        int id;
      int salary;
      employee(){}
employee(int ipid){
id=ipid;
salary=20;
}

};
//derived class
//public member of derived class become public member of base class in public visibility
//  public member of base class become private member of derived class in private visibility
class complex : public employee{

public:
int language;
complex(int ipid){
id=ipid;
language=2;
}

void display(){
cout<<id;
}

};

int main(){
employee e=employee(1);
cout<<e.id;
//e.display();
cout<<e.salary;
complex c=complex(2);
c.display();
cout<<c.language;
cout<<c.id;

}



