#include <vector>
#include <cstdio>

using namespace std;

vector<int> countBits1(int n) {
    vector <int> ans;
    for (int i=0; i<=n ;i++) {
        ans.push_back(0);
        int tmp = i;
        while (tmp) {
            ans[i] += tmp%2;
            tmp /= 2;
        }
    }
    return ans;
}

vector<int> countBits2(int n) {
    vector <int> ans;
    if (n>=0) {
        ans.push_back(0);
    }
    if (n>=1) {
        ans.push_back(1);
    }
    int head = 1, tail = 1;
    for (int i=2; i<=n ;i++) {
        if (tail==head) {
            ans.push_back(1);
            head = head + tail;
            tail = 1;
        }
        else {
            ans.push_back(ans[head]+ans[tail]);
            tail += 1;
        }
    }
    return ans;
}

vector<int> countBits3(int n) {
    vector<int> res(n+1,0);
    for(int i = 1 ; i<=n ; i++){
        res[i] = res[i&(i-1)]+1 ;
    }
    return res ;
}

int main() {
    vector <int> testcase_n = {2, 5};
    for (int i=0; i<testcase_n.size(); i++) {
        // Method 1: Naive, O(n log n)
        printf("n = %d, output = [", testcase_n[i]);
        for (int num: countBits1(testcase_n[i])) {
            printf("%d, ", num);
        }
        printf("]\n");

        // Method 2: O(n)
        printf("n = %d, output = [", testcase_n[i]);
        for (int num: countBits2(testcase_n[i])) {
            printf("%d, ", num);
        }
        printf("]\n");

        // Method 3: Solution, O(n)
        printf("n = %d, output = [", testcase_n[i]);
        for (int num: countBits3(testcase_n[i])) {
            printf("%d, ", num);
        }
        printf("]\n");
    }
    return 0;
}