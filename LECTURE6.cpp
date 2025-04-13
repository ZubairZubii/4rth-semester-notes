

///////////////////////////////////////////..    FRIEND FUUNCTION   /////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;


class complex{
int a;
int b;
// you can declare friend function public as well as private
//Friend complex setDataSum(complex c1,complex o1);
public:
friend complex setDataSum(complex c1,complex o1);
void setData(int a1,int b1){
a=a1;
b=b1;
}

void getData(void){
cout<<"number is:"<<a<<"+"<<b<<"i"<<endl;
}

};


complex setDataSum(complex c1,complex o1){
complex o2;
// you cannot acees name directly like a + b, but you tell that from which a and b 
// from c1 and o1
o2.setData((c1.a+o1.a),(c1.b+o1.b));
return o2;
}


int main(){

complex a,b,sum;
a.setData(1,2);
a.getData();
b.setData(3,4);
b.getData();
//yowu cannot acess friend function directly like sum.setDataSum(a,b);
sum=setDataSum(a,b);
sum.getData();

}


