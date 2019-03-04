/* Define all your MyVector-related functions here.
 * Also, define the swap function here.
 * You do not need to include the h file.
 * It included this file at the bottom.
 */
#include<cstdlib>

 void get_identity(string &my_id)
 {

     my_id = "jmr3by";


 }
template<typename T>
void swap(T & a,T &b)
{

    T temp = a;
    a = b;
    b = temp;

}


// We're giving you this one for free
// and as a guide for the syntax.
template <typename T>
MyVector<T>::~MyVector()
{
    delete[] m_data;
}

// Another example: remember when writing an implementation in hpp,
// return type first, then scope just before the function name.
// google how to trow out of range
template <typename T>
T & MyVector<T>::at(int index)
{

    if(!(index < size()))
    {

      throw std::out_of_range("Its alive !!!!!");
      
    }
    return m_data[index];

}


template <typename T>
MyVector<T>::MyVector()
{

    m_data = nullptr;
    reserved_size = 0;
    data_size =0;

}


template <typename T>
MyVector<T> & MyVector<T>::operator =(const MyVector<T> & source)
{

    if(reserved_size != source.reserved_size)
    {
        delete m_data;
        m_data = new T[reserved_size];

    }
    reserved_size = source.reserved_size;
    data_size = source.data_size;
    for(int i = 0;i<data_size;i++)
    {

        m_data[i] = source.m_data[i];

    }
    return *this;

}


template <typename T>
MyVector<T>::MyVector(const MyVector<T> & source)
{


   reserved_size = source.reserved_size;
   data_size = source.data_size;
   m_data = new T[reserved_size];
   for(int i = 0;i < data_size;i++)
   {

      m_data[i] = source.m_data[i];


   }

}


template <typename T>
T & MyVector<T>::front()
{


    return m_data[0];


}


template <typename T>
T & MyVector<T>::back()
{

    return m_data[data_size-1];

}

template <typename T>
int MyVector<T>::capacity()
{

    return reserved_size;

}

// question about resereve does this function need exceptions

template <typename T>
void MyVector<T>::reserve(int new_cap)
{

      if(new_cap > capacity())
      {
          T *store_data = new T[new_cap];

          for(int i =0;i<size();i++)
          {
              store_data[i] = m_data[i];

          }
          reserved_size = new_cap;
          delete m_data;
          m_data = store_data;

      }

}


template <typename T>
void MyVector<T>::push_back(const T &x)
{
    if(data_size>=reserved_size)
    {

        reserve(reserved_size+1);

    }
    m_data[data_size] = x;
    data_size++;

}


template <typename T>
void MyVector<T>::pop_back()
{

   data_size--;

}


template <typename T>
T & MyVector<T>::operator[](int index)
{

    return m_data[index];

}

template <typename T>
void MyVector<T>::insert(int i,const T & x)
{

    data_size = (data_size + 1);

    if(size() >= capacity())
    {

        reserve(reserved_size + 1);

    }
    for(int j = data_size;(j<=data_size) && (j>i);j--)
    {

          m_data[j] = m_data[j-1];

    }
    m_data[i] = x;

}


template <typename T>
int MyVector<T>::size()
{
    if(capacity() ==0 || data_size == 0)
    {

        return 0;

    }

    return (data_size);

}

template <typename T>
void MyVector<T>::shrink_to_fit()
{
    int new_capacity_size = 2* data_size;
    T *Pointer = new T[new_capacity_size];
    for(int i=0;i<size();i++)
    {

        Pointer[i] = m_data[i];

    }
    reserved_size = new_capacity_size;
    delete [] m_data;
    m_data = Pointer;


}

template <typename T>
void MyVector<T>::erase(int i)
{
    if(size()>0)
    {
        data_size--;

    }
    if((size())<(capacity())/(4))
    {
        shrink_to_fit();

    }
    for(int j = i;j < size();j++)
    {

        m_data[j] = m_data[j+1];

    }

}


template <typename T>
void MyVector<T>::clear()
{

    data_size=0;
    reserved_size = 0;
    delete m_data;
    m_data = nullptr;
}


template <typename T>
void MyVector<T>::assign(int count,const T &value)
{
    clear();
    m_data = new T[count];
    reserved_size = count;
    data_size = count;
    for(int i =0;i<size();i++)
    {
        m_data[i] = value;

    }




}
