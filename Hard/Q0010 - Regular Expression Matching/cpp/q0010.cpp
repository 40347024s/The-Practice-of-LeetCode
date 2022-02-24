#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>

using namespace std;

bool isMatch(string s, string p) {
    if (!p.length()) {
        return s.length()==0;
    }
    bool first_match = (s.length() > 0) && (p[0]==s[0] || p[0]=='.');
    if ((p.length()>=2) && (p[1]=='*')) {
        return (isMatch(s, p.substr(2, p.length()))) || (first_match && isMatch(s.substr(1, s.length()), p));
    }
    else {
        return first_match && isMatch(s.substr(1, s.length()), p.substr(1, p.length()));
    }
}

bool 

int main() {
    vector <string> testcase_s = {"aa", "aa", "ab", "qwer", "aab"};
    vector <string> testcase_p = {"a", "a*", ".*", "qw.r", "c*a*b"};
    for (int i=0; i<testcase_s.size(); i++) {
        // Method 1: Recursion, Modified from solution of python
        cout << testcase_s[i] << ", " << testcase_p[i] << ": " << isMatch(testcase_s[i], testcase_p[i]) << endl;
    }
    return 0;
}