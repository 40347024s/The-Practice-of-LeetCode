#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    int p;
    for (p = 0; p<strs[0].length();p++) {
        bool is_same = true;
        for (int j=1; j<strs.size(); j++) {
            if (p < strs[j].length() && strs[j][p]==strs[0][p]) {
                continue;
            }
            is_same = false;
            break;
        }
        if (!is_same) {
            break;
        }
    }
    return strs[0].substr(0, p);
}

int main() {
    vector <vector <string>> testcase_strs = {{"flower","flow","flight"}, {"dog","racecar","car"}, {""}};
    for (int i=0; i<testcase_strs.size(); i++) {
        printf("[");
        for (int j=0; j<testcase_strs[i].size(); j++) {
            printf("\"%s\", ", testcase_strs[i][j].c_str());
        }
        printf("] -> \"%s\"\n", longestCommonPrefix(testcase_strs[i]).c_str());
    }
    return 0;
}