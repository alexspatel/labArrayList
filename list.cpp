// FILE: list.pp
// LAB: Array List
// CSCI 262
// Alex Patel

#include <cstdlib>
#include <iostream>
#include <array>
#include <vector>
using namespace std;

class list {
public:
	list();						  // defualt constructor
	list(const list&);			  // copy construtor
	~list();					  // destructor

	void operator =(const list&); // assignment operator

	int size();
	int get(int position);
	void add(int);
	void insert(int n, int position);
	void erase(int position);
	

private:
	int  _size;
	int  _capacity;
	int* _numbers;

};


list::list()
{
	_size = 0;
	_capacity = 4;
	_numbers = new int[_capacity];
}

// Copy Constructor
list::list(const list& source) {
	_size = source._size;
	_capacity = source._capacity;
	_numbers = new int[_capacity];
	for (int i = 0; i < _size; i++)
	{
		_numbers[i] = source._numbers[i];
	}
}

// Destructor
list::~list()
{
	// free the memory allocated by the object
	delete[] _numbers;
}




// Returns the current count of elements stored in the list.
int list::size()
{	
	int i = 0;
	while(_numbers[i] != '\0')
	{
		i++;
	}
	_size = i;
	return _size;
}

// Returns the element stored at index position; if position is greater than the size of the list, returns 0.
int list::get(int position)
{
	// If the position is greater than the size of the list
	if( position >= _size )
	{
		return 0;
	}

	// Loop thru the list until the element position is found
	for( int i = 0; i < _size; i++ )
	{
		// return the element of position if i = position
		if( i == position )
		{
			return _numbers[i];
		}
	}
}

// Adds an element to the end of the list.
void list::add(int n) 
{
	if (_size == _capacity) 
	{
		int* tmp = new int[2 * _capacity];
		for (int i = 0; i < _size; i++) 
		{
			tmp[i] = _numbers[i];
		}
		delete[] _numbers;
		_numbers = tmp;
		_capacity *= 2;
	}
	_numbers[_size] = n;
	_size++;
}

// Inserts an element before the element at index.The method does nothing if position is greater than the size of the list.
void list::insert(int n, int position)
{
	if (_size == _capacity) 
	{
		int* tmp = new int[2 * _capacity];
		for (int i = 0; i < _size; i++) 
		{
			tmp[i] = _numbers[i];
		}
		delete[] _numbers;
		_numbers = tmp;
		_capacity *= 2;
	}
	_size++;
	
	int* temp = new int[_size + 1];
	
	for(int i = 0; i < _size; i++)
	{		
		if( i < position )
		{
			_numbers[i] = temp[i];
			//cout << numbers[i] << " "; 
		}
		if( i == position )
		{
			_numbers[i] = n;
			//cout << numbers[i] << " ";
		}

		if( i > position )
		{ 
			_numbers[i] = temp[i - 1];
			//cout << numbers[i] << " ";
		}
	}
	delete[] _numbers;
	_numbers = temp;
	

}


// Removes the element at index position.The method does nothing if position is 
// greater than or equal to the size of the list. Page 114 in textbook.
void list::erase(int position)
{
	for( int i = position; i < (_size - 1); i++ )
	{
		_numbers[i] = _numbers[i+1];
	}	
	_size--; 
}



// List Operator. Page 190 in textbook
void list::operator=(const list& source)
{
	// check for self assignment
	if(this == &source)
	{
		return;
	}

	// allocate memory and copy values

	*_numbers = *(source._numbers);
	_capacity = source._capacity;
	_size = source._size;

}




//int main() {
//	
//	int numbers[4] = {1,2,3,4};
//
//	list sizeOf;
//
//	sizeOf.size();
//
//	cout << size() << endl;
//
//	system("pause");
//
//	return 0;
//}
