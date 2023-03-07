#pragma once
#include "Event.h"
#include "vector"

//typedef Event TElement;

template <typename TElement>
class DynamicVector
{
private:
//    TElement* elems;
//    int size;
//    int capacity;
std::vector<TElement> elems;

public:
    // default constructor for a DynamicVector
    DynamicVector(int capacity = 10)  ;

    // copy constructor for a DynamicVector
    DynamicVector(const DynamicVector& v);
    ~DynamicVector();

    // assignment operator for a DynamicVector
    DynamicVector& operator=(const DynamicVector& v);

    // Adds an element to the current DynamicVector.
    void add_element(const TElement& e);

    //Deletes an element from the current DynamicVector.
    void delete_element(const TElement& e);

    //Finds an element and returns its position in the DynamicVector.
    int position_element(const TElement& e);

    //Updates an element
    void update_element(const TElement& e, const TElement& new_e);

    //Gets an element from the position
    TElement get_element_from_position(int position) const;

    int get_size() const;


    TElement get_element(int i) const;
    //std::vector<TElement> get_all_elems() const;

    /*
    DynamicVector& operator+(const TElement& e);

    friend DynamicVector operator+(const TElement& e,const DynamicVector& v)
    {
        DynamicVector temp = v;
        temp.add_element(e);
        return temp;
    }

    friend DynamicVector operator+(const DynamicVector& v, const TElement& e);
     */

private:
    // Resizes the current DynamicVector, multiplying its capacity by a given factor (real number).
    void resize(double factor = 2);
};










#include "DynamicVector.h"



template <typename TElement>
DynamicVector<TElement>::DynamicVector( int capacity)
{
//    this->size = v.size;
//    this->capacity = v.capacity;
//    this->elems = new TElement[this->capacity];
//    for (int i = 0; i < this->size; i++)
//        this->elems[i] = v.elems[i];


}



template <typename TElement>
DynamicVector<TElement>::DynamicVector(const DynamicVector<TElement>& v)
{
//    this->size = v.size;
//    this->capacity = v.capacity;
//    this->elems = new TElement[this->capacity];
//    for (int i = 0; i < this->size; i++)
//        this->elems[i] = v.elems[i];
this->elems = v.elems;

}

template <typename TElement>
DynamicVector<TElement>::~DynamicVector()
{
    this->elems.clear();
}

template <typename TElement>
DynamicVector<TElement>& DynamicVector<TElement>::operator=(const DynamicVector<TElement>& v)
{
    if (this == &v)
        return *this;

    this->elems.clear();
    //this->elems.size() = v.elems.size();
    //this->capacity = v.capacity;

    //delete[] this->elems;
    //this->elems = new TElement[this->capacity];
    //for (int i = 0; i != v.elems.size(); i++)
    int i =0;
    for (auto e: this->elems) {
        this->elems.push_back(v.elems[i]);
    i++;
    }

    return *this;
}

template <typename TElement>
void DynamicVector<TElement>::add_element(const TElement& e)
{
    int position = position_element(e);
    if(position==-1)
    {
//        if (this->elems.size() == this->capacity)
//            this->resize();
        this->elems.push_back(e);
        //this->size++;
    }
}

template <typename TElement>
TElement DynamicVector<TElement>::get_element(int i) const {
    return this->elems[i];
}

//template <typename TElement>
//void DynamicVector<TElement>::resize(double factor)
//{
//    this->capacity *= static_cast<int>(factor);
//
//    TElement* els = new TElement[this->capacity];
//    for (int i = 0; i < this->size; i++)
//        els[i] = this->elems[i];
//
//    delete[] this->elems;
//    this->elems = els;
//}

//template <typename TElement>
//std::vector<TElement> DynamicVector<TElement>::get_all_elems() const
//{
//    //for(auto i = this->elems.front(); i!= this->elems.back(); i++)
//      return this->elems;
//}

template <typename TElement>
int DynamicVector<TElement>::get_size() const
{
    return this->elems.size();
}

template <typename TElement>
void DynamicVector<TElement>::delete_element(const TElement &e) {
    int position = position_element(e);
    if (position!=-1)
    {
        //this->elems.erase(position);
//
        this->elems[position]=  this->elems[this->get_size()-1];
        this->elems.pop_back();


//        for (auto i=position; i<this->get_size()-1;i++)
//            this->elems[i] = this->elems[i+1];
//        this->size--;
    }
}

template <typename TElement>
int DynamicVector<TElement>::position_element(const TElement &e) {
    //for (int i=0;i<this->get_size();i++)
    int i = 0;
    for (auto v :this->elems ) {
        if ((TElement) e == v)
            return i;
        i++;
    }
    return -1;
}

template <typename TElement>
void DynamicVector<TElement>::update_element(const TElement &e, const TElement& new_e) {
    int position = position_element(e);
    if(position!=-1)
    {
        this->elems[position] = new_e;
    }
}

template <typename TElement>
TElement DynamicVector<TElement>::get_element_from_position(int position) const {
    return elems[position];
}












/*
DynamicVector operator+(const TElement& e,const DynamicVector& v)
{
    DynamicVector temp = v;
    temp.add_element(e);
    return temp;
}


DynamicVector operator+(const DynamicVector& v, const TElement& e)
{
    DynamicVector temp = v;
    temp.add_element(e);
    return temp;
}
 */


//#pragma once
//#include "Event.h"
//
//typedef Event TElement;
//
//class DynamicVector
//{
//private:
//    TElement* elems;
//    int size;
//    int capacity;
//
//public:
//    // default constructor for a DynamicVector
//    DynamicVector(int capacity = 10);
//
//    // copy constructor for a DynamicVector
//    DynamicVector(const DynamicVector& v);
//    ~DynamicVector();
//
//    // assignment operator for a DynamicVector
//    DynamicVector& operator=(const DynamicVector& v);
//
//    // Adds an element to the current DynamicVector.
//    void add_element(const TElement& e);
//
//    //Deletes an element from the current DynamicVector.
//    void delete_element(const TElement& e);
//
//    //Finds an element and returns its position in the DynamicVector.
//    int position_element(const TElement& e);
//
//    //Updates an element
//    void update_element(const TElement& e, const TElement& new_e);
//
//    //Gets an element from the position
//    //TElement get_element_from_position(int position) const;
//
//    int get_size() const;
//    TElement* get_all_elems() const;
//
//    //LABORATORY WORK!
//    DynamicVector& operator+( const TElement &e);
//
//    //TElement& operator+(const DynamicVector& v);
//private:
//    // Resizes the current DynamicVector, multiplying its capacity by a given factor (real number).
//    void resize(double factor = 2);
//};
//DynamicVector operator+(const TElement& e, DynamicVector& v );