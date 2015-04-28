#ifndef __PAYOFF_HPP__
#define __PAYOFF_HPP__

class PayOff {
public:
  PayOff();
  virtual ~PayOff();

  virtual double operator() (const double S) const = 0;
};

#endif