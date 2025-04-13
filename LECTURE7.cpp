

/////////////////////////////////////   MEMBER FRIEND FUNCTIOM   ////////////////////////////////////////////////////////
/////////////////////////////////         FRIEND CLASSES     ////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

//forward Diclaration
class complex;


class calculator{
public:
int SumRealData(complex ,complex);
int SumImaginary(complex ,complex);
};



class complex{

int a;
int b;
//friend int calculator :: SumRealData(complex ,complex );
//friend int calculator :: SumImaginary(complex ,complex );

friend class calculator;
public:

void setData(int a1,int b1){
a=a1;
b=b1;
}

void getData(void){
cout<<a<<"+"<<b<<"i"<<endl;
}

};


int calculator :: SumRealData(complex o1,complex o2){
return (o1.a+o2.a);
}
 int calculator :: SumImaginary(complex o1 ,complex o2){
 return (o1.b+o2.b);
}

int main(){
complex a,b;
a.setData(1,2);
a.getData();
b.setData(3,4);
b.getData();
calculator c;
int com1=c.SumRealData(a,b);
cout<<com1;
int com2=c.SumImaginary(a,b);
cout<<com2;
}





/*
//forward Diclaration
class zubair;

class Zdost{
public:
int Sum(zubair,zubair);

};




class zubair{

int a;
int b;
friend int Zdost :: Sum(zubair,zubair);
//friend class Zdost;
public:
void setdata(int a1,int b1){
a=a1;
b=b1;
}
};


int Zdost :: Sum(zubair o1,zubair o2){
return ((o1.a+o2.a),(o1.b+o2.b));
}


int main(){
zubair z1,z2;
z1.setdata(1,2);
z2.setdata(3,4);
Zdost zd;
int rez=zd.Sum(z1,z2);
cout<<rez;
}
*/








