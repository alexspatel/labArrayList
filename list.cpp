// FILE: list.pp
// LAB: Array List
// CSCI 262
// Alex Patel

#include <cstdlib>
#include <iostream>

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
	void print();

private:
	int  _size;
	int  _capacity;
	int* _numbers;
};


list::list() {
	_size = 0;
	_capacity = 4;
	_numbers = new int[_capacity];
}

list::list(const list& source) {
	_size = source._size;
	_capacity = source._capacity;
	_numbers = new int[_capacity];
	for (int i = 0; i < _size; i++) {
		_numbers[i] = source._numbers[i];
	}
}

list::~list()
{
	delete _numbers;
}


// The assignment operator
void list::operator=(const list&)
{

}


// Returns the current count of elements stored in the list.
int list::size()
{
	
}

// Returns the element stored at index position; if position is greater than the size of the list, returns 0.
int list::get(int position)
{

}

// Adds an element to the end of the list.
void list::add(int n) {
	if (_size == _capacity) {
		int* tmp = new int[2 * _capacity];
		for (int i = 0; i < _size; i++) {
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

}

// Removes the element at index position.The method does nothing if position is greater than or equal to the size of the list.
void list::erase(int position)
{

}


//void list::print() {
//	for (int i = 0; i < _size; i++) {
//		cout << _numbers[i] << ' ';
//	}
//}


//int main() {
//	list foo;
//	for (int i = 0; i < 50; i++) {
//		foo.add(i);
//	}
//
//	foo.print();
//	cout << endl;
//
//	system("pause");
//
//	return 0;
//}
