#pragma once


template <typename T, int N>
class Array
{
private:
  T* data;
public:
  Array();
  ~Array();
  Array(const Array&);

  T& operator[](const int& n);

  T* begin() const;
  T* end() const;
};
