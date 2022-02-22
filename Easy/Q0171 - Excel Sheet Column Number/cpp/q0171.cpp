#include <cstdio>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int titleToNumber1(string columnTitle) {
    int ans = 0;
    for (int i=0; i<columnTitle.size(); i++) {
        ans += (int)pow(26, (int)columnTitle.size()-i-1) * (columnTitle[i] - 'A' + 1);
    }
    return ans;
}

int titleToNumber2(string columnTitle) {
    int ans = 0;
    for (int i=0; i<columnTitle.size(); i++) {
        ans = ans * 26 + (columnTitle[i] - 'A' + 1);
    }
    return ans;
}

int main() {
    vector <string> testcase_columnTitle = {"A", "AB", "ZY", "FXSHRXW"};
    for (int i=0; i<testcase_columnTitle.size(); i++) {
        // Method 1
        printf("%s => %d\n", testcase_columnTitle[i].c_str(), titleToNumber1(testcase_columnTitle[i]));
        
        // Method 2
        printf("%s => %d\n", testcase_columnTitle[i].c_str(), titleToNumber2(testcase_columnTitle[i]));
    }
    return 0;
}
