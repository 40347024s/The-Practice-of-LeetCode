#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

bool isMatch(string s, string p) {
    int index = 0;
    for (int i=0; i<p.length(); i++) {
        if (p[i]=='.') {
            index++;
        }
        else if (p[i]=='*') {
            
        }
        else if (p[i]!=s[index]) {
            return false;
        }
        else {
            index++;
        }
    }
    if (index < s.length()) {
        return false;
    }
    return true;
}

int main() {
    string testcase_s[4] = {"aa", "aa", "ab", "qwer"};
    string testcase_p[4] = {"a", "a*", ".*", "qw.r"};
    for (int i=0; i<4; i++) {
        cout << testcase_s[i] << ", " << testcase_p[i] << ": " << isMatch(testcase_s[i], testcase_p[i]) << endl;
    }
    return 0;
}