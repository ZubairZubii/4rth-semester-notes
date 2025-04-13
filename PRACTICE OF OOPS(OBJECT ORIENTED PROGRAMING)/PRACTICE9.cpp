
//////////////////////////////////       TONY GEDDIS CHAPTER 14 CHALLENGE 4        /////////////////////////////////////////////////////

#include<iostream>
using namespace std;

class CourseGrade{
int LS;
int PFE;
int SEassy;
int FE;
public:
CourseGrade(){
LS=0;
PFE=0;
SEassy=0;
FE=0;
}
int setLab(int lab){
LS =lab;
cout<<"LAB SCORE"<<LS<<endl;
return LS;
}

int setPassFailExam(int PassFail){
if(PassFail >=70){
PFE=PassFail;
cout<<"pass fail score"<<PFE<<endl;
return PFE;}
else
{cout<<"you are fail in this exam"<<endl;
return 0;}
}

int setEassy(int es){
SEassy=es;
cout<<"eassy score"<<SEassy<<endl;
return SEassy;
}


int FinalExam(int finalE){
FE=finalE;
cout<<"final score"<<FE<<endl;
return FE;

}


};







int main(){
int a,b,c,d,Rezult=0;
int element=4;
CourseGrade *gradeArray=new CourseGrade[element];
cout<<"student score in class lab"<<endl;
a=gradeArray[0] .setLab(30);
cout<<"sudent pass fali exam score out of 10 question is"<<endl;
b=gradeArray[1] .setPassFailExam(100);
cout<<"this is the student eassy score"<<endl;
c=gradeArray[2] .setEassy(10);
cout<<"this is the final exam score"<<endl;
d=gradeArray[3] .FinalExam(50);
cout<<endl<<endl;
cout<<"this is my reult of student"<<endl;
Rezult = a+b+c+d ;
cout<<"rezult"<<Rezult<<endl;
if(Rezult >=170)
cout<<"Grade A"<<endl;
else if(Rezult >=150)
cout<<"Grade B"<<endl;
else if(Rezult >=100)
cout<<"Grade C"<<endl;
else if(Rezult >=70)
cout<<"Grade D"<<endl;
else
cout<<"Grade F and Fail sorry!"<<endl;
}


