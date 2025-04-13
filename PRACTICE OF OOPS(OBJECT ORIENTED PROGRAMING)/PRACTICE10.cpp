
//program to convert number into word
#include<iostream>
#include<cstring>
using namespace std;

void convert(int value){

string first[20]={"zero","one","two","three","four","five","six","seven","eight","nine","eleven","twelve",
                  "thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
string second[10]={" ","ten","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};

 if( value>=1000 ){
      convert(value/1000);
      cout<<" thousand ";
 if(value%1000){
     if(value%1000<100){
      cout<<"and ";}
      cout<<"  ";
      convert(value%1000);}
 }
else if(value>=100){
convert(value/100);
cout<<" hundred ";
  if( value%100){
  cout<<"and ";
  convert(value%100);}
  }
 else if(value>=20){
 cout<<second[value/10];
      if(value%10){
      cout<<" ";
      convert(value%10);}     
      }
  else{ 
  cout<<first[value];}

}


int main(){
int number;
cout<<"enter the number"<<endl;
cin>>number;
convert(number);
}



