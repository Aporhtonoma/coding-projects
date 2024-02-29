#include <iostream>

class Complex
{
private:
    double re;
    double im;

public:
    Complex();
    Complex(double r);
    Complex(double r, double i);

    double real();
    double imag();

    Complex operator+(const Complex &other);

    Complex operator-(const Complex &other);

    Complex operator*(const Complex &other);

    Complex operator/(const Complex &other);
    
    double conj();

    Complex operator==(const Complex&other);

    Complex operator!=(const Complex&other);

    Complex raiseto(const Complex&other);
    Complex copycat(const Complex&other);

    friend std::ostream& operator<<(std::ostream &os, const Complex &c);
};
