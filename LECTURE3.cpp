

/////////////////////////////////////    USING OOPS AS A ARRAYS   ///////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

class shop{
int itemId[100];
int itemPrice[100];
int counter;
public:
void intilConter(void){
counter=0;
}
void getPrice(void);
void DisplayPrice(void);
};

void shop::getPrice(void){
cout<<"enter the item ID"<<counter+1<<endl;
cin>>itemId[counter];
cout<<"enter the item Price"<<counter+1<<endl;
cin>>itemPrice[counter];
counter++;
}

void shop :: DisplayPrice(void){
for(int i=0;i<counter;i++)
cout<<"price of item"<<itemId[i]<<"is"<<itemPrice[i]<<endl;
}



int main(){
shop sh;
sh.intilConter();
sh.getPrice();
sh.getPrice();
sh.getPrice();
sh.DisplayPrice();
}




