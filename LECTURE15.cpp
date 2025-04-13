

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////      MULTI LEVEL INHERITANCE       ////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////   

#include<iostream>
using namespace std;

class student{

protected:
int rollNumber;
public:

void setRollNumber(int r){
rollNumber=r;
}

void getRollNumber(){
cout<<"your roll number is "<<rollNumber<<endl;
}

};

class exam: public student{

protected:
float math;
float physics;
public:

void setMarks(float m,float ph ){
math=m;
physics=ph;
}

void getMarks(){
cout<<"your exam marks in math is "<<math<<endl<<"your exam marks in phusics is "<<physics<<endl;
}

};

class rezult : public exam{

float rezult;
public:
void Display(){
getRollNumber();
getMarks();
cout<<"your exam percentage in math and physics is :"<< (math +physics)/2<<"%"<<endl;
}
};

int main(){
rezult rz;
cout<<"enter your roll number"<<endl;
rz.setRollNumber(2222591);
cout<<"enter your marks is math and physics"<<endl;
rz.setMarks(90,94);
rz.Display();

}



/*// multiplt inherited
class base1{
}
class base2{
}
class derived : public base1,public base2 ,public base3 //and onward{
}       
*/




