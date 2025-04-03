#ifndef FRACTION_H
#define FRACTION_H

#include <stdexcept>
#include <iostream>

class Fraction
{
private:
    int num {};
    int den {};

public:
    Fraction(int n = 1, int d = 1);

    int getNumerator() const { return num; }
    int getDenominator() const { return den; }

    int gcd() const;

    void reduce();

    bool operator==(const Fraction& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Fraction& frac);
};

#endif