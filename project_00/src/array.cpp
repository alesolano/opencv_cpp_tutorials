#include "array.hpp"

template <typename T, int N>
Array<T, N>::Array()
{
  data = new T[N];
}

template <typename T, int N>
Array<T, N>::~Array()
{
  delete[] data;
}

template <typename T, int N>
Array<T, N>::Array(const Array& a)
{
  data = a->data;
}

template <typename T, int N>
T& Array<T, N>::operator[](const int& n)
{
  return data[n];
}

template <typename T, int N>
T* Array<T, N>::begin() const
{
  return data;
}

template <typename T, int N>
T* Array<T, N>::end() const
{
  return data + N-1;
}
