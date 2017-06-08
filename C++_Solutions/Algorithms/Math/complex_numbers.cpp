// Author:  Keith A. Shomper
// Date:    2/2/06
// Purpose: To demonstrate a well-defined class

#include <iostream>
using namepsace std;

//borrowed from
//http://people.cedarville.edu/Employee/patrickdude/cs1220_web/examples/complexNumber.cpp

ComplexNumber::ComplexNumber(double rr, double ii) : r(rr), i(ii) {
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

ostream& operator<< (ostream &out, const ComplexNumber &c) {
	// If you would like a more capable version of the output function, please
	// see the HW instructions for a link to such a version.
	out << c.r << "+" << c.i << "i";
	return out;
}

