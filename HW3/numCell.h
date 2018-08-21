
//numCell.h
#ifndef numCELL
#define numCELL

#include <stdio.h>
#include <string>

using namespace std;

/* A class for storing and manipulating integers */
template <class T>

class numCell
{
private:
    T storedValue;
    
public:
    numCell();                                // constructor
    numCell(T initialValue);                  // constructor
    T read();                                 // return the content of the cell
    void write(T value);                      // write value to cell
    numCell& swap (numCell& otherCell);       // swap the contents of this cell with another
    numCell& operator=(numCell& otherCell);   // copy constructor
    numCell& operator+(numCell& otherCell);   // return the sum of this and otherCell
};
#endif /* numCell_hpp */



/*template <class T>
 numCell<T>::numCell()
 {
 storedValue = 0;
 }*/

//created 2 different default constructors
template <>
numCell<int>::numCell()
{
    storedValue=0;
}

template <>
numCell<string>::numCell()
{
    storedValue= "";
}


template <class T>
numCell<T>::numCell(T initialValue)
{
    storedValue = initialValue;
}

template <class T>
T numCell<T>::read()
{
    return storedValue;
}

template <class T>
void numCell<T>::write(T value)
{
    storedValue = value;
}

template <class T>
numCell<T>& numCell<T>::swap(numCell& otherCell)
{
    T tmp = this->read();
    write(otherCell.read());
    otherCell.write(tmp);
    return *this;
}

template <class T>
numCell<T>& numCell<T>::operator=(numCell& otherCell)
{
    write(otherCell.read());
    return *this;
}

template <class T>
numCell<T>& numCell<T>::operator+(numCell& otherCell)
{
    
    numCell *result = new numCell();
    result->write(otherCell.read() + this->read());
    return *result;
}

