#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int reverse(int x) {
    int ans = 0;
    while (x) {
        if (ans > pow(2, 31)/10 || ans < pow(-2, 31)/10) {
            ans = 0;
            break;
        }
        ans *= 10;
        ans += x%10;
        x /= 10;
    }
    return ans;
}

int main() {
    vector<int> testcase = {123, -123, 120, 2147483647, -2147483648};
    for (int i=0; i< 5; i++) {
        cout << reverse(testcase[i]) << endl;
    }
    return 0;
}
