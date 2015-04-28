/*******************************************************
 * Copyright (c) 2014, ArrayFire
 * All rights reserved.
 *
 * This file is distributed under 3-clause BSD license.
 * The complete license agreement can be obtained at:
 * http://arrayfire.com/licenses/BSD-3-Clause
 ********************************************************/

#include <arrayfire.h>
#include <af/util.h>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <cstdarg>
#include <algorithm>
#include <iostream>

using namespace std;
using namespace af;

template<typename T>
af::array add(af::array a, T num) {
  printf("%p\n", &a);
  return a + num;
}

af::array square_root(af::array a) {
  printf("%p\n", &a);
  return sqrt(a);
}


template<typename T>
af::array evaluate(const char* expr, vector<T>& args) {
  return add(args[0], args[1]);
}

int main(int argc, char ** argv) {
  try {
    int device = argc > 1 ? atoi(argv[1]) : 0;
    deviceset(device);
    info();

    timer::start();
    af::array A = randu(2, f32);
    af_print(A);
    af::array B = randu(2, f32);
    af_print(B);


//    af::array C = add(square_root(add(A, 1)), B);
//    af::array C = sqrt((A + 1) + B);
//    C.eval();
//    af_print(A);
//    af_print(B);
//    af_print(C);

    vector<af::array> args = {A, B};
    af::array C = evaluate("A0 + A1", args);
    af_print(C);
    printf("Time to execute %4.3f ms\n", timer::stop() / 10);
  } catch (af::exception& e) {
    fprintf(stderr, "%s\n", e.what());
  }

//  std::vector<double> A(10);
//  std::vector<double> B(10);
//  std::generate(A.begin(), A.end(), std::rand);
//  std::generate(B.begin(), B.end(), std::rand);
//
//  vector<std::vector<double> > args = {A, B};
//  af::array C = evaluate("A0 + A1", args);
//  af_print(C);
  return 0;
}
