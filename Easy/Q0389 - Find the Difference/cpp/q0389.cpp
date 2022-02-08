#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

char findTheDifference1(string s, string t) {
    unordered_map<char, int> seen;
    for (int i=0; i<s.length(); i++) {
        auto iter = seen.find(s[i]);
        if (iter == seen.end()) {
            seen[s[i]] = 1;
        }
        else {
            seen[s[i]] += 1;
        }
    }
    for (int i=0; i< t.length(); i++) {
        auto iter = seen.find(t[i]);
        if (iter==seen.end()) {
            return t[i];
        }
        else if (seen[t[i]]==0) {
            return t[i];
        }
        else {
            seen[t[i]] -= 1;
        }
    }
    return ' ';
}

char findTheDifference2(string s, string t) {
    int ans = 0;
    for (int i=0; i<s.length(); i++) {
        ans -= s[i];
        ans += t[i];
    }
    ans += t[t.length()-1];
    
    return ans;
}
int main() {
    cout << "ans: " << findTheDifference1("abcd", "edcba") << endl;
    cout << "ans: " << findTheDifference2("abcd", "edcba") << endl;
    return 0;
}