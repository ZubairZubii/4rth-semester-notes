

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////   AMBIGUITY RESOLUTION IN INHERITANCE   ///////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   

#include<iostream>
using namespace std;

class base1{

public:
void greet(){
cout<<"hello"<<endl;
}
};

class base2{

public:
void greet(){
cout<<"kasa ho"<<endl;
}
};

class derived : public base1, public base2{
public:
void greet(){
// cout<<"yes";
//if derived clas has its on function and statement then the ambigious condition is not matter
 base1 :: greet();
}
};

int main(){
base1 bs1;
bs1.greet();
base2 bs2;
bs2.greet();
derived dr;
dr.greet();

}




























