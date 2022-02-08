#include <algorithm> 
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
class O1Solution { // o(n) 
public: 
    int lengthOfLongestSubstring(string s) { 
    int res = 0;  
    int n = s.length(); 
    // vector <int> pre(256, -1);
    int pre[256] = { [0 ... 99] = -1 };
    int i = 0;
    for(int j=0; j<n; j++)
    {
        i = max(i, pre[s[j]]+1);
        int maxc = j-i+1;
        res = max(res, maxc);
        pre[s[j]] = j;
    }
    return res;
    }
};

class O2Solution { // o(n^2)
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        for (int i = 0; i < s.length(); i++)
        {
            unordered_set<char> visited;
            int j = i;
            for (; j < s.length(); j++)
            {
                if (visited.find(s[j])!=visited.end()) {
                    break;
                }   
                else {
                    visited.insert(s[j]);
                }
            }
            max_len = ((j-i)>max_len)?(j-i):max_len;
        }
     return max_len;   
    }
};

class BFSolution { // brute force o(n^3)
public:
    int lengthOfLongestSubstring(string s) {
        for (int i = s.length(); i > 0; i--)
        {
            for (int j = 0; j < s.length()+1-i; j++)
            {
                string ss = s.substr(j, i);
                
                unordered_set<char> visited;
                bool flag = true;
                for (int k=0; k<ss.length(); k++) {
                    if (visited.find(ss[k])!=visited.end()) {
                        flag = false;
                        break;
                    }
                    else {
                        visited.insert(ss[k]);
                    }
                }
                
                if (flag) {
                    return i;
                }

            }
            
        }
        return 0;
    }
};



int main() {
    BFSolution bfsol;
    O1Solution sol1;
    O2Solution sol2;
    string s[] = {" ", "au", "abcabcbb", "bbbbb", "pwwkew", "", "abcabcdbb", "He he he he~_ aababcabcdabcdedcba", "fytwttvvrpqegaqxogzdqyknlpqyanifldeezbcstswzsnyjvxmnvybinrgngqurtyxuazmvrlumyuvvrjjohmwufchls"};
    int num = 5;
    for (auto &e: s)
    {
        cout << "brute force   " << e << ": " << bfsol.lengthOfLongestSubstring(e) << endl;
        cout << "sliding window(o1)" << e << ": " << sol1.lengthOfLongestSubstring(e) << endl;
        cout << "sliding window(o2)" << e << ": " << sol2.lengthOfLongestSubstring(e) << endl;
    }

    return 0;
}
