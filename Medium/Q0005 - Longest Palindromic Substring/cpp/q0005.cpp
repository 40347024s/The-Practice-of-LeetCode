#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <string.h>

using namespace std;

string longestPalindrome1(string s) {
    string ans = "";
    for (int len=s.length(); len>=0; len--) {
        for (int i=0; i<=s.length()-len; i++) {
            string str1 = s.substr(i, len);
            string str2 = str1;
            reverse(str2.begin(), str2.end());
            if (str1==str2 && ans.length()<str1.length()) {
                ans = str1;
                return ans;
            }
        }
    }
    return ans;
}

string longestPalindrome2(string s) {
    string ans = s.substr(0, 1);
    for (int len=1; len<=2 ; len+=1) { // 1 for even, 2 for odd
        for (int i=0; i<(int)s.length()-len; i++) {
            int bi = i, ei = i+len;
            while (bi >= 0 && ei<=(int)s.length()-1) {
                if (s[bi]==s[ei]) {
                    if ((int)ans.length() < ei-bi+1) {
                        ans = s.substr(bi, ei-bi+1);
                    }
                    bi -= 1;
                    ei += 1;
                }
                else {
                    break;
                }
            }
        }
    }
    return ans;
}

string longestPalindrome3(string s) {
    if (s.empty()) return s;
    
    int best_l = 0;
    int best_r = 1;
    for(size_t i=0; i<s.size(); i++) {
        
        int l = i-1;
        int r = i+1;
        
        // check identical letters
        while(r < s.size() && s[r] == s[i]) {
            r++;
        }
        
        // update i
        i=r-1;
        
        // check left and right
        while(l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        
        // compute length
        int len = r - l - 1;
        
        // update best length
        if (len > best_r - best_l - 1) {
            best_l = l + 1;
            best_r = r;
        }
        
    }
    
    return s.substr(best_l, best_r-best_l);
}

int main() {
    string testcase[6] = {"a", "aaaa", "babad", "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb", "cbbd", "ibvjkmpyzsifuxcabqqpahjdeuzaybqsrsmbfplxycsafogotliyvhxjtkrbzqxlyfwujzhkdafhebvsdhkkdbhlhmaoxmbkqiwiusngkbdhlvxdyvnjrzvxmukvdfobzlmvnbnilnsyrgoygfdzjlymhprcpxsnxpcafctikxxybcusgjwmfklkffehbvlhvxfiddznwumxosomfbgxoruoqrhezgsgidgcfzbtdftjxeahriirqgxbhicoxavquhbkaomrroghdnfkknyigsluqebaqrtcwgmlnvmxoagisdmsokeznjsnwpxygjjptvyjjkbmkxvlivinmpnpxgmmorkasebngirckqcawgevljplkkgextudqaodwqmfljljhrujoerycoojwwgtklypicgkyaboqjfivbeqdlonxeidgxsyzugkntoevwfuxovazcyayvwbcqswzhytlmtmrtwpikgacnpkbwgfmpavzyjoxughwhvlsxsgttbcyrlkaarngeoaldsdtjncivhcfsaohmdhgbwkuemcembmlwbwquxfaiukoqvzmgoeppieztdacvwngbkcxknbytvztodbfnjhbtwpjlzuajnlzfmmujhcggpdcwdquutdiubgcvnxvgspmfumeqrofewynizvynavjzkbpkuxxvkjujectdyfwygnfsukvzflcuxxzvxzravzznpxttduajhbsyiywpqunnarabcroljwcbdydagachbobkcvudkoddldaucwruobfylfhyvjuynjrosxczgjwudpxaqwnboxgxybnngxxhibesiaxkicinikzzmonftqkcudlzfzutplbycejmkpxcygsafzkgudy"};
    // string testcase[4] = {"aa", "aaaa", "ccddcc", "babad"};
    for (int i=0; i<6; i++) {
        // Method 1: Naive
        cout << longestPalindrome1(testcase[i]) << endl;

        // Method 2: O(N^2)
        cout << longestPalindrome2(testcase[i]) << endl;

        // Method 3: Solution from LeetCode
        cout << longestPalindrome3(testcase[i]) << endl;
    }
    return 0;
}
