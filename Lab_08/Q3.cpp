#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class BigInteger {
private:
    vector<int> digits;
    bool isNegative;

public:
    BigInteger(string number) {
        isNegative = (number[0] == '-');
        for (int i = number.length() - 1; i >= isNegative; i--)
            digits.push_back(number[i] - '0');
    }

    friend ostream& operator<<(ostream& os, const BigInteger& num);
    friend BigInteger operator+(const BigInteger &num1, const BigInteger &num2);
};

ostream& operator<<(ostream& os, const BigInteger& num) {
    if (num.isNegative) os << "-";
    for (int i = num.digits.size() - 1; i >= 0; i--)
        os << num.digits[i];
    return os;
}

BigInteger operator+(const BigInteger &num1, const BigInteger &num2) {
    vector<int> result;
    int carry = 0;
    size_t maxSize = max(num1.digits.size(), num2.digits.size());
    
    for (size_t i = 0; i < maxSize || carry; ++i) {
        int sum = carry;
        if (i < num1.digits.size()) sum += num1.digits[i];
        if (i < num2.digits.size()) sum += num2.digits[i];
        result.push_back(sum % 10);
        carry = sum / 10;
    }
    
    string sumStr;
    for (int i = result.size() - 1; i >= 0; i--) {
        sumStr += to_string(result[i]);
    }
    return BigInteger(sumStr);
}

int main() {
    BigInteger num1("12345678901234567890");
    BigInteger num2("98765432109876543210");
    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;
    cout << "num1 + num2: " << num1 + num2 << endl;
    return 0;
}
