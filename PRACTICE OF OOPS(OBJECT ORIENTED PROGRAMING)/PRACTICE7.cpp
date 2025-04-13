#include<iostream>
#include<cstdlib>
using namespace std;

// The FeetInches class holds distances or measurements
// expressed in feet and inches.
class FeetInches
{

private:
int feet;
// To hold a number of feet
int inches;
// To hold a number of inches
void simplify(); // Defined in FeetInches.cpp
public:
// Constructor
FeetInches(int f = 0, int i = 0)
{ feet = f;
inches = i;
simplify(); }
// Mutator functions
void setFeet(int f)
{ feet = f; }
void setInches(int i)
{ inches = i;
simplify(); }
// Accessor functions
int getFeet() const
{ return feet; }
int getInches() const
{ return inches; }
// Overloaded operator functions
FeetInches operator + (const FeetInches &); // Overloaded +
FeetInches operator - (const FeetInches &); // Overloaded -
};

void FeetInches::simplify()
{
if (inches >= 12)
{
feet += (inches / 12);
inches = inches % 12;
}
else if (inches < 0)
{
feet -= ((abs(inches) / 12) + 1);
inches = 12 - (abs(inches) % 12);
}
}

FeetInches FeetInches::operator + (const FeetInches &right)
{

FeetInches temp;
cout<<"yah"<<endl;
cout<<temp.inches<<endl; //0
cout<<right.inches<<endl; //inches recent value in feetinches class

temp.inches = inches + right.inches;
temp.feet = feet + right.feet;
temp.simplify();
return temp;
}

FeetInches FeetInches::operator - (const FeetInches &right)
{
FeetInches temp;
temp.inches = inches - right.inches;
temp.feet = feet - right.feet;
temp.simplify();
return temp;
}

int main()
{
int feet, inches;
// To hold input for feet and inches
// Create three FeetInches objects. The default arguments
// for the constructor will be used.
FeetInches first, second, third;
// Get a distance from the user.
cout << "Enter a distance in feet and inches: ";
cin >> feet >> inches;
// Store the distance in the first object.
first.setFeet(feet);
first.setInches(inches);
// Get another distance from the user.
cout << "Enter another distance in feet and inches: ";
cin >> feet >> inches;
// Store the distance in second.
second.setFeet(feet);
second.setInches(inches);
// Assign first + second to third.
third = first + second;
// Display the result.
cout << "first + second = ";
cout << third.getFeet() << " feet, ";
cout << third.getInches() << " inches.\n";
}





