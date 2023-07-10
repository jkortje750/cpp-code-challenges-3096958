#include "complex_num.h"
#include <iomanip>

complex_num::complex_num(double real, double imag) {
    this->real = real;
    this->imag = imag;
}

complex_num complex_num::operator +(complex_num other) {
    complex_num sum;
    sum.real = this->real + other.real;
    sum.imag = this->imag + other.imag;
    return sum;
}

complex_num complex_num::operator -(complex_num other) {
    complex_num diff;
    diff.real = this->real - other.real;
    diff.imag = this->imag - other.imag;
    return diff;
}

complex_num complex_num::operator *(complex_num other) {
    complex_num prod;
    prod.real = (this->real * other.real) - (this->imag * other.imag);
    prod.imag = (this->real * other.imag) + (this->imag * other.real);
    return prod;
}

complex_num complex_num::operator /(complex_num other) {
    complex_num div;
    double divisor = ((other.real * other.real) + (other.imag * other.imag));
    div.real = (this->real * other.real) + (this->imag * other.imag);
    div.real = div.real / divisor;
    div.imag = (this->imag * other.real) - (this->real * other.imag);
    div.imag = div.imag / divisor;
    return div;
}

void complex_num::print(std::ostream &os) {
    os << std::fixed << std::setprecision(2);
    if (imag >= 0.0) {
        os << real << " + " << imag << "i";
    } else {
        os << real << " - " << -1 * imag << "i";
    }
    os << std::flush;
}
