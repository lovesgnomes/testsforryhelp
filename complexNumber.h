#ifndef COMPLEX_NUMBER
#define COMPLEX_NUMBER

#include <iostream>
using namespace std;

class ComplexNumber {
 public:
   ComplexNumber(double real = 0.0, double imag = 0.0);
   ComplexNumber(char * str);
   friend ComplexNumber operator+ (const ComplexNumber &a, const ComplexNumber &b);
   friend ComplexNumber operator- (const ComplexNumber &a, const ComplexNumber &b);
   friend ComplexNumber operator* (const ComplexNumber &a, const ComplexNumber &b);
   friend ComplexNumber operator/ (const ComplexNumber &a, const ComplexNumber &b);
   
   friend istream &operator >> (istream &in,  ComplexNumber &c);
   friend ostream&      operator<<(ostream &out,           const ComplexNumber &c);

 private:
	float r;
	float i;
};

#endif  // COMPLEX_NUMBER
