#include "Collection.h"
#include <stdexcept>

void Collection::add(double value) {
	if (index_ >= capacity_) {
		throw std::out_of_range("Collection has reached its capacity. Value will not be added.");
		return;
	}

	array_[index_] = value;
	index_++;
}

void Collection::addFront(double value) {
	if (index_ >= capacity_) {
		throw std::out_of_range("Collection has reached its capacity. Value will not be added.");
		return;
	}

	for (int i = index_ - 1; i >= 0; i--) {
		array_[i + 1] = array_[i];
	}

	array_[0] = value;
	index_++;
}

double Collection::get(int ndx) const {
	if (ndx >= index_) {
		throw std::out_of_range("Index outside of range.");
	}

	return array_[ndx];
}

double Collection::getFront() const {
	if (!index_ > 0) {
		throw std::out_of_range("Array is empty.");
	}

	return array_[0];
}

double Collection::getEnd() const {
	if (!index_ > 0) {
		throw std::out_of_range("Array is empty.");
	}

	return array_[index_ - 1];
}

int Collection::find(double needle) const {
	for (int i = 0; i < index_; ++i) {
		if (array_[i] == needle) {
			return i;
		}
	}

	return -1;
}

std::ostream& operator<<(std::ostream& out, const Collection& c) {
	for (int i = 0; i < c.index_ - 1; ++i) {
		out << c.get(i) << " ";
	}
	out << c.get(c.index_ - 1);

	//out << c.index_ - 1 << std::endl;

	return out;
}


/*
---Collection(): Default constructor for the collection.  Initializes the array to a fixed size of your choice
---Collection(int size): argument constructor that takes an integer parameter and uses it to set the initial capacity of the array
---int getSize(): returns the number of elements in the array. Unlike c-strings where we had a null-terminator to mark the end of the array, in this case you will need a variable to keep track of the number of elements currently in the array.
---int getCapacity(): returns the maximum number of elements allowed in the current array.
---void add(double value)  As you add the value to the back of the array, you should also check update the size (i.e. the number of elements in the array).  If the new item exceeds the max size of the list, throw a runtime error...
---throw runtime_error("List Full");
---void addFront(double value): This will add an item to the front of the list.  If the new item exceeds the max size,  throw a runtime_exception.
---double get(int ndx): Gets the value stored at the specified position. Throws and out_of_range exception if the index is outside the bounds of the array.
---double getFront(): Returns the first value in the array. Throws an out_of_range exception if the array is empty.
---double getEnd(): Returns the last value in the array. Throws and out_of_range exception if the array is empty.
---int find(double needle): returns the position of needle in the list, -1 if not found
---friend std::ostream& operator<<(std::ostream& out, const Collection & c): overload the extraction operator to display the list.
*/
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
