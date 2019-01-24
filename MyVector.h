/*
 * Simplified version of the std::vector
 * This is your h file. Do not edit it!
 */

#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <stdexcept>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::string;

/*
Writes to a string array containing:
    * the your (the student author’s) Campus Username (at index 0)
    * and Student ID# (at index 1).
Takes as input a pre-existing length-2 string array.
*/
void get_identity(string my_id[]);


// Purpose: Swaps two elements (including a vector).
// Parameters: a, b: the list elements themselves to be swapped
// Note: a and b can be any parameters, and just happen to be list this time.
// e.g., swap(list_obj[2], list_obj[1]);
// This one is similar to std::swap (you can check it's behavior).
// This is not a list function, but a general one.
template <typename T>
void swap(T &a, T &b);


template <typename T>
class MyVector
{
    private:
        T *m_data;
        int reserved_size;
        int data_size;

    public:
        // Should default array pointer to nullptr, and do all the stuff a constructor does.
        // Just a simple default constructor.
        MyVector();

        ~MyVector();

        // Make sure this does a deep copy.
        MyVector<T> & operator=(const MyVector<T> &source);

        // Make sure this does a deep copy
        MyVector(const MyVector<T> &source);

        // Returns the element of the array by reference, so it can be read or written.
        T & operator[](int i);

        // Purpose: Returns the element stored at the index by reference
        // Parameters: index - The location of the element to be returned.
        // This one should throw an std::out_of_range exception when out-of-bounds
        T & at(int index);

        // Purpose: Returns the element stored at the front of the vector
        T & front();

        // Purpose: Returns the element stored at the back of the vector
        T & back();

        // Purpose: Returns the maximum number of elements that can be stored in the current Vector
        int capacity();

        // Purpose: Ensures that there is enough room for a specific number of elements
        // Parameters: new_cap - The amount of space to be reserved in the array.
        // Postconditions: Increases max_size to new_cap if new_cap > max_size
        // Other functions should check that their operations are not going beyond the size limit,
        // and call this one if so
        // By default, you should double the size of the current array when it fills up.
        // NOTE: reserve does not do the checking of whether it's full; another function should do that, and then call reserve, which just adjusts the size to whatever it is called with, only if it is greater than current.
        // Inital size is 0, so a special case is needed to grow to 1, then 2, 4, etc.,
        void reserve(int new_cap);

        // If your array hits the point at which it is less than (not <=) 1/4 full, it should call this function.
        // It should shrink such that the array is 2x as big as the data.
        // NOTE: shrink_to_fit does not do the checking of 1/4 full; another function should do that, and then call shrink_to_fit.
        void shrink_to_fit();

        // Fills the array with count of T value (e.g., 5 a would be [a, a, a, a, a])
        // This replaces the current array.
        void assign(int count, const T &value);

        // Purpose: Clears the MyVector
        // Postconditions: current size set to 0, storage size to default (0).
        //                 elements are deallocated and data is set to nullptr
        void clear();

        // Purpose: appends the value x to the end of an MyVector
        // Parameters: x is value to be added to MyVector
        // Postconditions: current size is incremented by 1
        //     If max size is reached, the storage array is grown.
        void push_back(const T &x);

        // Removes the last element of the vector
        void pop_back();

        // Purpose: inserts the value x at the position i 
        //     (before the value currently at i) in the  MyVector
        // Parameters: x is value to be added to MyVector
        //             i is the position to insert x at
        // Postconditions: current size is incremented by 1
        //     If max size is reached, the storage array is grown.
        void insert(int i, const T &x);

        // Purpose: Removes the element at index i in the array
        // Parameters: i, the index of the element to remove
        // Postconditions: if the size of the list is greater than 0
        //     size is decremented by one.
        //     if the size of the list less than 1/4 the max size,
        //     the storage array is shrunk.
        void erase(int i);

        // Returns the size of the actual data stored in the array list
        // Remember, with indexing at 0, this is 1 more than the last elements position index
        int size();

        // This is designed to partially mimic the behavior of iterators.
        int begin()
        {
            return 0;
        }

        int end()
        {
            return size();
        }
};


// We're giving you this one.
// This relies on you having implemented the .at() and .size() member functions first.
// It may be a good idea to get those working, so you can test with this.
template <typename T>
std::ostream & operator<<(std::ostream &out, MyVector<T> &my_list)
{
    out << "[ ";

    for(int i = 0; i < my_list.size(); i++)
    {
        out << my_list.at(i) << ", ";
    }

    out << "]";

    return out;
}


#include "MyVector.hpp"

#endif

