// FILE: list.cpp
// LAB: Array List
// CSCI 262
// Alex Patel

#include <cstdlib>
#include <iostream>

using namespace std;

class list {
public:
	list();				// Default construtor
	list(const list& source);	// Copy Constructor
	~list();			// Destructor

	void operator =(const list& source);	// Assignment Operator

	int size();
	int get(int position);
	void add(int);
	void insert(int n, int position);
	void erase(int position);
	void print();

private:
	int  _size;
	int  _capacity;
	int* _numbers;
};

// Default Contructor
list::list() 
{
	_size = 0;
	_capacity = 4;
	_numbers = new int[_capacity];
}

// Copy Constructor
list::list(const list& source) 
{
	_size = source._size;
	_capacity = source._capacity;
	_numbers = new int[_capacity];
	for (int i = 0; i < _size; i++) {
		_numbers[i] = source._numbers[i];
	}
}

// Destructor
list::~list()
{
	delete [] _numbers;
}

// Assignment Operator
void list::operator=(const list& source)
{
	int *new_numbers;

	if(this == &source)
	{
		return;
	}

	if(_capacity != source._capacity)
	{
		new_numbers = new int[source._capacity];
		delete [] _numbers;
		_numbers = new_numbers;
		_capacity = source._capacity;
	}
}

// Size member function
int list::size()
{
	return _size;
}

// Add member function
void list::add(int n) 
{
	if (_size == _capacity) {
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

// Get member function
int list::get(int position)
{
	for(int i = 0; i < 5; i++)
	{
		if(i == position)
		{
			return i;
			cout << i << endl;
		}
	}
	return 0;
}

// Insert member function ------->>>>>>>> Creates an error: Infinite Loop
void list::insert(int n, int position)
{
	
	/*int* temp = new int[_capacity];
	for(int i = 0; i < _size; i++)
	{
		temp[i] = _numbers[i];
	}
	_size++;
	for(int i = 0; i < _size; i++)
	{
		if(i < position)
		{
			_numbers[i] = temp[i];
		}
		if(i == position)
		{
			_numbers[i] = n;
		}
		if(i > position)
		{
			_numbers[i] = temp[i-1];
		}
	}*/
}

// Erase member function
void list::erase(int position)
{
	int* temp = new int[_capacity];
	for(int i = 0; i < _size; i++)
	{
		temp[i] = _numbers[i];
	}
	for(int i = 0; i < (_size - 1); i++)
	{
		if(i < position)
		{
			_numbers[i] = temp[i];
		}
		if(i >= position)
		{
			_numbers[i] = temp[i+1];
		}
	}
	_size--; // erase the last element in the list.
}


// Print function
void list::print() 
{
	for (int i = 0; i < _size; i++) {
		cout << _numbers[i] << ' ';
	}
}


// Main function
//int main() 
//{
//	list foo;
//	for (int i = 0; i < 10; i++) {
//		foo.add(i);
//	}
//
//	foo.print();
//	cout << endl;
//
//	foo.get(4);
//
//	system("pause");
//
//	return 0;
//}
