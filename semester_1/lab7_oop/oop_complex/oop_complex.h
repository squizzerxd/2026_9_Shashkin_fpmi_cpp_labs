#pragma once

#include <iosfwd>

class Complex {
public:
    Complex();
    Complex(double real, double imag = 0.0);
    Complex(const Complex& other);
    Complex& operator=(const Complex& other);

    double Real() const;
    void Real(double value);
    double Imag() const;
    void Imag(double value);
    double Abs() const;

    Complex operator+() const;
    Complex operator-() const;

    Complex& operator+=(const Complex& rhs);
    Complex& operator-=(const Complex& rhs);
    Complex& operator*=(const Complex& rhs);
    Complex& operator/=(const Complex& rhs);

private:
    double re_;
    double im_;
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const Complex& rhs);

bool operator==(const Complex& lhs, const Complex& rhs);
bool operator!=(const Complex& lhs, const Complex& rhs);

std::ostream& operator<<(std::ostream& out, const Complex& z);
std::istream& operator>>(std::istream& in, Complex& z);