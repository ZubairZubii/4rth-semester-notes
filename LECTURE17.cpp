

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////          VIRTUAL BASE CLASS        ////////////////////////////////////////////////////
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

class exam: virtual public student{

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


class sport : virtual public student{
protected:
float score;
public:
void getScore(float sc){
score=sc;
}
void displayScore(){
cout<<"my sport score is:"<<score<<endl;
}

};
class rezult : public exam, public sport{

float rezult;
public:
void Display(){
getRollNumber();
getMarks();
displayScore();
cout<<"your total score in math and physics and sports is :"<< (math +physics+ score)<<endl;
}
};

int main(){
rezult rz;
cout<<"enter your roll number"<<endl;
int roll;
cin>>roll;
rz.setRollNumber(roll);
cout<<"enter your marks is math and physics"<<endl;
int m,p;
cin>>m>>p;
rz.setMarks(m,p);
cout<<"enter your sport score"<<endl;
int s;
rz.getScore(s);
rz.Display();

}

