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

void permutation(string head, string tail, int len) {
    while (tail.length() > 0) {
        char cur_ch = *tail.begin();
        tail.erase(tail.begin());
        if (cur_ch=='*') {
            char prev_ch = *head.rbegin();
            head.erase(head.end()-1);
            for (int i=0; i<=len-(int)head.length(); i++) {
                permutation(head+string(i, prev_ch), tail, len);
            }
        }
        else {
            head += cur_ch;
        }
    }
    if (head.length()==len) {
        cout << "ans: " << head << endl;
    }
    return;
}

int main() {
    // string testcase_s[4] = {"aa", "aa", "ab", "qwer", "aab"};
    // string testcase_p[4] = {"a", "a*", ".*", "qw.r", "c*a*b"};
    // for (int i=0; i<4; i++) {
    //     cout << testcase_s[i] << ", " << testcase_p[i] << ": " << isMatch(testcase_s[i], testcase_p[i]) << endl;
    // }
    permutation("", "a*b*c*d*e*b", 3);
    return 0;
}