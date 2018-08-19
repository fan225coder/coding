class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> c;
        for (char ch:s) {
            if (!c.count(ch)) c[ch]=0;
            c[ch]++;
        }
        int ans=0;
        bool odd=false;
        for (auto it:c) {
            int add=it.second/2*2;
            ans+=add;
            if (it.second-add) odd=true;
        }
        if (odd) ans++;
        return ans;
    }
};
