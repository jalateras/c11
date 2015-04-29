/*******************************************************
 * Copyright (c) 2014, ArrayFire
 * All rights reserved.
 *
 * This file is distributed under 3-clause BSD license.
 * The complete license agreement can be obtained at:
 * http://arrayfire.com/licenses/BSD-3-Clause
 ********************************************************/

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <arrayfire.h>
#include <af/util.h>

using namespace af;
template<class ty> dtype get_dtype();

template<> dtype get_dtype<float>() { return f32; }
template<> dtype get_dtype<double>() { return f64; }

template<class ty, bool use_barrier>
static ty monte_carlo_barrier(int N, ty K, ty t, ty vol, ty r, ty strike, int steps, ty B, array randmat)
{
  dtype pres = get_dtype<ty>();
  array payoff = constant(0, N, 1, pres);

  ty dt = t / (ty)(steps - 1);
  array s = constant(strike, N, 1, pres);


  array S = product(join(1, s, randmat), 1);

  if (use_barrier) {
    S = S * alltrue(S < B, 1);
  }

  payoff = max(0.0, S - K);
  ty P = mean<ty>(payoff) * exp(-r * t);
  return P;
}

template<class ty, bool use_barrier>
double monte_carlo_bench(int N, array randmat)
{
  int steps = 180;
  ty stock_price = 100.0;
  ty maturity = 0.5;
  ty volatility = .30;
  ty rate = .01;
  ty strike = 100;
  ty barrier = 115.0;

  for (int i = 0; i < 10; i++) {
    monte_carlo_barrier<ty, use_barrier>(N, stock_price, maturity, volatility,
                                         rate, strike, steps, barrier, randmat);
  }

  return 1.0;
}

int main()
{
  try {
    int n = 1000;
    array randmat = randn(n, 180 - 1, f32);

    // Warm up and caching
    monte_carlo_bench<float, false>(1000, randmat);
    monte_carlo_bench<float, true>(1000, randmat);

    n = 30000;
    randmat = randn(n, 180 - 1, f32);

    double start = clock();
    double total;
    for (int idx = 0; idx < 100; idx++) {
      total += monte_carlo_bench<float, true>(n, randmat);
    }
    printf("Time to price 1000 options %4.3fsec\n", (clock() - start) / CLOCKS_PER_SEC);

  } catch (af::exception &ae) {
    std::cout << ae.what() << std::endl;
  }

  return 0;
}
