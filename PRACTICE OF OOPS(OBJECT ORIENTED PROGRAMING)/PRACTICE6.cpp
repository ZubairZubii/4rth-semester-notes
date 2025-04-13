#include<iostream>
#include <cstring>
#include<cstdlib>
using namespace std;
/*class PersonInfo
{
private:
char *name;
int age;
public:
// Constructor
PersonInfo(char *n, int a)
{ name = new char[strlen(n) + 1];
cout<<"i am not copy and operator"<<<endl;
strcpy(name, n);
age = a; }
// Copy Constructor
PersonInfo(const PersonInfo &obj)
{ name = new char[strlen(obj.name) + 1];
cout<<"i am copy constructor"<<endl;
strcpy(name, obj.name);
age = obj.age; }
// Destructor
~PersonInfo()
{ delete [] name; }
// Accessor functions
const char *getName()
{ return name; }
int getAge()
{ return age; }
// Overloaded = operator
void operator=(const PersonInfo &right)
{ delete [] name;
cout<<"i am operator"<<endl;
name = new char[strlen(right.name) + 1];
strcpy(name, right.name);
age = right.age; }
};

int main()
{
// Create and initialize the jim object.
char * j=new char;
char * b=new char;
cin>>j>>b;

PersonInfo jim ( j,  27);
// Create and initialize the bob object.
PersonInfo bob ( b ,  32);
// Create the clone object and initialize with jim.
PersonInfo clone = jim;
// Display the contents of the jim object.
cout << "The jim Object contains: " << jim.getName();
cout << ", " << jim.getAge() << endl;
// Display the contents of the bob object.
cout << "The bob Object contains: " << bob.getName();
cout << ", " << bob.getAge() << endl;
// Display the contents of the clone object.
cout << "The clone Object contains: " << clone.getName();
cout << ", " << clone.getAge() << endl << endl;
// Assign bob to clone.
cout << "Now the clone will change to bob and ";
cout << "bob will change to jim.\n\n";
clone = bob;
// Call overloaded = operator
bob = jim;
// Call overloaded = operator
// Display the contents of the jim object.
cout << "The jim Object contains: " << jim.getName();
cout << ", " << jim.getAge() << endl;
// Display the contents of the bob object.
cout << "The bob Object contains: " << bob.getName();
cout << ", " << bob.getAge() << endl;
// Display the contents of the clone object.
cout << "The clone Object contains: " << clone.getName();
cout << ", " << clone.getAge() << endl;
}*/


int main(){





int a=3;
cout<<abs(a);








}
