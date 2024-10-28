#include <iostream>

using namespace std;

template <typename type>
class list {
public:
	type* arr;
	int maxSize;
	int currentSize;

public:
	list(int size = 10) : maxSize(size), currentSize(0) {
		arr = new type[maxSize];
	}

	list(const list& other) : maxSize(other.maxSize), currentSize(other.currentSize) {
		arr = new type[maxSize];
		for (int i = 0; i < currentSize; ++i) {
			arr[i] = other.arr[i];
		}
	}

	virtual ~list() {
		delete[] arr;
	}

	virtual void addElementAtFirstIndex(type element) = 0;
	virtual void addElementAtLastIndex(type element) = 0;
	virtual void removeElementFromStart() = 0;
};

template <typename type>
class Arraylist : public list<type> {
public:
	Arraylist(int size = 10) : list<type>(size) {}

	void addElementAtFirstIndex(type element) override {
		if (currentSize >= maxSize) {
			cout << "List is full. Cannot add element ." << endl;
			return;
		}
		for (int i = currentSize; i > 0; --i) {
			arr[i] = arr[i - 1];
		}
		arr[0] = element;
		currentSize++;
	}

	void addElementAtLastIndex(type element) override {
		if (currentSize >= maxSize) {
			cout << "List full. No element ." << endl;
			return;
		}
		arr[currentSize] = element;
		currentSize++;
	}

	void removeElementFromStart() override {
		if (currentSize == 0) {
			cout << "List empty. No element to remove." << endl;
			return;
		}
		for (int i = 0; i < currentSize - 1; ++i) {
			arr[i] = arr[i + 1];
		}
		currentSize--;
	}
};

int main() {
	Arraylist<int> list;
	list.addElementAtLastIndex(10);
	list.addElementAtLastIndex(20);
	list.addElementAtFirstIndex(5);

	list.removeElementFromStart();

	
	cout << "Current elements in the list:" << endl;
	for (int i = 0; i < list.currentSize; ++i) {
		cout << list.arr[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
