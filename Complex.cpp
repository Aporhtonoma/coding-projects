#include "Complex.hpp"

Complex::Complex() : re(0.0), im(0.0) {}
Complex::Complex(double r) : re(r), im(0.0) {}
Complex::Complex(double r, double i) : re(r), im(i) {}

double Complex::real()
{
    return re;
}
double Complex::imag()
{
    return im;
}

double Complex::conj()
{
    return (im=-im);
}

Complex Complex::raiseto(const Complex &other)
{
    return Complex (re=(re*im)-(other.re * other.im) ,im=(other.im * re)+(im * other.re));

}

Complex Complex::operator+(const Complex &other)
{
    return Complex(re + other.re, im + other.im);
}

Complex Complex::operator-(const Complex &other)
{
    return Complex(re - other.re, im - other.im);
}

Complex Complex::operator*(const Complex &other)
{
    return Complex((re * other.re)-(im * other.im), (im * other.re)+(other.im * re));
}

Complex Complex::operator/(const Complex &other)
{
    return Complex(((re * other.re)+(im * other.im))/((other.re*other.re)+(other.im*other.im)), ((im * other.re)-(re *other.im))/((other.re*other.re)+(other.im*other.im)));
}

Complex Complex::operator==(const Complex&other){
    return ((re==other.re)&&(im==other.im));
}

Complex Complex::operator!=(const Complex&other){
    return ((re!=other.re)&&(im!=other.im));
}

Complex  Complex::copycat(const Complex&other){
    return (re=other.re),(im=other.im);
}

std::ostream &operator<<(std::ostream &os, const Complex &c)
{
    if (c.im == 0)
        os << c.re;
    else if (c.im < 0)
        os << c.re << " - " << -c.im << "i";
    else
        os << c.re << " + " << c.im << "i";
    return os;
}