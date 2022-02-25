#include <string>
#include <cstdio>
#include <vector>

using namespace std;

int compareVersion(string version1, string version2) {
    int i = 0, j = 0;
    while (i<version1.length() || j<version2.length()) {
        int val1 = 0, val2 = 0;
        while (i<version1.length() && version1[i]!='.') {
            val1 = val1 * 10 + version1[i] - '0';
            i++;
        }
        while (j<version2.length() && version2[j]!='.') {
            val2 = val2 * 10 + version2[j] - '0';
            j++;
        }
        if (val1 > val2) {
            return 1;
        }
        else if (val1 < val2) {
            return -1;
        }
        i++;
        j++;
    }
    return 0;
}


int main() {
    vector<string> testcase_ver1 = {"1.0", "1.01", "0.1"};
    vector<string> testcase_ver2 = {"1.0.0", "1.001", "1.1"};
    for (int i=0; i< testcase_ver1.size(); i++) {
        printf("%s vs. %s? => %d\n", testcase_ver1[i].c_str(), testcase_ver2[i].c_str(), compareVersion(testcase_ver1[i], testcase_ver2[i]));
    }
    return 0;
}
