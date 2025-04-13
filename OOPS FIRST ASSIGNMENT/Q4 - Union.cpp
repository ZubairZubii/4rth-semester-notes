/*
The program will have two arrays with a set of values. 
Call a function named find_union and result will be stored in result array that contains the union of all elements of two array. 
Example 
Arr1 = {1,3,6,7,9,3}
Arr2 = {2,3,6,10}
ResultUnionArr = {1,2,3,6,7,10}
Note: You can add helping function in the code.

*/
#include<iostream>
using namespace std;
struct arrayUnion{
	int arr1[10]; //keep this size
	int arr2[5]; // keep this size
	int *ResultUnionArr;

	input()
	{
		//cin>>arr1 >>arr2
		//input of the arr1 and arr2
	}
	find_union()
	{
		//find union of arr1 and arr2
	}
	printresult()
	{
		//print array with union
	}
};


int main()
{
	arrayUnion u;
	u.input();
	u.find_union();
	u.printresult();
	//main will remain same
}
