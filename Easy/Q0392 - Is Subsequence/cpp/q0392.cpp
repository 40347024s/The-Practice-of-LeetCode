#include <vector>
#include <string>

using namespace std;

bool isSubsequence1(string s, string t) {
    if (!s.length()) {
        return true;
    }
    else if(!t.length()) {
        return false;
    }
    if (s[0]==t[0]) {
        return isSubsequence1(s.substr(1, s.length()), t.substr(1, t.length()));
    }
    else {
        return isSubsequence1(s, t.substr(1, t.length()));
    }
}

bool isSubsequence2(string s, string t) {
    int p1 = 0;
    int p2 = 0;
    while (p1<s.length() && p2<t.length()) {
        if (s[p1]==t[p2]) {
            p1++;
        }
        p2++;
    }
    if (p1==s.length()) {
        return true;
    }
    return false;
}

int main() {
    vector <string> testcase_s = {"abc", "axc"};
    vector <string> testcase_t = {"ahbgdc", "ahbgdc"};
    for (int i=0; i<testcase_s.size(); i++) {
        // Method 1: Recursion
        printf("%s is in %s? => %d\n", testcase_s[i].c_str(), testcase_t[i].c_str(), isSubsequence1(testcase_s[i], testcase_t[i]));

        // Method 2: 
        printf("%s is in %s? => %d\n", testcase_s[i].c_str(), testcase_t[i].c_str(), isSubsequence2(testcase_s[i], testcase_t[i]));
    }
    return 0;
}