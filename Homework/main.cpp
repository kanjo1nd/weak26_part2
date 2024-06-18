#include <iostream>
using namespace std;

template<class T>
class Array {
	T* mas;
	int size;
	int quantity;
	int grow;
public:
	Array(int initialSize = 0, int grow = 1) : size(initialSize), quantity(initialSize), grow(grow) {
		if (quantity > 0) {
			mas = new T[size];
		}
		else {
			mas = nullptr;
		}
	}
	int GetSize() const {
		return quantity;
	}
	void SetSize(int length, int grow = 1) {
		this->grow = grow;
		if (length > size) {
			T* temp = new T[length];
			for (int i = 0; i < quantity; i++) {
				temp[i] = mas[i];
			}
			delete[] mas;
			size = length;
			mas = temp;
		}
		else if (length < quantity) {
			quantity = length;
		}
		quantity = length;
	}
	int GetUpperBound() const {
		return quantity - 1;
	}
	bool IsEmpty() const {
		if (quantity > 0) {
			return true;
		}
		else {
			return false;
		}
	}
	void FreeExtra() {
		if (size < quantity) {
			T* temp = new T[size];
			for (int i = 0; i < size; i++) {
				temp[i] = mas[i];
			}
			delete[] mas;
			quantity = size;
			mas = temp;
		}
	}
	void RemoveAll() {
		delete[] mas;
		mas = nullptr;
		size = 0;
		quantity = 0;
	}
	T GetAt(int index) const {
		if (index >= size || index < 0) {
			cout << "Index out of range";
		}
		return mas[index];
	}
	void SetAt(int index, const T& value) {
		if (index >= size || index < 0) {
			cout << "Index out of range";
		}
		mas[index] = value;
	}
	T& operator[](int index) {
		if (index >= size || index < 0) {
			cout << "Index out of range";
		}
		return mas[index];
	}
	void Add(const T& value) {
		if (size <= quantity) {
			T* temp = new T[size + grow];
			for (int i = 0; i < quantity; i++) {
				temp[i] = mas[i];
			}
			delete[] mas;
			size = size + grow;
			mas = temp;
		}
		mas[quantity++] = value;
	}
	void Append(const Array<T>& other) {
		for (int i = 0; i < other.quantity; i++) {
			Add(other.mas[i]);
		}
	}
	~Array() {
		delete[] mas;
	}
	Array<T>& operator=(const Array<T>& other) {
		if (this == &other) {
			return *this;
		}
		delete[] mas;
		size = other.size;
		quantity = other.quantity;
		grow = other.grow;
		mas = new T[quantity];
		for (int i = 0; i < size; i++) {
			mas[i] = other.mas[i];
		}
		return *this;
	}
	T* GetData() const {
		return mas;
	}

	void InsertAt(int index, const T& value) {
		if (index > quantity || index < 0) {
			cout << "Index out of range";
		}
		if (quantity >= size) {
			T* temp = new T[size + grow];
			for (int i = 0; i < quantity; i++) {
				temp[i] = mas[i];
			}
			delete[] mas;
			size = size + grow;
			mas = temp;
		}
		for (int i = quantity; i > index; i--) {
			mas[i] = mas[i - 1];
		}
		mas[index] = value;
		++quantity;
	}

	void RemoveAt(int index) {
		if (index >= quantity || index < 0) {
			cout << "Index out of range";
		}
		for (int i = index; i < quantity - 1; i++) {
			mas[i] = mas[i + 1];
		}
		--quantity;
	}
};

int main() {
	Array<int> arr(0, 3);
	arr.Add(1);
	arr.Add(2);
	arr.Add(3);
	arr.Add(4);
	arr.Add(5);

	for (int i = 0; i < arr.GetSize(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	arr.InsertAt(2, 99);

	for (int i = 0; i < arr.GetSize(); ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;

	arr.RemoveAt(2);

	for (int i = 0; i < arr.GetSize(); ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}