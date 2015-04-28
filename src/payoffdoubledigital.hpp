#ifndef __PAYOFFDOUBLEDIGITAL_HPP__
#define __PAYOFFDOUBLEDIGITAL_HPP__

#include "payoff.hpp"

class PayOffDoubleDigital : public PayOff {
private:
  double U;
  double D;

public:
  PayOffDoubleDigital(const double _U, const double _D);
  virtual ~PayOffDoubleDigital();

  virtual double operator() (const double S);
};

#endif