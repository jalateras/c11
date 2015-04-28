#ifndef __SMATRIX_HPP__
#define __SMATRIX_HPP__

#include <vector>

using namespace std;

template<typename T = double>
class SimpleMatrix {
private:
  vector<vector<T> > matrix;

public:
  SimpleMatrix();
  SimpleMatrix(const int& rows, const int& cols, const T& val);
  SimpleMatrix(const SimpleMatrix<T>& rhs);
  virtual ~SimpleMatrix();

  SimpleMatrix<T>& operator=(const SimpleMatrix<T>& rhs);
  vector<vector<T> > getMatrix() const;
  T& value(const int& row, const int& col);
};
#endif
