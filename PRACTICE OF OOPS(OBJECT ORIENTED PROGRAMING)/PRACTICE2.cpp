

//////////////////////////..............                CAR CLASS              ....................//////////////////////////////////////    

#include<iostream>
#include<cstring>
using namespace std;

class CAR{

int yearCar;
string model;
int speed=0;
public:
CAR(int y,string m ){
yearCar=y;
model=m;
//speed;
}

void Accelerate(){
speed+=5;
}

void brake(){
speed-=5;
}

void getRezult(){
cout<<"my year of car "<<yearCar<<endl;
cout<<"my car model "<<model<<endl;
cout<<"my car speed" <<speed<<endl;
}


};



int main(){
CAR c1(2022 ,"MOCCO");
c1.Accelerate();
c1.getRezult();
cout<<endl<<endl;
CAR c2(2023 ,"CIVIC");
c2.brake();
c2.getRezult();
}



