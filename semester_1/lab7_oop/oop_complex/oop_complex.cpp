#include "oop_complex.h"

#include <cmath>
#include <iostream>

Complex::Complex() : re_(0.0), im_(0.0) {}

Complex::Complex(double real, double imag) : re_(real), im_(imag) {}

Complex::Complex(const Complex& other) : re_(other.re_), im_(other.im_) {}

Complex& Complex::operator=(const Complex& other) {
    if (this != &other) {
        re_ = other.re_;
        im_ = other.im_;
    }
    return *this;
}

double Complex::Real() const { return re_; }
void Complex::Real(double value) { re_ = value; }
double Complex::Imag() const { return im_; }
void Complex::Imag(double value) { im_ = value; }

double Complex::Abs() const { return std::hypot(re_, im_); }

Complex Complex::operator+() const { return *this; }
Complex Complex::operator-() const { return Complex(-re_, -im_); }

Complex& Complex::operator+=(const Complex& rhs) {
    re_ += rhs.re_;
    im_ += rhs.im_;
    return *this;
}

Complex& Complex::operator-=(const Complex& rhs) {
    re_ -= rhs.re_;
    im_ -= rhs.im_;
    return *this;
}

Complex& Complex::operator*=(const Complex& rhs) {
    const double re = re_ * rhs.re_ - im_ * rhs.im_;
    const double im = re_ * rhs.im_ + im_ * rhs.re_;
    re_ = re;
    im_ = im;
    return *this;
}

Complex& Complex::operator/=(const Complex& rhs) {
    const double denom = rhs.re_ * rhs.re_ + rhs.im_ * rhs.im_;
    const double re = (re_ * rhs.re_ + im_ * rhs.im_) / denom;
    const double im = (im_ * rhs.re_ - re_ * rhs.im_) / denom;
    re_ = re;
    im_ = im;
    return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs) {
    Complex result(lhs);
    result += rhs;
    return result;
}

Complex operator-(const Complex& lhs, const Complex& rhs) {
    Complex result(lhs);
    result -= rhs;
    return result;
}

Complex operator*(const Complex& lhs, const Complex& rhs) {
    Complex result(lhs);
    result *= rhs;
    return result;
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
    Complex result(lhs);
    result /= rhs;
    return result;
}

bool operator==(const Complex& lhs, const Complex& rhs) {
    return lhs.Real() == rhs.Real() && lhs.Imag() == rhs.Imag();
}

bool operator!=(const Complex& lhs, const Complex& rhs) { return !(lhs == rhs); }


std::ostream& operator<<(std::ostream& out, const Complex& z) {
    out << '(' << z.Real() << ',' << z.Imag() << ')';
    return out;
}


std::istream& operator>>(std::istream& in, Complex& z) {
    char c;
    if (!(in >> c)) {
        return in;
    }
    double re = 0.0;
    double im = 0.0;
    if (c == '(') {
        in >> re >> c;
        if (in && c == ',') {
            in >> im >> c;
        }
        if (in && c != ')') {
            in.setstate(std::ios::failbit);
        }
    }
    else {
        in.putback(c);
        in >> re;
    }
    if (in) {
        z = Complex(re, im);
    }
    return in;
}