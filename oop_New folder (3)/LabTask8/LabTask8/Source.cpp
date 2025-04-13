#include<iostream>
using namespace std;

// QUESTION NO 1
class Rational {
	int numerator;
	int denomerator; 
public:
	Rational() {

		numerator = 0;
		denomerator = 1;
	}
	Rational(int n,int d) {

		numerator = n;
		denomerator = d;
		Rational tem;
		if (tem.numerator < tem.denomerator) {
			for (int i = 1; i <= tem.numerator; i++) {
				if (tem.numerator % i == 0 && tem.denomerator % i == 0) {
					tem.numerator /= i;
					tem.denomerator /= i;
				}
			}
		}
		else
		{
			for (int i = 1; i <= tem.denomerator; i++) {
				if (tem.numerator % i == 0 && tem.denomerator % i == 0) {
					tem.numerator /= i;
					tem.denomerator /= i;
				}
			}
		}

	}

	Rational operator+ (const Rational& obj)
	{
		Rational tem;
		tem.numerator = numerator + obj.numerator;
		tem.denomerator = denomerator + obj.denomerator;

		if (tem.numerator < tem.denomerator) {
			for (int i = 1; i <= tem.numerator; i++) {
				if (tem.numerator % i == 0 && tem.denomerator % i == 0) {
					tem.numerator /= i;
					tem.denomerator /= i;
				}
			}
		}
		else
		{
			for (int i = 1; i <= tem.denomerator; i++) {
				if (tem.numerator % i == 0 && tem.denomerator % i == 0) {
					tem.numerator /= i;
					tem.denomerator /= i;
				}
			}
		}



		return tem;
	}

	Rational operator * (const Rational& obj) {
		Rational tem;
		tem.numerator = numerator * obj.numerator;
		tem.denomerator = denomerator * obj.denomerator;
		if (tem.numerator < tem.denomerator) {
			for (int i = 1; i <= tem.numerator; i++) {
				if (tem.numerator % i == 0 && tem.denomerator % i == 0) {
					tem.numerator /= i;
					tem.denomerator /= i;
				}
			}
		}
		else
		{
			for (int i = 1; i <= tem.denomerator; i++) {
				if (tem.numerator % i == 0 && tem.denomerator % i == 0) {
					tem.numerator /= i;
					tem.denomerator /= i;
				}
			}
		}

		return tem;

	}

	Rational operator / (const Rational& obj) {
		Rational tem;
		tem.numerator = numerator / obj.numerator;
		tem.denomerator = denomerator / obj.denomerator;
		if (tem.numerator < tem.denomerator) {
			for (int i = 1; i <= tem.numerator; i++) {
				if (tem.numerator % i == 0 && tem.denomerator % i == 0) {
					tem.numerator /= i;
					tem.denomerator /= i;
				}
			}
		}
		else
		{
			for (int i = 1; i <= tem.denomerator; i++) {
				if (tem.numerator % i == 0 && tem.denomerator % i == 0) {
					tem.numerator /= i;
					tem.denomerator /= i;
				}
			}
		}

		return tem;

	}



 };

 

//QUESTION NO2 
class Matrix {
	int row;
	int columns;
	int** ptr;
public:
	Matrix() {
		 row=0;
		 columns=0;
		 ptr=nullptr;
	}

	Matrix(int r,int c) {
		row = r;
		columns = c;
		ptr = new int* [row];
		for (int i = 0; i < row; i++)
			ptr[i] = new int[columns];
	}

	void operator=(const Matrix& right) {
	
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < columns; j++) {
				ptr[i][j] = right.ptr[i][j];
			}
		}

}

	bool operator==(const Matrix& right) {
		
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < columns; j++) {
				if (ptr[i][j] == right.ptr[i][j])
					return true;
				else
					return false;

			
			}
		}
	}

	Matrix operator + (const Matrix& right) {
	
		Matrix temp;
		columns = right.columns;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < columns; j++) {
				temp.ptr[i][j] = ptr[i][j] + right.ptr[i][j];

			}
		}
		return temp;

	}

	Matrix operator - (const Matrix& right) {
		
		Matrix temp;
	
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < columns; j++) {
				temp.ptr[i][j] = ptr[i][j] - right.ptr[i][j];

			}
		}
		return temp;

	}

	Matrix operator * (const Matrix& right) {
		
		Matrix temp;
	if(row==right.columns && right.row==right.columns)
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < columns; j++) {
				for (int k = 0; k < right.row; k++) {
					right.ptr[i][j] = ptr[i][k] * ptr[k][j];
				}
	

			}
		}
		return right;

	}

	~Matrix() {
		for (int i = 0; i < columns; i++)
			delete[] ptr[i];

		delete[] ptr;
	}

};




// QUESTION NO 3
class Complex {

	double real;
	double imaginary;
public:

	Complex(){
		real = 0.0;
		imaginary = 0.0;

	}

	Complex(double r, double i) {

		real = r;
		imaginary = i;
	}

	void setReal(double r) {
		real = r;
	 }
	double getReal()const {
		return real;
		}
	void setImaginary(double i) {

		imaginary = i;
		 }
	double getImaginary() const {
		return imaginary;
		 }

	Complex operator+ (const Complex& obj) {
		
		Complex temp;
		temp.real = real + obj.real;
		temp.imaginary = imaginary + obj.imaginary;

		return temp;
	}

	Complex operator- (const Complex& obj) {
		Complex temp;
		temp.real = real - obj.real;
		temp.imaginary = imaginary - obj.imaginary;

		return temp;

	}

	Complex operator* (const Complex& obj) {
		Complex c1, c2;

		c1.imaginary = real * obj.imaginary;
		c1.imaginary += real * obj.imaginary;

		c2.real = real * obj.real;
		c2.real -= imaginary * obj.imaginary;
		c1.real = c2.real;

		return c1;
	}

	void operator= (const Complex& obj) {
		real =obj.real;
		imaginary = obj.imaginary;
	}

	bool operator== (const Complex& obj) {
		if (real == obj.real)
			return true;
		else
			return false;

		if (imaginary == obj.imaginary)
			return true;
		else
			return false;

	}
};


// QUESTION NO 4
class Money {
	int dollar;
	int cents;
public:
	Money() {
		dollar = 0;
		cents = 0;
	}

	Money(int dollar, int cents) // Parameterized Constructor
	{
		this->dollar = dollar;
		this->cents = cents;
	}

	void operator = (const Money& right)
	{
		dollar = right.dollar;
		cents = right.cents;

	}

	bool operator == (const Money& right) {
		if (dollar == right.dollar)
			return true;
		else
			return false;

		if (cents == right.cents)
			return true;
		else
			return false;

	}

	Money operator + (const Money& right) {
		Money temp;
		dollar = dollar + right.dollar;
		cents = cents + right.cents;

	}

	Money operator - (const Money& right) {
		Money temp;
		dollar = dollar - right.dollar;
		cents = cents - right.cents;

	}

	bool operator < (const Money& right) {
		if (dollar < right.dollar)
			return true;
		else
			return false;

	}

	bool operator > (const Money& right) {
		if (dollar > right.dollar)
			return true;
		else
			return false;

	}

	~Money() {}
};


int main(){

}