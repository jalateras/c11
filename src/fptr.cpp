#include <iostream>

using namespace std;

template<typename T>
T add(const T& lhs, const T& rhs) {
  return lhs + rhs;
}

template<typename T>
T subtract(const T& lhs, const T& rhs) {
  return lhs - rhs;
}

template<typename T>
T binary_op(const T& lhs, const T& rhs, T (*func)(const T&, const T&)) {
  return func(lhs, rhs);
}

int main() {
  cout << binary_op(1.12, 2.0, add) << endl;
  cout << binary_op(1, 2, subtract) << endl;

  double vals[] = {1, 2, 3};
  double ptr = double(long(&vals[0]));

  cout << ((double*)ptr)[1] << endl;
}
