/* Sample tester
 * We've included vector below to show you how your types should behave.
 * You can use that for debugging.
 * When implementing your list, you are expected to use the same names and declarations as defined by the STL implementation of an array list, the vector.
 * The vector you implement must be templated on the data type it stores.

In main (or multiple mains) you should write your own "unit tests" for each function;
I suggest 1 main per function.

The sample input and output are defined in terms of the behavior of the std::vector (which you must test yourself).

Background reading:

General container library
http://en.cppreference.com/w/cpp/container

Vector
http://en.cppreference.com/w/cpp/container/vector
(This wiki the most “official”, but still unofficial, source of C++ knowledge for end-programmers)

http://www.cplusplus.com/reference/vector/vector/
(This may also help, but if these links differ, go with en.cppreference.com instead)

Overloading operator syntax
https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B
*/

// USE THIS TO TEST, BUT REMOVE LATER
#include <vector>

/// Uncomment this:
#include "MyVector.h"

/* Sample main
 * Disclaimer: this file is not a unit test!
 * Just because it runs, does NOT mean your assignment is correct.
 * This file is for developing your own tests.
 * We've included vector below to show you how your types should behave.
 * You can use that for debugging.
 * When implementing your list, you are expected to use the same names and declarations as defined by the STL implementation of an array list, the vector.
 * The vector you implement must be templated on the data type it stores.

In main (or multiple mains) you should write your own "unit tests" for each function;
I suggest 1 main per function.

The sample input and output are defined in terms of the behavior of the std::vector (which you must test yourself).

Background reading:

General container library
http://en.cppreference.com/w/cpp/container

Vector
http://en.cppreference.com/w/cpp/container/vector
(This wiki the most “official”, but still unofficial, source of C++ knowledge for end-programmers)

http://www.cplusplus.com/reference/vector/vector/
(This may also help, but if these links differ, go with en.cppreference.com instead)

Overloading operator syntax
https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B
*/

// USE THIS TO TEST, BUT REMOVE LATER
#include <vector>

/// Uncomment this:
#include "MyVector.h"

int main()
{
    // Uncomment this
    MyVector<int> v;
    MyVector<int> b;
    //std::vector<int> v;

    cout << v.size() << endl;
    v.push_back(4000);
    cout << v.at(0) << endl;
    cout << v.capacity() << endl;
    v.reserve(10);
    cout << v.capacity() << endl;
    v.push_back(200);
    v.push_back(100);
    v.insert(v.begin(), 3);
    v.insert(v.end(), 20);
    b = v;
    // These below are tricky.
    // They look like iterators, but are really just integers.
    // We are not making you re-implement iterators themselves.
    int j = 0;

    for(auto i = v.begin(); i < v.end(); i++)
    {
        cout << v.at(j) << endl;
        j++;
    }

    j = 0;

    for(auto i = 0; i < v.size(); i++)
    {
        cout << v[j] << endl;
        j++;
    }

    return 0;

}
