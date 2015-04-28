#ifndef __PAYOFFCALL_HPP__
#define __PAYOFFCALL_HPP__

#include "payoff.hpp"

class PayOffCall : public PayOff {
private:
  double K;

public:
  PayOffCall();
  virtual ~PayOffCall();

  virtual double operator() (const double S);
};

#endif