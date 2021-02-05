#pragma once
//156
template<typename T>

class DynamicArray{
private:
	unsigned nrOfElem;
	unsigned capacity;
	unsigned initialCap;
	T** arr;

	void expand();
	void initialize(unsigned from);
public:
	DynamicArray(unsigned size = 5);
	DynamicArray(const DynamicArray& obj);
	~DynamicArray();

	T& operator[] (const unsigned index);
	void operator= (const DynamicArray& obj);

	unsigned maxCapacity();
	unsigned size();
	void push(const T element);
	void remowe(const unsigned index, bool ordered = false);

};

template<typename T>
DynamicArray<T>::DynamicArray(unsigned size) {
	this->initialCap = size;
	this->capacity = size;
	this->nrOfElem = 0;
	
	this->arr = new T * [this->capacity];
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& obj){
	this->initialCap = obj.itinialCal;
	this->capacity = obj.capacity;
	this->nrOfElem = obj.nrOfElem;

	this->arr = new T * [this->capacity];

	for (int i = 0; i < this->nrOfElem; i++) {
		this->arr[i] = new T(*obj.arr[i]);
	}
}

template<typename T>
DynamicArray<T>::~DynamicArray(){
	for (unsigned int i = 0; i < this->nrOfElem; i++){
		delete this->arr[i];
	}
	delete[] arr;
}

template<typename T>
T& DynamicArray<T>::operator[] (const unsigned index) {
	if (index < 0 || index >= this->nrOfElem){
		throw "Out of bounds indexing operator.";
	}
	return *this->arr[index];
}

template<typename T>
void DynamicArray<T>::operator= (const DynamicArray& obj) {
	
	for (int i = 0; i < nrOfElem; i++) {
		delete this->arr[i];
	}
	delete[] arr;

	this->initialCap = obj.itinialCal;
	this->capacity = obj.capacity;
	this->nrOfElem = obj.nrOfElem;

	this->arr = new T * [this->capacity];

	for (int i = 0; i < this->nrOfElem; i++) {
		this->arr[i] = new T(*obj.arr[i]);
	}
}


template<typename T>
void DynamicArray<T>::expand(){
	this->capacity += 1;
	T* *tempArr = new T*[this->capacity];

	for (int i = 0; i < this->nrOfElem; i++) {
		tempArr[i] = this->arr[i];
	}

	delete[]arr;

	this->arr = tempArr;
	this->initialize(this->nrOfElem);
}
template<typename T>
void DynamicArray<T>::initialize(unsigned from) {
	for (size_t i = from; i < capacity; i++)
	{
		this->arr[i] = nullptr;
	}
}


template<typename T>
unsigned DynamicArray<T>::maxCapacity() {
	return this->capacity;
}

template<typename T>
unsigned DynamicArray<T>::size() {
	return this->nrOfElem;
}

template<typename T>
void DynamicArray<T>::push(const T element) {
	if (this->nrOfElem >= this->capacity)
		this->expand();

	this->arr[this->nrOfElem++] = new T(element);
}

template<typename T>
void DynamicArray<T>::remowe(const unsigned index, bool ordered) {
	if (index < 0 || index >= this->nrOfElem)
		throw("Index poza zasiegiem!");
	if (ordered) {
		delete this->arr[index];

		for (int i = 0; i < nrOfElem-1; i++){
			this->arr[i] = this->arr[i + 1];
		}
		this->arr[--this->nrOfElem] = nullptr;
	}
	else {
		delete this->arr[index];

		this->arr[index] = this->arr[this->nrOfElem - 1];
		this->arr[--this->nrOfElem] = nullptr; 
	}
}