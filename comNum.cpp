#include "complexNumber.h"
#include <cstring>
#include <string.h>
#include <stdio.h>
#include <cstdlib>

ComplexNumber::ComplexNumber(double rr, double ii) : r(rr), i(ii) {
}

//turn str into seperate parts and make it a ComNum 
//*str is an array
ComplexNumber::ComplexNumber(const char * str){
  //this size is wrong, and idk why
    cout <<  "size" << sizeof(str) << endl;
    char bloop[100];
    char *punch;
    char *decoy;
    int tokenNum = 0;
    bool firstIm = false;
    bool lastIm = false;
    int totalTokens = 0;
    strcpy(bloop, str);

    punch = strtok(bloop, "+- ");
    decoy = strtok(bloop, "+- ");
    
    
    //finding out how many parts are inputted
    while (decoy != NULL) {
    decoy = strtok(NULL, " +- ");
        totalTokens++; }
        //is also giving wrong number
        cout << "total tokens: " << totalTokens << endl;
    
    
    
    
    
    //would be useful if size and totalTokens were working
    for (int j = 0; j < sizeof(str); j++) {
          if ((punch[j] == 'i') && (j < sizeof(str)/2)){
            firstIm = true;
            } 
          else if (punch[j] == 'i') {
            lastIm = true;
            }
        
            }
            
          
          
   //sorting into tokens, but not doing it correctly either       
   while (punch != NULL)
   {    
     //if the first token has an i, then there is no other number
        if (firstIm) {
          i = atof(punch); 
          r = 0;
          }
      //if the second num is imaginary, during the cycle it will    
        else if (lastIm) {
        //assign the first value to real
          if (tokenNum = 0) {
          r = atof(punch);
          }
        //assign the second to imaginary  
          if (tokenNum = 1) {
          i = atof (punch);
          }
          
           }
       //if there isn't an i found, the number goes as is    
        else {
          r = atof(punch);
          i = 0;}
          
        punch = strtok(NULL, " +- ");
        tokenNum++;

   } 

	  
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


//still don't know how to use this
istream&  operator>>(istream &in, ComplexNumber &c) {

in >> c.r >> c.i;
return in;

}
//change back
ostream& operator<< (ostream &out, const ComplexNumber &c) {
	out << c.r << "+" << c.i << "i";
	return out;
}
