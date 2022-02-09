#include <iostream>
#include <cmath>
#include <ctype.h>

using namespace std;

int myAtoi1(string s) {
    int ans = 0;
    bool is_negative = false;
    bool is_digit_begin = false;
    for (int i=0; i<s.length(); i++) {
        if (!is_digit_begin) {
            if (s[i]=='-') {
                is_negative = true;
                is_digit_begin = true;
            }
            else if (s[i]=='+') {
                is_digit_begin = true;
            }
            else if (isdigit(s[i])) {
                is_digit_begin = true;
                ans += s[i]- '0';
            }
            else if (s[i]!=' ') {
                return ans;
            }
        }
        else {
            if (!isdigit(s[i])) {
                break;
            }
            else {
                if (ans > (int)(pow(2, 31)/10) || (ans == (int)(pow(2, 31)/10) && (s[i]-'0')>=8)) {
                    ans = (int)(pow(2, 31)-1);
                    break;
                }
                else if (ans < (int)(pow(-2, 31)/10) || (ans == (int)(pow(-2, 31)/10) && (s[i]-'0')==9)) {
                    ans = (int)(pow(-2, 31));
                    break;
                }
                ans *= 10;
                ans += (s[i] - '0')*pow(-1, is_negative);
            }
        }
    }
    return ans;
}

int myAtoi2(string s) {
    int index = 0;
    bool is_negative = false;
    while (s[index]==' ') {
        index ++;
    }
    if (s[index]=='-') {
        is_negative = true;
        index ++;
    }
    else if (s[index]=='+') {
        index ++;
    }
    long ans = 0;
    while (index<s.length() && isdigit(s[index])) {
        ans = ans*10 + (s[index] - '0');
        if (ans > INT32_MAX) {
            return is_negative ? INT32_MIN : INT32_MAX;
        }
        index ++;
    }
    if (is_negative) {
        ans *= -1;
    }
    return ans;
}

int main() {
    string testcase[9] = {"-91283472332", "words and 987", "42", "    -42", "4193 with words", "2147483647", "-2147483648", "2147483648", "-21474836478"};
    for (int i=0; i< 9; i++) {
        cout << myAtoi1(testcase[i]) << endl;
        cout << myAtoi2(testcase[i]) << endl;
    }
    return 0;
}
