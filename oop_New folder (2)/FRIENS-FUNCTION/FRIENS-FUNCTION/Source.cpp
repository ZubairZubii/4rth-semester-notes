#include<iostream>
using namespace std;

class myfriend {
	
	int a, b;

public:
	myfriend() {
		a = 0;
		b = 0;

	}

	myfriend(int a,int b) {
		
		this->a = a;
		this->b = b;

	}

	void print() {
		cout << "a" << a << "b" << b << endl;
	}
	//friend myfriend add(myfriend& f1, myfriend& f2);
	friend class B;
};


class B {

public:
	//void(myfriend &obj) {
	void pr(myfriend& obj) {
		cout << obj.a;
	}
	//}


};


/*
 myfriend add(myfriend& f1, myfriend& f2) {
	 myfriend f3;
	// f3.a = f1.a + f2.a;
	 f3.a=(f1.a+f2.a);
	 f3.b = f1.b + f2.b;
	 return f3;
}
*/
int main() {
	myfriend f1(1,2), f2(2,3);
	//f1();
	//f2()
	myfriend f3;

	f3.print();
	B f;
	f.pr(f1);


}