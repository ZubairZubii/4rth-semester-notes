
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////         ABSTRACT BASE CLASS AND                        ///////////////////////////////
///////////////////////////////////          VIRTUAL CLASS                              ///////////////////////////////   

#include<iostream>
#include<cstring>
using namespace std;

//abstract base class
class ZC{
protected:
string text;
float rating;
public:
ZC (string t,float r){
text=t;
rating=r;
}
virtual void Display()=0; // do nothing----> pure virtyal function

};

class ZCVideo : public ZC{
protected:
int VL;
public:
ZCVideo(string t,float r,int L) : ZC(t,r){
VL=L;
}
void Display(){
cout<<"my channel text is:"<<text<<endl;
cout<<"my channel reting is :"<<rating<<endl;
cout<<"my channel videoLength:"<<VL<<endl;
}

};

class ZCText : public ZC{
protected:
int words;
public:
ZCText(string t,float r,int w): ZC(t,r) {
words=w;
}
void Display(){
cout<<"my channel text is:"<<text<<endl;
cout<<"my channel reting is :"<<rating<<endl;
cout<<"my channel words:"<<words<<endl;
}

};

int main(){

string t="my channel is zubair channel";
float r=4.32;
int L=400;
ZCVideo V(t,r,L);
//V.Display();
int w=500;
ZCText T(t,r,w);
//T.Display();

ZC *z[2];
z[0]=&V;
z[1]=&T;

z[0]->Display();
z[1]->Display();
}






























