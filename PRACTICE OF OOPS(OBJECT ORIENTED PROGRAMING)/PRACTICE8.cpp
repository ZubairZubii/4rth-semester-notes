#include <iostream>
using namespace std;



/*class test{
  int x;
  public:
  test(int x=0) : x{x} {}
  friend istream & operator >> (istream& input ,test & a);
  friend ostream & operator << (ostream& output ,test & a);
    
    
};
istream & operator >> (istream& input ,test & a){
    input>>a.x;
    return input;
    
}
ostream & operator << (ostream& output ,test & a){
    output<<a.x;
    return output;
};
int main() {
 test t;
 cin>>t;
 cout<<t;
    return 0;
}*/




class subject{
int subj[3];
public:
subject(int sub1,int sub2,int sub3){

subj[0]=sub1;
subj[1]=sub2;
subj[2]=sub3;

}

int operator[] (int position){
return subj[position];
} 


};



int main(){

subject s(1,2,3);
cout<<s[0];
cout<<s[1];
cout<<s[2];
}












