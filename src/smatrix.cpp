#ifndef __SMATRIX_CPP__
#define __SMATRIX_CPP__

#include <iostream>
#include "smatrix.hpp"

using namespace std;

template<typename T>
SimpleMatrix<T>::SimpleMatrix() {
}

template<typename T>
SimpleMatrix<T>::SimpleMatrix(const int& rows, const int& cols, T const& val) {
  for(int i = 0; i < rows; i++) {
    vector<T> col(cols, val);
    matrix.push_back(col);
  }
}

template<typename T>
SimpleMatrix<T>::SimpleMatrix(const SimpleMatrix<T>& rhs) {
  matrix = rhs.getMatrix();
}

template<typename T>
SimpleMatrix<T>::~SimpleMatrix() {
}

template<typename T>
SimpleMatrix<T> &SimpleMatrix<T>::operator=(const SimpleMatrix<T> &rhs) {
  if (this == rhs) {
    return *this;
  }

  this->matrix = rhs.getMatrix();
  return *this;
}

template<typename T>
vector <vector<T>> SimpleMatrix<T>::getMatrix() const {
  return matrix;
}

template<typename T>
T &SimpleMatrix<T>::value(const int &row, const int &col) {
  return matrix[row][col];
}

#endif


int main() {
  SimpleMatrix<int> matrix(2, 2, 3);

  cout << matrix.value(0, 0) << endl;
  cout << matrix.value(1, 0) << endl;
}
