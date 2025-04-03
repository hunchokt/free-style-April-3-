#include "Fraction.h"
#include <stdexcept>
#include <iostream>

Fraction::Fraction(int n, int d)
    : num {n}, den {d}
{
    if (d == 0) {
        throw std::runtime_error("Denominator can't be zero");
    }

    if (num < 0) num *= -1;
    if (den < 0) den *= -1;
}

int Fraction::gcd() const {
    int gcd { 1 };
    int min {};

    (num < den) ? min = num : min = den;

    for (int i = 1; i <= min; ++i) {
        if (num % i == 0 && den % i == 0) {
            gcd = i;
        }
    }
    return gcd;
}

void Fraction::reduce() {
    int divisor = this -> gcd();
    num /= divisor;
    den /= divisor;
}

bool Fraction::operator==(const Fraction& other) const {
    return (num == other.num) && (den == other.den);
}

std::ostream& operator<<(std::ostream& out, const Fraction& frac) {
    out << frac.getNumerator() << "/" << frac.getDenominator();
    return out;
}


