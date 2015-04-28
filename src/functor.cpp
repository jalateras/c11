#include <iostream>

using namespace std;

template<typename T = double>
class BinaryFunction {
public:
  BinaryFunction() {
  }

  virtual T operator()(const T& lhs, const T& rhs) = 0;
};

template<typename T = double>
class AddFunction : public BinaryFunction<T> {
public:
  AddFunction() { }

  virtual T operator()(const T& lhs, const T& rhs) {
    return lhs + rhs;
  }
};


template<typename T = double>
class SubtractFunction : public BinaryFunction<T> {
public:
  SubtractFunction() { }
  virtual T operator()(const T& lhs, const T& rhs) {
    return lhs - rhs;
  }
};

template<typename T = double>
T binary_op(const T& lhs, const T& rhs, BinaryFunction<T>* func) {
  return (*func)(lhs, rhs);
}


int main() {
  cout << binary_op<long>(1, 2, new AddFunction<long>()) << endl;
  cout << binary_op<long>(1, 2, new SubtractFunction<long>()) << endl;
}
