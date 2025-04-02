#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

    void reduce()
    {
        for (int i = 0; i < (numerator > denominator ? numerator : denominator); ++i)
        {
            if (numerator % i == 0 && denominator % i == 0)
            {
                numerator = numerator / i;
                denominator = denominator / i;
            }
        };

        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        };
    };

public:
    Fraction(int _numerator, int _denominator) : numerator(_numerator), denominator(_denominator)
    {
        if (_denominator == 0)
        {
            throw invalid_argument("Denominator cannot be Zero");
        };
        reduce();
    };

    Fraction operator+(const Fraction &args) const
    {
        return Fraction(numerator * args.denominator + args.numerator * denominator, denominator * args.denominator);
    };

    Fraction operator-(const Fraction &args) const
    {
        return Fraction(numerator * args.denominator - args.numerator * denominator, denominator * args.denominator);
    };

    Fraction operator*(const Fraction &args) const
    {
        return Fraction(numerator * args.numerator, denominator * args.denominator);
    };

    Fraction operator/(const Fraction &args) const
    {
        if (args.numerator == 0)
        {
            throw domain_error("Division by zero");
        }
        return Fraction(numerator * args.denominator, denominator * args.numerator);
    };

    bool operator==(const Fraction &args) const
    {
        return numerator == args.numerator && denominator == args.denominator;
    };

    bool operator!=(const Fraction &args) const
    {
        return numerator != args.numerator || denominator != args.denominator;
    };

    bool operator<(const Fraction &args) const
    {
        return numerator * args.denominator < denominator * args.numerator;
    };

    bool operator>(const Fraction &args) const
    {
        return numerator * args.denominator > denominator * args.numerator;
    };

    bool operator<=(const Fraction &args) const
    {
        return (numerator * args.denominator < denominator * args.numerator) || (numerator == args.numerator && denominator == args.denominator);
    };

    bool operator>=(const Fraction &args) const
    {
        return (numerator * args.denominator > denominator * args.numerator) || (numerator == args.numerator && denominator == args.denominator);
    };

    
};