#include <iostream>

using namespace std;

template<typename T>
void f1(T& param) {
  cout << param << " " << &param  << endl;
}

template<typename T, std::size_t N>
constexpr std::size_t arraySize(T (&)[N]) noexcept {
  return N;
}

const char* modify(const char* ptr) {
  ptr = "New one";

  return ptr;
}

void exercise3() {
  int x = 27;
  const int cx = x;
  const int& rx = x;
  const char* const ptr = "Fun with pointers";
  f1(x);
  f1(cx);
  f1(rx);
  f1(ptr);

  const char* val = "Old one";
  val = "New one";
  cout << modify(val) << endl;
}

void exercise4() {
  const char name[] = "Jim Alateras!!";

  cout << name << " " << &name  << endl;
  f1(name);

  cout << arraySize(name) << endl;

  int keyVals[] = {1, 3, 7, 9, 11, 22, 35};
  int mappedVals[arraySize(keyVals)];

//  std::array<int, 7> mappedVals2;
}

//template<typename T>
//T add(const T& a, const T&  b) {
//  return a + b;
//}

int add(const int& a, const int&  b) {
  return a + b;
}

template<typename T>
void exec (const T& param) {
  cout << param(6, 6) << endl;
}

void exercise5() {
  exec(add);
}

void exercise6() {
  int theAnswer = 42;

  auto x = theAnswer;
  auto y = &theAnswer;

  cout << x << " " << y << endl;
  cout << typeid(x).name() << " " << typeid(y).name() << endl;
}

int main() {
  exercise6();
  return 0;
}