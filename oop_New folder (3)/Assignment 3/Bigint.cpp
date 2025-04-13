#pragma once
#include<iostream>
using namespace std;
class BigInt {
    string digits;
public:
    //constructors
    BigInt(int val = 0) {
        digits = to_string(val);
    }
    BigInt(const string& text) {
        digits = text;
    }
    BigInt(const BigInt& copy) {
        digits = copy.digits;
    }
   
    //ARithemtic operations
    //picked up
    BigInt operator+(const BigInt& val) const {
        string result_digits;
        int carry = 0;
        int i = digits.length() - 1, j = val.digits.length() - 1;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) {
                sum += digits[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += val.digits[j] - '0';
                j--;
            }
            carry = sum / 10;
            sum = sum % 10;
            result_digits = to_string(sum) + result_digits;
        }
        BigInt result(result_digits);
        return result;
    }
    // defined
    BigInt operator+=( BigInt& value) {
        *this = *this + value;
        return *this;
    }

    BigInt operator+(int val) const {
        BigInt temp(val);
        return *this + temp;
    }
    //subtraction
    //picked up 
    //need to be changed
    BigInt operator-(const BigInt& val) const {
        string result_digits;
        int borrow = 0;
        int i = digits.length() - 1, j = val.digits.length() - 1;

        while (i >= 0 || j >= 0) {
            int diff = borrow;
            if (i >= 0) {
                diff += digits[i] - '0';
                i--;
            }
            if (j >= 0) {
                diff -= val.digits[j] - '0';
                j--;
            }
            if (diff < 0) {
                borrow = -1;
                diff += 10;
            }
            else {
                borrow = 0;
            }
            result_digits = to_string(diff) + result_digits;
        }
        while (result_digits.length() > 1 && result_digits[0] == '0') {
            result_digits.erase(0, 1);
        }
        BigInt result(result_digits);
        return result;
    }
    //okay
    BigInt operator-=( BigInt& value) {
        *this = *this - value;
        return *this;
    }

    BigInt operator-(int val) const {
        BigInt value(val);
        return *this - value;
    }
   
    
   
    //////////
    //multiplication

    BigInt operator*(const BigInt& val) const 
    {
        int i = digits.length() - 1;
        int j = val.digits.length() - 1;
        string store(i + j + 2, '0');
        int carry = 0;
        for (i; i >= 0; i--) {
            int temp = digits[i] - '0';
            int k = j;
            for (k; k >= 0; k--) {
                int result = carry + (temp * (val.digits[k] - '0')) + (store[i + k + 1] - '0');
                store[i + k + 1] = (result % 10) + '0';
                carry = result / 10;
            }
            if (carry > 0) {
                store[i + k + 1] += carry;
                carry = 0;
            }
        }
        while (store.size() > 1 && store[0] == '0') {
            store.erase(0, 1);
        }
        BigInt final(store);
        return final;
    }

    BigInt operator*=( BigInt& value) {
        *this = *this * value;
        return *this;
    }
    //unary operator: 
   

    BigInt& operator++()
    {
        int carry = 1;
        int i = digits.length() - 1;
        for (i; i >= 0 && carry; i--) {
            int digit = digits[i] - '0' + carry;
            carry = digit / 10;
            digit = digit % 10;
            digits[i] = digit + '0';
        }
        if (carry) {
            digits = "1" + digits;
        }
        return *this;
    }

    BigInt operator++(int)
    {
        BigInt store(*this);
        int carry = 1;
        int i = digits.length() - 1;
        for (i; i >= 0 && carry; i--) {
            int digit = digits[i] - '0' + carry;
            carry = digit / 10;
            digit = digit % 10;
            digits[i] = digit + '0';
        }
        if (carry) {
            digits = "1" + digits;
        }
        return store;
    }

    BigInt& operator--()
    {
        if (digits.length() == 1 && digits[0] == '0') {
            return *this;
        }
        int borrow = 1;
        int i = digits.length() - 1;
        for (i; i >= 0 && borrow; i--) {
            int result = digits[i] - '0' - borrow;
            borrow = result < 0;
            result = (result + 10) % 10;
            digits[i] = result + '0';
        }
        while (digits.length() > 1 && digits[0] == '0') {
            digits.erase(0, 1);
        }
        return *this;
    }
      

    BigInt operator--(int) {
        BigInt store(*this);
        if (digits == "0") {
            digits = "1";
        }
        int borrow = 1;
        int i = digits.length() - 1;
        for (i; i >= 0 && borrow; i--) {
            int result = digits[i] - '0' - borrow;
            borrow = result < 0;
            result = (result + 10) % 10;
            digits[i] = result + '0';
        }
        while (digits.length() > 1 && digits[0] == '0') {
            digits.erase(0, 1);
        }
        return store;
    }
    //logical operators 

    bool operator==(const BigInt& val) const {
        int i = digits.length() - 1;
        int j = val.digits.length() - 1;
        if (i != j) {
            return false;
        }
        for (i, j; i >= 0 && j >= 0; i--, j--)
        {
            if (digits[i] != val.digits[j])
            {
                return false;
            }
        }
        return true;
    }

    bool operator==(const string& val) const {
        int i = digits.length() - 1;
        int j =val.length() - 1;
        if (i != j) {
            return false;
        }
        for (i, j; i >= 0 && j >= 0; i--, j--)
        {
            if (digits[i] != val[j])
            {
                return false;
            }
        }
        return true;
    }


    bool operator!=(const BigInt& val) const {
        int i = digits.length() - 1;
        int j = val.digits.length() - 1;
        if (i != j) {
            return true;
        }
        for (i, j; i >= 0 && j >= 0; i--, j--) {
            if (digits[i] == val.digits[j]) {
                return false;
            }

        }
        return true;

    }

    bool operator<(const BigInt& val) const {
        int i = digits.length() - 1;
        int j = val.digits.length() - 1;
        if (i < j) {
            return true;
        }
        for (i, j; i >= 0 && j >= 0; i--, j--) {
            if (digits[i] > val.digits[j]) {
                return false;
            }

        }
        return true;

    
    }
    bool operator>(const BigInt& val) const {
        int i = digits.length() - 1;
        int j = val.digits.length() - 1;
        if (i < j) {
            return false;
        }
        for (i, j; i >= 0 && j >= 0; i--, j--) {
            if (digits[i] < val.digits[j]) {
                return false;
            }

        }
        return true;
    }
  
    bool operator<=(const BigInt& val) const {
        int i = digits.length() - 1;
        int j = val.digits.length() - 1;
        if (i > j) {
            return false;
        }
        for (; i >= 0 && j >= 0; i--, j--) {
            if (digits[i] > val.digits[j]) {
                return false;
            }
            if (digits[i] < val.digits[j]) {
                return true;
            }
        }
        return true;
    }

    
    bool operator>=(const BigInt& val) const {
        int i = digits.length() - 1;
        int j = val.digits.length() - 1;
        if (i < j) {
            return false;
        }
        for (i, j; i >= 0 && j >= 0; i--, j--) {
            if (digits[i] < val.digits[j] && digits[i] != val.digits[j]) {
                return false;
            }

        }
        return true;

    }
    //compound operator 
    void removeLeadingZeros() {
        int i = 0;
        while (digits[i] == '0' && i < digits.length() - 1) {
            i++;
        }
        digits = digits.substr(i);
    }
    BigInt operator-=(const BigInt& rhs) {
        int borrow = 0;
        int i = digits.length() - 1, j = rhs.digits.length() - 1;
        while (i >= 0 || j >= 0 || borrow) {
            int diff = borrow;
            if (i >= 0) {
                diff += digits[i] - '0';
                i--;
            }
            if (j >= 0) {
                diff -= rhs.digits[j] - '0';
                j--;
            }
            if (diff < 0) {
                diff += 10;
                borrow = -1;
            }
            else {
                borrow = 0;
            }
            digits = to_string(diff) + digits;
        }
        removeLeadingZeros();
        return *this;
    }

    //
    operator int() {
        return digits.length();
    }
    operator string() const {
        return digits;
    }

    friend ostream& operator<<(ostream& output, const BigInt& val); // outputs the BigInt
    friend istream& operator>>(istream& input, BigInt& val); // inputs the BigInt

};
    istream& operator>>(istream& input, BigInt& val) {
        string str;
        input >> str;
        val = BigInt(str);
        return input;
    }
    ostream& operator<<(ostream& output, const BigInt& val) {
        output << val.digits;
        return output;
    }