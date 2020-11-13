#include <numeric>

class Rational {
private:
    int num, den;

public:
    Rational(int _num = 0, int _den = 1): num(_num), den(_den) {
        int gcd = std::gcd(num, den);
        num /= gcd;
        den /= gcd;
        if (den < 0) {
            num = -num;
            den = -den;
        }
    }

    Rational operator+(const Rational& a) const {
        return Rational(num * a.den + a.num * den, den * a.den);
    }

    Rational operator-(const Rational& a) const {
        return Rational(num * a.den - a.num * den, den * a.den);
    }

    Rational operator*(const Rational& a) const {
        return Rational(num * a.num, den * a.den);
    }

    Rational operator/(const Rational& a) const {
        return Rational(num * a.den, den * a.num);
    }

    Rational operator+() const {
        return Rational(num, den);
    }

    Rational operator-() const {
        return Rational(-num, den);
    }

    Rational operator+(const int a) const {
        return *this + Rational(a, 1);
    }

    Rational operator*(const int a) const {
        return *this * Rational(a, 1);
    }

    Rational operator-(const int a) const {
        return *this - Rational(a, 1);
    }

    Rational operator/(const int a) const {
        return *this / Rational(a, 1);
    }

    int numerator() const {
        return num;
    }

    int denominator() const {
        return den;
    }

    Rational& operator+=(const Rational& a) {
        *this = *this + Rational(a);
        return *this;
    }

    Rational& operator-=(const Rational& a) {
        *this = *this - Rational(a);
        return *this;
    }

    Rational& operator*=(const Rational& a) {
        *this = *this * Rational(a);
        return *this;
    }

    Rational& operator/=(const Rational& a) {
        *this = *this / Rational(a);
        return *this;
    }

    bool operator==(const Rational& a) const {
        return (num == a.num / std::gcd(a.num, a.den) && den == a.den / std::gcd(a.num, a.den));
    }

    bool operator!=(const Rational& a) const {
        return (num != a.num / std::gcd(a.num, a.den) || den != a.den / std::gcd(a.num, a.den));
    }

    Rational& operator++() {
        *this += 1;
        return *this;
    }

    Rational operator++(int) {
        Rational p = *this;
        ++(*this);
        return p;
    }

    Rational& operator--() {
        *this -= 1;
        return *this;
    }

    Rational operator--(int) {
        Rational p = *this;
        --(*this);
        return p;
    }
};

Rational operator+(const int a, const Rational& rational) {
    return Rational(a, 1) + rational;
}

Rational operator*(const int a, const Rational& rational) {
    return Rational(a, 1) * rational;
}

Rational operator-(const int a, const Rational& rational) {
    return Rational(a, 1) - rational;
}

Rational operator/(const int a, const Rational& rational) {
    return Rational(a, 1) / rational;
}
