#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stdio.h>

using namespace std;

bool checkInclusion1(string s1, string s2) {
    unordered_map<char, int> s1_table;
    for (auto e: s1) {
        s1_table[e]++;
    }
    for (int i=0; i<=(int)s2.length()-(int)s1.length(); i++) {
        unordered_map<char, int> s1_table_copy = s1_table;
        int remain_len = s1.length();
        for (int j=i; j<=s2.length(); j++) {
            if (s1_table_copy[s2[j]]) {
                s1_table_copy[s2[j]]--;
                remain_len--;
            }
            else {
                break;
            }
        }
        if (remain_len==0) {
            return true;
        }
    }
    return false;
}

bool checkInclusion2(string s1, string s2) {
    unordered_map< char, int >mp;    //Use hashmap to store the frequencies of all the characters present in string s1.
    for(auto it : s1){
        mp[it]++;
    }
    int count = mp.size();         //Use the count variable to see if all of the characters in the map have the same frequency, indicating that an anagram has been found.
    int i = 0, j = 0;
    int k = s1.size();             //Window Size
    while(j < s2.size()){
        if(mp.find(s2[j]) != mp.end()){      //If a character is found that already exists in the map, reduce its frequency by one.
            mp[s2[j]]--;
            if(mp[s2[j]] == 0){     //If the frequency of a specific character on the map is 0, it means that all occurrences of that character is found inside the current window size.
                count--;
            }
        }
        if(j-i+1 < k){
            j++;
        }
        else if(j-i+1 == k){
            if(count == 0){    //Anagram found 
                return true;
            }
            if(mp.find(s2[i]) != mp.end()){  //Check if that character is present in the map while sliding the window, then increase its frequency by one, as we decreased its frequency when we first met it while crossing the window.
                mp[s2[i]]++;
                if(mp[s2[i]] == 1){
                    count++;
                }
            }
            i++;
            j++;
        }
    }
    return false;
}

bool checkInclusion3(string s1, string s2) {
    unordered_map<char, int> s1_table;
    for (auto e: s1) {
        s1_table[e]++;
    }
    int remain_len = s1.length();
    int i = 0, j = 0;
    while (j < (int)s2.length()) {
        if (s1_table.find(s2[j])!=s1_table.end() && s1_table[s2[j]]>0) {
            remain_len--;
            s1_table[s2[j]]--;
        }
        if (remain_len==0) {
            return true;
        }
        if ((j-i+1) == (int)s1.length()) {
            if (s1_table.find(s2[i])!=s1_table.end() && s2[i]!=s2[j]) {
                remain_len++;
                s1_table[s2[i]]++;
            }
            i++;
        }
        j++;
    }

    return false;
}

void swap(string &ans, int i, int j) {
    char tmp = ans[j];
    ans[j] = ans[i];
    ans[i] = tmp;
}

void Permutation1(string ans, int start) {
    if (start==ans.length()) {
        cout << ans << endl;
    }
    for (int i=start; i<ans.length(); i++) {
        swap(ans, i, start);
        Permutation1(ans, start + 1);
        swap(ans, i, start);
    }
}

void Permutation2(string ans) {
    int *ans_arr = new int[ans.length()];
    for (int i=0; i<ans.length(); i++) {
        ans_arr[i] = ans[i];
    }
    sort(ans_arr, ans_arr+ans.length());
    bool is_finish = false;
    while (!is_finish) {
        // Print current permutation
        for (int i=0; i<ans.length(); i++) {
            cout << (char)ans_arr[i];
        }
        cout << endl;
        is_finish = true;
        int cur;
        for (cur = ans.length()-2; cur >= 0; cur--) {
            if (ans_arr[cur] < ans_arr[cur+1]) {
                is_finish = false;
                break;
            }
        }
        if (is_finish) {
            continue;
        }
        int swap_idx;
        for (swap_idx = ans.length()-1; swap_idx > cur; swap_idx--) {
            if (ans_arr[cur] < ans_arr[swap_idx]) {
                // printf("cur: %d, swap_idx: %d\n", cur, swap_idx);
                int tmp = ans_arr[cur];
                ans_arr[cur] = ans_arr[swap_idx];
                ans_arr[swap_idx] = tmp;
                reverse(ans_arr+cur+1, ans_arr+ans.length());
                break;
            }
        }
    }
    delete[] ans_arr;
}


int main() {
    // Method 1: Recursion, contains duplicated permutations.
    Permutation1("ccba", 0);
    cout << "----------------" << endl;
    // Method 2: Lexicographic order, contains completely different permutations.
    Permutation2("ccba");
    cout << "----------------" << endl;
    vector<string> testcase_str1 = {"ab", "ab", "acd", "ab", "abc"};
    vector<string> testcase_str2 = {"eidbaooo", "eidboaoo", "dcda", "a", "bbbca"};
    for (int i=0; i< testcase_str1.size(); i++) {
        // Method 1: O(N^2)
        printf("%s in %s? => %d\n", testcase_str1[i].c_str(), testcase_str2[i].c_str(), checkInclusion1(testcase_str1[i], testcase_str2[i]));
        // Method 2: Solution from Leetcode
        printf("%s in %s? => %d\n", testcase_str1[i].c_str(), testcase_str2[i].c_str(), checkInclusion2(testcase_str1[i], testcase_str2[i]));
        // Method 3: Rewrite method1
        printf("%s in %s? => %d\n", testcase_str1[i].c_str(), testcase_str2[i].c_str(), checkInclusion3(testcase_str1[i], testcase_str2[i]));
        cout << "----------------" << endl;
    }
    return 0;
}
