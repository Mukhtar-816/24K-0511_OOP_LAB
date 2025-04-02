#include <iostream>
#include <vector>
using namespace std;

class Polynomial;

class PolynomialUtils {
public:
    static int evaluate(const Polynomial &p, int x);
    static Polynomial derivative(const Polynomial &p);
};

class Polynomial {
private:
    vector<int> coefficients;
public:
    Polynomial() {}
    Polynomial(const vector<int> &coeffs) : coefficients(coeffs) {}
    friend ostream& operator<<(ostream& os, const Polynomial& poly);
    friend Polynomial operator+(const Polynomial &p1, const Polynomial &p2);
    friend Polynomial operator-(const Polynomial &p1, const Polynomial &p2);
    friend Polynomial operator*(const Polynomial &p1, const Polynomial &p2);
    friend class PolynomialUtils;
};

ostream& operator<<(ostream& os, const Polynomial& poly) {
    if (poly.coefficients.empty()) {
        os << "0";
        return os;
    }
    for (int i = poly.coefficients.size() - 1; i >= 0; --i) {
        if (poly.coefficients[i] == 0) continue;
        if (i != poly.coefficients.size() - 1 && poly.coefficients[i] > 0) os << " + ";
        if (poly.coefficients[i] < 0) os << " - ";
        if (abs(poly.coefficients[i]) != 1 || i == 0) os << abs(poly.coefficients[i]);
        if (i > 0) os << "x";
        if (i > 1) os << "^" << i;
    }
    return os;
}

Polynomial operator+(const Polynomial &p1, const Polynomial &p2) {
    vector<int> result(max(p1.coefficients.size(), p2.coefficients.size()), 0);
    for (size_t i = 0; i < p1.coefficients.size(); i++) result[i] += p1.coefficients[i];
    for (size_t i = 0; i < p2.coefficients.size(); i++) result[i] += p2.coefficients[i];
    return Polynomial(result);
}

Polynomial operator-(const Polynomial &p1, const Polynomial &p2) {
    vector<int> result(max(p1.coefficients.size(), p2.coefficients.size()), 0);
    for (size_t i = 0; i < p1.coefficients.size(); i++) result[i] += p1.coefficients[i];
    for (size_t i = 0; i < p2.coefficients.size(); i++) result[i] -= p2.coefficients[i];
    return Polynomial(result);
}

Polynomial operator*(const Polynomial &p1, const Polynomial &p2) {
    vector<int> result(p1.coefficients.size() + p2.coefficients.size() - 1, 0);
    for (size_t i = 0; i < p1.coefficients.size(); i++)
        for (size_t j = 0; j < p2.coefficients.size(); j++)
            result[i + j] += p1.coefficients[i] * p2.coefficients[j];
    return Polynomial(result);
}

int PolynomialUtils::evaluate(const Polynomial &p, int x) {
    int result = 0, power = 1;
    for (int coeff : p.coefficients) {
        result += coeff * power;
        power *= x;
    }
    return result;
}

Polynomial PolynomialUtils::derivative(const Polynomial &p) {
    if (p.coefficients.size() <= 1) return Polynomial();
    vector<int> deriv_coeffs(p.coefficients.size() - 1);
    for (size_t i = 1; i < p.coefficients.size(); i++)
        deriv_coeffs[i - 1] = p.coefficients[i] * i;
    return Polynomial(deriv_coeffs);
}

int main() {
    Polynomial p1({2, 0, 3});
    Polynomial p2({1, 4});
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "p1 + p2: " << p1 + p2 << endl;
    cout << "p1 - p2: " << p1 - p2 << endl;
    cout << "p1 * p2: " << p1 * p2 << endl;
    cout << "p1 evaluated at x=2: " << PolynomialUtils::evaluate(p1, 2) << endl;
    cout << "Derivative of p1: " << PolynomialUtils::derivative(p1) << endl;
    return 0;
}
