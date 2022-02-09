#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <string.h>

using namespace std;

string convert1(string s, int numRows) {
    if (numRows==1) {
        return s;
    }
    vector <char> vec[numRows];
    for (int i=0; i<(int)s.length(); i++) {
        int ind = i%(2*(numRows-1));
        if (ind < numRows) {
            vec[ind].push_back(s[i]);
        }
        else {
            vec[(2*(numRows-1))-ind].push_back(s[i]);
        }
    }
    string ans;
    for (int i=0; i<numRows; i++) {
        for (int j=0; j<vec[i].size(); j++) {
            ans += vec[i][j];
        }
    }
    return ans;
}

string convert2(string s, int numRows) {
    if (numRows==1 || s.length()<numRows) {
        return s;
    }
    string ans;
    for (int i=0; i<numRows ;i++) {
        int step = 2*(numRows-i-1);
        int total_step = step;
        ans += s[i];
        while (i+total_step < (int)s.length()) {
            if (step) {
                ans += s[i+total_step];
            }
            step = 2*(numRows-1) - step;
            total_step += step;
        }
    }
    return ans;
}

int main() {
    string testcase_str[5] = {"abcde", "abcdefghijklmnop", "PAYPALISHIRING", "PAYPALISHIRING", "A"};
    int testcase_int[5] = {6, 4, 3, 4, 1};
    for (int i=0; i< 5; i++) {
        cout << convert1(testcase_str[i], testcase_int[i]) << endl;
        cout << convert2(testcase_str[i], testcase_int[i]) << endl;
    }
    return 0;
}
