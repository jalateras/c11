#include <iostream>
#include <limits>
#include <arrayfire.h>

using namespace std;
using namespace af;

static int N = 10e6;

static int comp(const void * elem1, const void * elem2) {
  int f = *((int*)elem1);
  int s = *((int*)elem2);
  if (f > s) return  1;
  if (f < s) return -1;
  return 0;
}

static void sortOnDevice(af::array x) {
  af::array vals;
  af::array inds;
  af::sort(vals, inds, x);
}

static void sortOnHost(int* data) {
  qsort(data, N, sizeof(int), comp);
}

static void device_wrapper() {
  int* data = (int *)malloc(sizeof(int) * N);
  for (int i = 0; i < N; i++) {
    data[i] = int(rand() * 2147483647);
  }

  af::array ddata(N, 1, data);
  sortOnDevice(ddata);
  free(data);
}

static void host_wrapper() {
  int* data = (int *)malloc(sizeof(int) * N);
  for (int i = 0; i < N; i++) {
    data[i] = int(rand() * 2147483647);
  }
  sortOnHost(data);

  free(data);
}

int main() {
  af::deviceset(0);
  af::info();

  printf("  host:  %.5f seconds to sort %d elements\n", timeit(host_wrapper), N);
  printf("device:  %.5f seconds to sort %d elements\n", timeit(device_wrapper), N);
}