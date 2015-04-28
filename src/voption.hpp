#ifndef __VOPTION_HPP__
#define __VOPTION_HPP__

class VanillaOption {
private:
  // strike price
  double K;
  // risk-free rate
  double r;
  // maturity time
  double T;
  // underlying asset price
  double S;
  // volatility of the underlying asset
  double sigma;

  void init();
  void copy(const VanillaOption& rhs);

public:
  VanillaOption();
  VanillaOption(const double& _K, const double& _r, const double& _T, const double& _S, const double& _sigma);
  VanillaOption(const VanillaOption& rhs);

  VanillaOption& operator=(const VanillaOption& rhs);

  double getK() const;
  double getr() const;
  double getT() const;
  double getS() const;
  double getsigma() const;
  double calc_call_price() const;
  double calc_put_price() const;

  virtual ~VanillaOption();
};

#endif