#include <cmath>

class Complex {
private:
    double re, im;

public:
    Complex(double _re, double _im): re(_re), im(_im) {}

    Complex(double _re): re(_re), im(0) {}

    Complex operator+(const Complex& a) const {
        return {re + a.re, im + a.im};
    }

    Complex operator-(const Complex& a) const {
        return {re - a.re, im - a.im};
    }

    Complex operator*(const Complex& a) const {
        return {re * a.re - im * a.im, re * a.im + im * a.re};
    }

    Complex operator/(const Complex& a) const {
        return {(re * a.re + im * a.im) / (a.re * a.re + a.im * a.im),
                (im * a.re - re * a.im) / (a.re * a.re + a.im * a.im)};
    }

    bool operator==(const Complex& a) const {
        return (re == a.re && im == a.im);
    }

    bool operator!=(const Complex& a) const {
        return (re != a.re || im != a.im);
    }

    double Re() const {
        return re;
    }

    double Im() const {
        return im;
    }

    Complex& operator+=(const Complex& a) {
        re += a.re;
        im += a.im;
        return *this;
    }

    Complex& operator-=(const Complex& a) {
        re -= a.re;
        im -= a.im;
        return *this;
    }

    Complex operator+() const {
        return {re, im};
    }

    Complex operator-() const {
        return {-re, -im};
    }
};

Complex operator+(double a, const Complex& complex) {
    return {a + complex.Re(), complex.Im()};
}

Complex operator*(double a, const Complex& complex) {
    return {a * complex.Re(), a * complex.Im()};
}

double abs(const Complex& a) {
    return sqrt(a.Re() * a.Re() + a.Im() * a.Im());
}