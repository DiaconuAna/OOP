//
// Created by amina on 3/26/2021.
//
#pragma once

template<typename T>
class DynamicVectorTemplated {
private:
    T* elements;
    int nrElems;
    int capacity;

public:
    //constructor
    explicit DynamicVectorTemplated(int capacity = 2);

    //resize
    void resize();

    //assignment operator
    DynamicVectorTemplated& operator=(const DynamicVectorTemplated& dv);

    T& operator[](int index);

    //copy constructor
    DynamicVectorTemplated(const DynamicVectorTemplated &dv);

    //destructor
    ~DynamicVectorTemplated();

    //returns the length
    int length();

    //add a new movie/object
    void add(T type);

    /**
     * Remove an object from the given position in the list
     * @param type
     * @param position
     */
    void remove(T type, int position);

    /**
     * Update an object in the list
     * @param position
     * @param updated_type
     */
    void update(int position, T updated_type);

    /**
     * Gets an element from the list
     * @param mov
     * @return 1 if it exists,else 0
     */
    T getItem(int position);

};



template <typename T>
DynamicVectorTemplated<T>::DynamicVectorTemplated(int capacity) {
    this -> capacity = capacity;
    this -> elements = new T[this->capacity];
    this -> nrElems = 0;
}

template <typename T>
void DynamicVectorTemplated<T>::resize() {
    T* newArray;
    newArray = new T[this->capacity*2];

    for (int i=0;i<this->capacity;i++){
        newArray[i] = this->elements[i];
    }

    delete[] this->elements;
    this->elements = newArray;
    this->capacity *= 2;
}

template <typename T>
DynamicVectorTemplated<T> &DynamicVectorTemplated<T>::operator=(const DynamicVectorTemplated<T> &dv) {
    this ->capacity = dv.capacity;
    this ->nrElems = dv.nrElems;

    for (int i=0;i<dv.nrElems;i++)
        this->elements[i] = dv.elements[i];

    //TODO:review this
    return *this;
    //return DynamicVectorTemplated<T>(1);
}

template<typename T>
T &DynamicVectorTemplated<T>::operator[](int index) {

    if (index >= this->nrElems){
        throw "\n Invalid index - out of bounds! \n";
    }
    return this->elements[index];
}

template<typename T>
DynamicVectorTemplated<T>::DynamicVectorTemplated(const DynamicVectorTemplated<T> &dv) {
    this ->capacity = dv.capacity;
    this ->nrElems = dv.nrElems;
    this ->elements = new T[5];
    for (int i=0;i<dv.nrElems;i++)
        this->elements[i] = dv.elements[i];
}

template<typename T>
void DynamicVectorTemplated<T>::update(int position, T updated_type) {
    this->elements[position] = updated_type;
}

template<typename T>
DynamicVectorTemplated<T>::~DynamicVectorTemplated() {
    delete[] this->elements;
}

template<typename T>
int DynamicVectorTemplated<T>::length() {
    return this->nrElems;
}

template<typename T>
void DynamicVectorTemplated<T>::add(T type) {
    if (this->nrElems == this ->capacity)
        this -> resize();
    this->elements[this->nrElems] = type;
    this->nrElems ++;
}

template<typename T>
void DynamicVectorTemplated<T>::remove(T type, int position) {
//    int position;
//    position = this->search(type);
//    if (position == -1)
//        return;
    this -> elements[position] = this -> elements[nrElems - 1];
    nrElems --;
}

template<typename T>
T DynamicVectorTemplated<T>::getItem(int position) {
    return this->elements[position];
}


