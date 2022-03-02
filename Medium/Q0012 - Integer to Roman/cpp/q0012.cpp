#include <vector>
#include <string>
#include <cstdio>
#include <unordered_map>

using namespace std;

unordered_map <int, char> roman_table = {{1, 'I'}, {5, 'V'}, {10, 'X'}, {50, 'L'}, {100, 'C'}, {500, 'D'}, {1000, 'M'}};

string intToRoman1(int num) {
    string ans;
    int dividend = 1;
    int res = num%10;
    while (num) {
        string roman_num;
        if (res==9) {
            roman_num += roman_table[dividend];
            roman_num += roman_table[dividend*10];
        }
        else if (res==4) {
            roman_num += roman_table[dividend];
            roman_num += roman_table[dividend*5];
        }
        else {
            if (res >= 5) {
                roman_num += roman_table[dividend*5];
                res -= 5;
            }
            for (int i=0; i<res; i++) {
                roman_num += roman_table[dividend];
            }
        }
        ans = roman_num + ans;
        dividend *= 10;
        num /= 10;
        res = num%10;
    }

    return ans;
}

vector <string> roman_nums = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
vector <int> roman_idx = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

string intToRoman2(int num) {
    string ans;
    for (int i=0; i<roman_idx.size(); i++) {
        while (num/roman_idx[i]) {
            ans += roman_nums[i];
            num -= roman_idx[i];
        }
    }
    return ans;
}

int main() {
    vector <int> testcase_num = {3, 58, 1994, 10};
    for (int i=0; i<testcase_num.size(); i++) {
        printf("%d -> %s\n", testcase_num[i], intToRoman1(testcase_num[i]).c_str());
        printf("%d -> %s\n", testcase_num[i], intToRoman2(testcase_num[i]).c_str());
    }
    return 0;
}