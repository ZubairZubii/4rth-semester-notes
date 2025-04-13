#include <iostream>
using namespace std;

class Array 
{
	public:
	int Size;
	int *arr;
//	public:
	Array()
	{
		arr=NULL;
		Size=0;
	}
	Array(int Size) // a parameterized constructor initializing an Array of predefined size
	{
		this->Size=Size;
		arr=new int[Size];
		for(int a=0; a<Size; a++)
			arr[a]=0;
	}
	Array(int *arr, int Size) // initializes the Array with an existing Array
	{
		this->Size=Size;
		this->arr=new int[Size];
		for(int a=0; a<Size; a++)
			this->arr[a]=arr[a];
	}
	Array(const Array& a) // copy constructor
	{
		Size=a.Size;
		arr=new int[Size];
		for(int i=0; i<Size; i++)
			arr[i]=a.arr[i];
	}
	int size()
	{
		return Size;
	}
	int& operator[](int i) //returns the integer at index after checking the out of range error
	{
		//if(i<Size)
			return arr[i];
	}
	int& operator[](int i)const
	{
		if(i<Size)
			return arr[i];	
	}
	const Array& operator=(const Array&) //copy the Array
	{
		this->arr=arr;
		this->Size=Size;
		return *this;
	}
	Array operator+(const Array& a) //adds two Array
	{
		Array result(Size);
		for(int i=0; i<Size; i++)
			result.arr[i]=arr[i]+a.arr[i];
		return result;
	}
	Array operator-(const Array& a) //subtracts two Array
	{
		Array result(Size);
		for(int i=0; i<Size; i++)
			result.arr[i]=arr[i]-a.arr[i];
		return result;
	}
	Array operator++() //adds one to each element of Array
	{
		for(int i=0; i<Size; i++)
			arr[i]=arr[i]+1;
		return *this;
	}
	Array operator++(int) //adds one to each element of Array
	{
		for(int i=0; i<Size; i++)
			arr[i]=arr[i]+1;
		return *this;
	}
	Array& operator--(int) //subtracts one from each element of Array
	{
		for(int i=0; i<Size; i++)
			arr[i]=arr[i]-1;
		return *this;
	}
	bool operator==(const Array& a)const //returns true if two Arrays are same
	{
		if(a.Size!=Size)
			return 0;
		for(int i=0; i<Size; i++)
			{
				if(a.arr[i]==arr[i])
				{
					return 1;
				}	
			}
		return 0;
	}
	bool operator!() // returns true if the Array is empty
	{
		if(arr==NULL)
			return 1;
		else return 0;
	}
	void operator+=(const Array& a) //adds two Array
	{
		for(int i=0; i<Size; i++)
			arr[i]=arr[i]+a.arr[i];
	}
	void operator-=(const Array& a) //subtracts two Array
	{
		for(int i=0; i<Size; i++)
			arr[i]=arr[i]-a.arr[i];
	}
	int operator()(int idx, int val) // erases the value val at idx. Returns 1 for a successful //deletion and -1 if idx does not exists or is invalid. Shift the elements after idx to the //left.
	{
		if(arr[idx]!=val)
			return -1;
		if(arr[idx]==val)
			arr[idx]=0;
		return 1;
	}
	~Array() // destructor...
	{
		delete []arr;
	}
};

//ostream& operator<<(ostream& output, const Array& a);//Outputs the Array
istream& operator>>(istream& input, Array& a) //Inputs the Array
{
	for(int i=0; i<a.Size; i++)
		input>>a.arr[i];
	return input;
}

