#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool isPalindrome(int x) {
    if (x<0) {
        return false;
    }
    string num;

    while (x) {
        num += (x%10) + '0';
        x /= 10;
    }    

    string num_reverse = num;
    reverse(num_reverse.begin(), num_reverse.end());
    return num==num_reverse;
}

int main() {
    // string testcase[9] = {"-91283472332", "words and 987", "42", "    -42", "4193 with words", "2147483647", "-2147483648", "2147483648", "-21474836478"};
    int testcase[7] = {120, 121, -12, 0, 111, 11, 1};
    for (int i=0; i< 7; i++) {
        cout << testcase[i] << ": " << isPalindrome(testcase[i]) << endl;
    }
    return 0;
}
