#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    string s = "dvdf";
    unordered_map<char, int>seen;
    int max_len = 0;
    int head = 0;
    for (int i=0; i<s.length(); i++) {
        auto iter = seen.find(s[i]);
        if (iter!=seen.end()) {
            max_len = max(max_len, i - head);
            head = max(seen[s[i]] + 1, head);
        }
        seen[s[i]] = i;
    }
    max_len = max(max_len, (int)s.length() - head);
    cout << "max_len:" << max_len << endl;
    return 0;
}
