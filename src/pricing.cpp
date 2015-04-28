#include <iostream>

using namespace std;

int main() {
  double total = 0;
  double start_time = clock()/CLOCKS_PER_SEC;
  for (int i = 0; i < 1000000; i++) {
    total += i * 1;
  }
  double end_time = clock()/CLOCKS_PER_SEC;
  cout << "Elapsed Time: " << end_time - start_time << endl;

}
