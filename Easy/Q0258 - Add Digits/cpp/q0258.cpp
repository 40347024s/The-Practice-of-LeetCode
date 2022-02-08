#include <iostream>

using namespace std;

int addDigits1(int num) {
    while (num/10) {
        int digit_sum = 0;
        while (num) {
            digit_sum += num%10;
            num /= 10;
        }
        num = digit_sum;
    }
    return num;
}

int addDigits2(int num) {
    if (num==0) {
        return num;
    }
    else {
        return (num-1)%9+1;
    }
}


int main() {
    // Method 1: Naive 
    cout << addDigits1(1234) << endl;

    // Method 2: Digital root, O(1)
    cout << addDigits1(1234) << endl;
    return 0;
}