#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map <char, int> roman_table = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};

int romanToInt(string s) {
    int cur = 0, prev = 0;
    int ans = 0;
    while (s.length()) {
        cur = roman_table[s.back()];
        s.pop_back();
        if (cur < prev) {
            ans -= cur;
        }
        else {
            ans += cur;
        }
        prev = cur;
    }
    return ans;
}

int main() {
    vector <string> testcase_s = {"III", "LVIII", "MCMXCIV"};
    for (int i=0; i<testcase_s.size(); i++) {
        printf("%s -> %d\n", testcase_s[i].c_str(), romanToInt(testcase_s[i]));
    }
    return 0;
}