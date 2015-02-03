#include "complexNumber.h"
#include <cstring>
#include <string.h>
#include <stdio.h>

ComplexNumber::ComplexNumber(double rr, double ii) : r(rr), i(ii) {
}

//turn str into seperate parts and make it a ComNum 
//*str is an array
ComplexNumber::ComplexNumber(char * str){
    char bloop[100];
    char *punch;
    strcpy(bloop, str);
    punch = strtok(bloop, "+-");
   while (punch != NULL)
   {
        cout << punch << "then" << endl;
        punch = strtok(NULL, " ");
   } 
cout << endl;
	  
}


ComplexNumber operator+ (const ComplexNumber &a, const ComplexNumber &b) {
	ComplexNumber result;

	result.r = a.r + b.r;
	result.i = a.i + b.i;

	return result;
}

ComplexNumber operator- (const ComplexNumber &a, const ComplexNumber &b) {
	ComplexNumber result;

	result.r = a.r - b.r;
	result.i = a.i - b.i;

	return result;
}

ComplexNumber operator* (const ComplexNumber &a, const ComplexNumber &b) {
	ComplexNumber result;

	result.r = (a.r * b.r - a.i * b.i);
	result.i = (a.r * b.i + a.i * b.r);

	return result;
}

ComplexNumber operator/ (const ComplexNumber &a, const ComplexNumber &b) {
	ComplexNumber result;

	result.r = (a.r * b.r + a.i * b.i) / (b.r * b.r + b.i * b.i);
	result.i = (a.i * b.r - a.r * b.i) / (b.r * b.r + b.i * b.i);

	return result;
}

istream&  operator>>(istream &in, ComplexNumber &c) {

in >> c;
return in;

}
//change back
ostream& operator<< (ostream &out, const ComplexNumber &c) {
	
	return out;
}
