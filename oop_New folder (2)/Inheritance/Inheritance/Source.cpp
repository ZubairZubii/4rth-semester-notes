#include<iostream>
using namespace std;

class A {
	int x;
public:



void getx(int x1) {
	x = x1;
}

friend class B;

};

class B :  public A {
	int y;
public:


	void getx(A& a ) {
		cout << "B Amiguity resolve" << endl;
		cout << a.x<<endl;
	}

};


class D : public B {

public:
	D(A& a) {
	
		cout << a.x;
	}



};


int main() {
	
	A a;
	a.getx(2);
	B b;

	b.getx(a);
}