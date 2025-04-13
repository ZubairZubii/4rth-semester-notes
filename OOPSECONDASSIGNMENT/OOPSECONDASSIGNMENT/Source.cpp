#include<iostream>
#include<cstring>
using namespace std;


///////////////////////////////////////////////////////////////////////////////////
// QUESTION NO 1
// THIS IS A STRUCTURE CALLED PIXEL
struct Pixel {
	int red; //red color
	int green; //green color
	int blue;  // blue color
	
	// THIS IS DEFAULT THAT INITIALIZE ALL COLOR TO 0
	Pixel() {
		red = 0;
		green = 0;
		blue = 0;
	}
	// THIS IS PARAMTARIZED THAT INITIALIZED ALL COLOR ACCORDING TO THE PARAMETER
	Pixel(int r, int g, int b) {
		red = r;
		green = g;
		blue = b;
	}

};

// THIS IS CLASS CALLED IMAGE
class Image {
	int row; //THIS IS IMAGE ROW
	int col; // THIS IS IMAGE COL
	int depth; // THIS IS DEPTH OF IMAGE
	Pixel*** image; // THIS IS THE 3D POINTER OF PIXEL STRUCTURE
public:
// THIS IS PARAMETARIZED CONSTRUCTOR THAT INITIALIZE ALL VALUE ACCORDING TO THE PARAMETER
	Image(int d = 1, int r = 1, int c = 1) {
		row = d;
		col = c;
		depth = d;
// THIS DYNAMICALLY 3D POINTER OF PIXEL STRUCTURE NAME IMAGE 
		image = new Pixel **[depth];
		for (int i = 0; i < row; i++) {
			image[i] = new Pixel * [row];
			for (int j = 0; j < col; j++) {
				image[i][j] = new Pixel[col];
				for (int k = 0; k < depth; k++)
					image[i][j][k] = Pixel();
			}
		}

	}

// THIS IS THE COPY CONSTRUCTOR THAT ALL VALUE IN ONE OBJECT FROM THE OTHER
	Image(const Image& img) {

		row = img.row;
		col = img.col;
		depth = img.depth;

// THIS IS PARAMETARIZED CONSTRUCTOR THAT INITIALIZE ALL VALUE ACCORDING TO THE PARAMETER
	image = new Pixel **[depth];
		for (int i = 0; i < row; i++) {
			image[i] = new Pixel * [row];
			for (int j = 0; j < col; j++) {
				image[i][j] = new Pixel[col];
				for (int k = 0; k < depth; k++)
					image[i][j][k] = img.image[i][j][k];
			}
		}

	}

// frees any dynamically allocated memory used by the Image object.
	~Image() {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				delete[] image[i][j];
			}
			delete[] image[i];
		}
		delete[] image;
	}

	int getRow() // returns the number of rows in the image. 
	{
		return row;
	}

	int getCol() // returns the number of columns in the image.
	{
		return col;
	}

	int getDepth() // returns the number of color channels in the image.
	{
		return depth;
	}

	Pixel getPixel(int x, int y, int z) // returns the Pixel object at the specified x, y, and z coordinates in the image.
	{
		return image[x][y][z];
	}

	void setPixel(int x, int y, int z, Pixel p)  // sets the Pixel object at the specified x, y, and z coordinates in the image to the specified Pixel object.
	{
		image[x][y][z] = p;
	}

	void fill(Pixel p) //p): fills the entire image with the specified Pixel object.
	{
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				for (int k = 0; k < depth; k++) {
					image[i][j][k] = p;
				}
			}
		}
	}

	void clear() // fills the entire image with black (i.e., Pixel(0, 0, 0)).
	{
		Pixel P1(0, 0, 0);
		fill(P1);
	}

	double getAverageBrightness() // calculates and returns the average brightness value of all the pixels in the image.
	{
		double brightness = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				for (int k = 0; k < depth; k++) {
					brightness += (image[i][j][k].red + image[i][j][k].green + image[i][j][k].blue) / 3.0;
				}
			}
		}
	return brightness / row * col * depth;
}

	int getMaximumBrightness(int depth) // finds and returns the maximum brightness value of all the pixels in the specified color channel.
	{
		int max = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (image[i][j][depth].red> max)
					max = image[i][j][depth].red;
			}
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (image[i][j][depth].green > max)
					max = image[i][j][depth].green;
			}
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (image[i][j][depth].blue > max)
					max = image[i][j][depth].blue;
			}
		}


		return max;

	}

	int countBrightPixel() // counts and returns the number of pixels in the image that have at least one color channel with a brightness value of 255.
	{
		int count = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				for (int k = 0; k < depth; k++) {
					if (image[i][j][k].red == 255 || image[i][j][k].green == 255 || image[i][j][k].blue == 255) {
						count++;
						break;
					}
				}
			}
		}
		return count;
	}

	void transposePixel(int depth) // transposes the pixels in the specified color channel of the image.
	{


		Pixel** trans = new Pixel *[row];
		for (int i = 0; i < row; i++) {
			trans[i] = new Pixel  [col];
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				trans[j][i] = image[i][j][depth];
			}
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				  image[i][j][depth]=trans[i][j];
			}
		}

		for (int i = 0; i < row; i++)
			delete[] trans[i];
		delete[] trans;
	}

};







///////////////////////////////////////////////////////////////////////////////////
//	QUESTION NO 2
// Implement a class Pizza that includes the following private data members :
class Pizza {

	char* name;// sting to store the pizza name
	char* topping;// a string to store the pizza topping
	char* size;// – a string for the size of the pizza(can only be regular, medium or large)
	bool is_ready;// a boolean to store the status of the pizza, is it ready or not
	double price;//  a double to store the price of pizza.

public:
	//– a default constructor
	Pizza() {
		name = nullptr;
		topping = nullptr;
		size = nullptr;
		is_ready = 0;
		price = 0.0;

	}
	// – a parametrized constructor
	Pizza(char* toppingVal, double priceVal) {
		strcpy(topping, toppingVal);
		price = priceVal;
	}

	// ready_status) – a parametrized constructor
	Pizza(char* toppingVal, double priceVal, char* nameVal, char* sizeVal, bool
		ready_status) {
		strcpy(topping, toppingVal);
		price = priceVal;
		strcpy(name, nameVal);
		size = sizeVal;
		is_ready = ready_status;
	}

	// – a copy constructor
	Pizza(const Pizza& pizza) {
		topping = pizza.topping;
		price = pizza.price;
		name = pizza.name;
		strcpy(size, pizza.size);
		is_ready = pizza.is_ready;

	}

	// – setter for topping
	void setTopping(char* toppingVal) {

		strcpy(topping, toppingVal);
	}

	// – setter for price
	void setPrice(double priceVal) {

		price = priceVal;
	}

	// – setter for name
	void setName(char* nameVal) {

		strcpy(name, nameVal);
	}
	// – setter for size
	void setSize(char* sizeVal) {


		strcpy(size, size);
	}

	char* getTopping()  // – getter for topping
	{
		return topping;
	}

	double getPrice() // - getter for price
	{
		return price;
	}

	char* getName()   //– getter for name
	{
		return name;
	}
	char* getSize()   //– getter for size
	{
		return size;
	}

	void makePizza()  //– function to make pizza(check if topping is not NULL then set value of is_ready to true)
	{

		if (topping == NULL)
			is_ready = false;
		else
			is_ready = true;


	}

	bool check_status()  //  - function to check if pizza is ready or not
	{
		return is_ready;
	}
};





////////////////////////////////////////////////////////////////////////////////////
//question no 3
// 
//Implement your own string class using only primitive data types. Your string class should
//contain some of the same functionality as the string class in C++.
class String {
public:
	char* data;  //holds the character array that constitutes the string
	int size; // : the current length of the string that the object contains(number of characters in data)

	//Your object should have the following constructors and destructor :
	String() //: default constructor
	{
		data = nullptr;
		size = 0;
	}

	String(int length) // : alternate constructor that initializes length to sizeand initializes data to a new char array of size.
	{
		size = length;
		data = new char[size];

	}

	String(char* str)  //: alternate constructor that initializes length to size of str, initializes data to a new char array of size lengthand fills the contents of data with the contents of str.
	{
		int length = 0;
		for (int i = 0; str[i] != '\0'; i++)
			length++;

		size = length;

		data = new char[size ];
		for (int i = 0; i < size; i++) {
			data[i] = str[i];
		}
		

	}

	String(const String& str) // : copy constructor
	{

		size = str.size;
		data = new char[size];
		for (int i = 0; i < size; i++) {
			data[i] = str.data[i];
		}
		

	}

	~String() // : destructor in which you should delete your data pointer.
	{
		delete[] data;
	}

	int stringLength() // :returns the length of the string in the object
	{
		return strlen(data);
	}

	void clear() // : should clear the data in your string class (dataand length)
	{
		size = 0;
		delete[] data;
		data = new char[1];
		data[0] = '\0';
	}

	bool isEmpty() // : this method should check to see if data within the String class in empty or not.
	{
		return size = 0;

	}

	char* getdata() // : a getter to get the actual string
	{
		return data;
	}
	bool isEqual(char* str) // : this method compares if the data in the calling string object is equal to str.
	{
		for (int i = 0; i < size; i++) {
			if (data[i] != str[i])
				return false;
			else
				return true;
		}

		return true;

	}

	bool equalsIgnoreCase(char* str) // : this method compares the calling string object data with the data in str without considering the case.
	{
		for (int i = 0; i < size; i++) {
			if (data[i] != str[i])
				return false;

		}
		if (size != strlen(str))
			return false;


		return true;

	}

	char* substring(char* substr, int startIndex) {


		int size2 = strlen(substr);
		int i, j;
		for (i = startIndex; i < size - size2; i++) {
			for (j = 0; j < size2; j++) {
				if (data[i + j] != substr[j]) {
					break;
				}
			}
			if (j == size2) {
				return &data[i];
			}


		}

		return NULL;
	}

	char* substring(char* substr, int startIndex, int endIndex) { 
		///: this method should
		/*	search for substr in data within the calling String object between the startIndexand
				endIndex.For example, if you had the string “awesome”and you wanted to find the
				substring ‘es’ starting from startIndex = 2 and endIndex = 5. Your function should
				return “esom”.Returns NULL if substring is not found.*/
		int size2 = strlen(substr);
		int i, j;
		for (i = startIndex; i < size - size2; i++) {
			for (j = 0; j < size2; j++) {
				if (data[i + j] != substr[j]) {
					break;
				}
			}
			if (j == size2 && i + j <= endIndex) {
				char* rezult = new char[endIndex - startIndex + 1];
				for (int k = i; k < endIndex; k++)
					rezult[k - i] = data[k];

				return rezult;
			}


		}

		return NULL;

	}

	void print() // : a function that will output the contents of the character array within the object.If the contents of the String are empty(length == 0) then you should print “NULL”.
	{
		if (stringLength() == isEmpty())
			cout << "NULL";
		else {
			for (int i = 0; i < size; i++) {
				cout << data[i];
			}
		}

	}

};







/////////////////////////////////////////////////////////////////////////////////
// QUESTION  NO 4
class StudentAccount {

	char* name;
	float annualInterestRate;
	double savingBalance;
	char* accountNum; // the account numbers will be from “SA00” to “SA99”. Each account must have a unique account number that has not been assigned to any other customer before.

public:
	// default contructor
	StudentAccount() {
		name = nullptr;
		annualInterestRate = 0.0;
		savingBalance = 0.0;
		accountNum = nullptr;
	}
	// parametarized constructor
	StudentAccount(char* n, float r, double b, char* num) {
		int l1 = 0;
		for (int i = 0; n[i] != '\0'; i++)
			l1++;

		name = new char[l1 + 1];
		for (int i = 0; i <= l1; i++)
			name[i] = n[i];

		annualInterestRate = r;

		savingBalance = b;

		int l2 = 0;
		for (int i = 0; num[i] != '\0'; i++)
			l2++;

		accountNum = new char[l2 + 1];
		for (int i = 0; i <= l2; i++)
			accountNum[i] = num[i];

	}

	// destructor
	~StudentAccount() {
		delete[] name;
		delete[] accountNum;
	}

	// set a annualInterestRate with parameter
	void setAnnualInterestRate(float r) {
		annualInterestRate = r;
	}

	// set a savingBalance with parameter
	void setSavingBalance(double b) {
		savingBalance = b;
	}

	// set a name with parameter
	char* getName() const {
		return name;
	}

	// set a annualInterestRate with parameter
	float getAnnualInterestRate() const {
		return annualInterestRate;
	}

	// set a savingBalance with parameter
	double getSavingBalance() const {
		return savingBalance;
	}

	// set a accountNum with parameter
	char* getAccountNum() const {
		return accountNum;
	}


};

void OpenCustomerAccount(StudentAccount* savers[], int accountsOpen, char* NameVal, double balance)  // – a function to create a new accountand assign it an account number.
{
	// – an array of 100 SavingAccount pointers.

	if (accountsOpen > 100) {
		cout << "Sorry Account limit is full";
		return;
	}

	int l = 0;
	for (int i = 0; NameVal[i] != '\0'; i++)
		l++;

	char* newname = new char[l + 1];

	for (int i = 0; i < l; i++) {
		newname[i] = NameVal[i];

		char n[4];
		n[0] = 'S';
		n[1] = 'A';
		n[2] = '0' + (accountsOpen % 10);
		n[3] = '0' + (accountsOpen / 10);


		savers[accountsOpen] = new StudentAccount(newname, 0.0f, balance, n);
	}

}

float calculateMonthlyInterest(StudentAccount* saver) // - that calculates the monthly interest by multiplying the balance by annualInterestRate divided by 12.
{
	float monthly = (saver->getSavingBalance() * saver->getAnnualInterestRate()) / 12.0;

	return monthly;
}

void modifyInterestRate(StudentAccount* saver, float newValue)
{
	saver->setAnnualInterestRate(newValue);

}

int SearchCustomer(StudentAccount* savers[], int accountsOpen, char* accountNum)  // – a  function that searches for an account using an account number.If the customer is found it returns the array index otherwise return -1
{

	for (int i = 0; i < accountsOpen; i++) {
		if (savers[i]->getAccountNum() == accountNum) {
			return i;
		}

	}
	return -1;

}


bool UpdateAccountBalance(StudentAccount* savers[], int accountsOpen, char* accountNumVal, double balanceVal)  // – a function that updates a customer’s balance
{
	bool check = false;
	for (int j = 0; j < accountsOpen; j++) {
		bool found = true;

		for (int i = 0; i < 4; i++) {
			if (savers[j]->getAccountNum()[i] != accountNumVal[i]) {
				found = false;
				break;

			}
		}
		if (found) {
			savers[j]->setSavingBalance(balanceVal);
			check = true;
		}
	}
	return check;

}






//////////////////////////////////////////////////////////////////////////////////
// QUESTION NO 5
class Integer {
	int num;
	string str;
public:
	//include all the necessary checks before performing the operations in the functions

	Integer()// a default constructor
	{
		num = 0;
		str = "";
	}

	Integer(int n)// a parametrized constructor
	{
		num = n;

	}
	Integer(string& s) // a parametrized constructor
	{
		str = s;


	}

	void set(int n)//set value
	{
		num = n;
	}

	int get()const //get value at (i,j)
	{
		return num;
	}

	int bitCount() //Returns the number of one-bits in the 2's complement binary
	{
		int count = 0;
		while (num != 0) {
			if (num % 2 == 1)
				count++;
		}
		num /= 2;

		return count;
	}

	int compareTo(Integer& other) //Compares two Integer objects numerically.
	{
		if (num > other.num)
			return 1;
		else if (num < other.num)
			return -1;
		else
			return 0;
	}

	double doubleValue() //Returns the value of this Integer as a double.
	{
		return (double)num;
	}


	float floatValue() //Returns the value of this Integer as a float.
	{
		return (float)num;
	}


	Integer plus(const Integer& other) //adds two Integers and return the result
	{
		Integer rez;
		rez.num = num + other.num;

		return rez;
	}

	Integer minus(const Integer& other) // subtracts two Integers and return the result
	{
		Integer rez;
		rez.num = num - other.num;

		return rez;

	}


	Integer multiple(const Integer& other) //multiplies two Integers and return the result
	{
		Integer rez;
		rez.num = num * other.num;

		return rez;

	}

	Integer divide(const Integer& other) //divides two Integers and return the result
	{
		Integer rez;
		rez.num = num / other.num;

		return rez;
	}

	static int numberOfLeadingZeros(int i) /*Returns the number of zero bits preceding the
	highest-order ("leftmost") one-bit in the two's complement binary representation of the
	specified int value.*/
	{
		if (i == 0) {
			return 32;
		}

		int count = 0;
		while (i > 0 && (i % 2) == 0) {
			count++;
			i /= 2;
		}

		return count;

	}

	static int numberOfTrailingZeros(int i) /*Returns the number of zero bits following the
	lowest-order ("rightmost") one-bit in the two's complement binary representation of the
	specified int value.*/
	{
		if (i == 0)
			return 32;

		int count = 0;

		while (i % 2 == 0) {
			count++;
			i >>= 1;

		}
		return count;

	}


	

	static string toBinaryString(int i) //Returns string representation of i
	{
		


		if (i == 0)
			return "0";

		int bit = 1;
		string rez = "";
		while (i != 0) {
			rez = (bit & i ? "1" : "0") + rez;

			i >>= 1;
		}
		return rez;

	}

	static string toHexString(int i)//Returns string representation of i in base16
	{
		if (i == 0) {
			return "0";
		}

		string result = "";
		int mask = 15;
		while (i != 0) {
			int remainder = i % 16;
			if (remainder < 10)
				result = (char)(remainder + '0') + result;
			else
				result = (char)(remainder + 'a') + result;

			i /= 16;
		}
		return result;


	}



	static string toOctString(int i) //Returns string representation of i in base 8
	{
		if (i == 0) {
			return "0";
		}

		string result = "";
		while (i != 0) {
			int remainder = i % 8;
			result = (char)('0' + remainder) + result;
			i /= 8;
		}
		return result;


	}


};








////////////////////////////////////////////////////////////////////////////////
// QUESTION NO 6
class Library {
	char* bookTitle; // – a string to hold the title of the book
	char* author; // – a string to hold the name of the author

	int bookID; // – an integer to hold book identification numbers between 1 and 100.
	int quantity; // – an integer to hold the number of copies of the book in the library
	float price; // – a float to hold the price of each book
	static int totalBooks; // – a static integer to hold the total number of books in the library
	//	The class should implement the following public methods :
public:
	Library() {
		bookTitle = nullptr;
		author = nullptr;
		bookID = 0;
		quantity = 0;
		price = 0.0;

	}
	void setBookTitle(char* title)//– a setter for book title
	{
		strcpy(bookTitle,title);
	}


	void setAuthor(char* authorName) // – a setter for author name
	{
		
		strcpy(author, authorName);
	}
	void setBookID(int bookID) // – a setter for book ID
	{
		this->bookID = bookID;

		}
	void setQuantity(int quantity) // – a setter for number of copies of the book
	{
		this->quantity = quantity;
			}
	void setPrice(float price) // – a setter for the price of each book
	{
		this->price = price;
				}
	static void setTotalBooks(int totalBooks)// – a setter for total number of books
					{
						Library:: totalBooks = totalBooks;
					}

	char* getBookTitle()  //– a getter for book title
					{
						return bookTitle;
					}
	
	char* getAuthor() // – a getter for author name
					{
						return author;
						}

	int getBookID() // – a getter for book ID
					{
						return bookID;

							}
	int getQuantity() // – a getter for number of copies of the book
					{
						return quantity;
								
					}
					
	float getPrice() // – a getter for the price of each book
					{
						return price;
									}

	void calcTotalPrice()     //– a function to calculate the total price of all copies of the book
					{
						float total = price * quantity;

					 }
	static int getTotalBooks()  //– a static function to get the total number of books in the  library
					{
						return totalBooks;
						 }
};


int Library::totalBooks = 0;

Library getBook_at(Library books[100], int index)  //– returns the Library object at the given array index
{
	return books[index];
}
void addBook(Library books[100], Library newBook) //– adds a new book to the library array
{
	int ind=0;
	
	for (int i = 0; books[i].getBookID() != 0 && i < 100 ;i++) {
		ind++;
	}

	if (ind < 100)
		books[ind] = newBook;
	else
		cout << "SORRY LIBRARY IS FULL";
}

void removeBook(Library books[100], int bookID)  // – removes the book with the given book ID from the library array
{
	int ind = 0;
	for (int i = 0; books[i].getBookID() != bookID; i++) {
		ind++;
	}
	if (ind < 100)
		cout << "REMOVE THE BOOK " << books[ind].getBookID() <<" "<< books[ind].getBookTitle() << endl;
	else
		cout << "SOORY THIS BOOK IS NOT AVAILABLE";

 }

void SortByTitle(Library books[100])  //– sorts the books in ascending order based on title
{
	Library temp;

	for (int i = 0; i < Library :: getTotalBooks(); i++)
	{
		for (int j = 0; j < Library:: getTotalBooks() ; j++)
		{
			if ( books[j].getBookTitle() > books[j + 1].getBookTitle() ) {

				temp = books[j];
				books[j] = books[j + 1];
				books[j + 1] = temp;
			
			}
		}
	}

}

void SortByAuthor(Library books[100])  //– sorts the books in ascending order based on author name
{
	Library temp;
	for (int i = 0; i < Library::getTotalBooks(); i++)
	{
		for (int j = 0; j < Library::getTotalBooks(); j++)
		{
			if (books[j].getAuthor() > books[j + 1].getAuthor() ) {
				 
				temp = books[j];
				books[j] = books[j + 1];
				books[j + 1] = temp;

			}
		}
	}


}

void SortByPrice(Library books[100])  //– sorts the books in ascending order based on price
{
	Library temp;
	for (int i = 0; i < Library::getTotalBooks(); i++)
	{
		for (int j = 0; j < Library::getTotalBooks(); j++)
		{
			if (books[j].getPrice() > books[j + 1].getPrice() ) {

				temp = books[j];
				books[j] = books[j + 1];
				books[j + 1] = temp;

			}
		}
	}
}

bool searchByTittle(Library books[10], char* titlename)  //- returns true if the book with the titlename is found in the list
{
	for (int i = 0; i < Library :: getTotalBooks(); i++) {
		if (books[i].getBookTitle() == titlename)
			return true;
		else
			return false;
	}
}

Library mostExpensiveBook(Library books[10])  //- returns the book with the most expensive price from the list
{
	Library maxexpensive;
	float maxp = 0;
	for (int i = 0; i < Library::getTotalBooks(); i++)
	{
		if (books[i].getPrice() > maxp)
			maxp = books[i].getPrice();
		maxexpensive=books[i];
	}
	return maxexpensive;

}







///////////////////////////////////////////////////////////////////////////////////
// QUESTION NO 7
class Student{
	int stdID;      // - an integer to hold the student's identification number
		string name;  //- a string to hold the student's first name
		string* courseCodes;   //- a dynamic array of strings to hold the course codes of the courses taken by the student
			int numCourses; /// -an integer to hold the number of courses taken by the student
		int* courseGrades;  //- a dynamic array of integers to hold the grades obtained by the student in the courses taken
		float gpa;  // -a float to hold the grade point average of the student, calculated as the sum of 	all course grades divided by the number of courses taken
public:
	Student() {

		stdID = 0;
		name = "";
		courseCodes = nullptr;
		numCourses = 0;
		courseGrades = nullptr;
		gpa = 0.0;
	}


	int getStdID() // -a getter for the student's ID
	{
		return stdID;

	}
	string getName() // -a getter for the student's first name
	{
		return name;

	}

	int getNumCourses() // -a getter for the number of courses taken by the student
	{
		return numCourses;
	}
				
	string getCourseCode(int i) // -a getter for the course code of the course taken at index i of the courseCodes array
	{
		return courseCodes[i];
				}
					
	int getCourseGrade(int i) // -a getter for the grade obtained by the student in the course taken at index i of the courseGrades array
	{
		return courseGrades[i];
					}
						
	float getGPA() // -a getter for the student's GPA
						{
							return gpa;
						}

	void setStdID(int id) // -a setter for the student's ID
						{

							stdID = id;
						}

	void setName(string firstName) // -a setter for the student's first name
						{
							name=firstName;

						}
							
	void setCourseGrade(string courseCode, int grade) // -a function to set the grade obtained by the student in the course with the given course code
						{
							for (int i = 0; i < numCourses; i++) {
								if (courseCodes[i] == courseCode)
									courseGrades[i] = grade;
								
							}

						}
								
	void addCourse(string courseCode, int grade) // -a function to add a course with the given course code and grade to the student's record
						{
							string* newcourse =new string[numCourses + 1]();
							int* newgrade =new int[numCourses + 1];

							for (int i = 0; i < numCourses; i++) {
								newcourse[i] = courseCodes[i];
								newgrade[i] = courseGrades[i];
							}
							newcourse[numCourses] = courseCode;
							newgrade[numCourses] = grade;

							delete[] courseCodes;
							delete[] courseGrades;

							courseCodes = newcourse;
							courseGrades = newgrade;


		}
									
									
	void calcGPA() // -a function to calculate the student's GPA
						{
							float sumofcourseGrades = 0;
							for (int i = 0; i < numCourses; i++) {
								sumofcourseGrades += courseGrades[i];
							}
							gpa = sumofcourseGrades / numCourses;


	}


};


Student getStudentAt(Student students[], int index)   // - returns the Student object at he given array index
{
	return students[index];

}

float calcClassGPA(Student students[], int numStudents) // - calculates the average GPA of all students in the array
{
	float average = 0;

	for (int i = 0; i < numStudents ; i++) {
		average += students[i].getGPA();
	}
	average = average / numStudents;

	return average;
 }


float getMaxGPA(Student students[], int numStudents)  // - calculates the maximum GPA from all the students in the array
{
	float max = 0;
	for (int i = 0; i < numStudents ; i++) {
		if (students[i].getGPA() > max)
			max = students[i].getGPA();
	}
	return max;

}

int getMinGPA(Student students[], int numStudents) // - calculates the minimumGPA from all the students in the array
{
	int min = 0;
	for (int i = 0; i < numStudents; i++) {
		if (students[i].getGPA() < min)
			min = students[i].getGPA();
	}
	return min;
 }

void printStudentRecord(Student student) //- prints the record of the given student, including the student's ID, name, course codes, grades, and GPA
{

	cout << "sudent id" << student.getStdID() << endl;
	cout << "sudent Name" << student.getName() << endl;
	cout << "sudent Cources" << student.getNumCourses() << endl;
	int i;
	cout << "ENTER THE Index in which you want code";
	cin >> i;
	cout << "sudent Cources" << student.getCourseCode(i) << endl;
	cout << "ENTER THE Index in which you want grade";
	cin >> i;
	cout << "sudent Grades" << student.getCourseGrade(i) << endl;

}

void printAllStudentRecords(Student students[], int numStudents)  //- prints the records of all students in the array
{
	for (int i = 0; i < numStudents; i++) {
		cout << "sudent id" << students[i].getStdID() << endl;
		cout << "sudent Name" << students[i].getName() << endl;
		cout << "sudent Cources" << students[i].getNumCourses() << endl;
		int ind;
		cout << "ENTER THE Index in which you want code";
		cin >> ind;
		cout << "sudent Cources" << students[i].getCourseCode(ind) << endl;
		cout << "ENTER THE Index in which you want grade";
		cin >> ind;
		cout << "sudent Grades" << students[i].getCourseGrade(ind) << endl;
	}
}









