class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char,int> c;
        for (char ch:s) {
            if (!c.count(ch)) c[ch]=0;
            c[ch]++;
        }
        bool odd=false;
        for (auto it:c) {
            if (it.second%2) {
                if (odd) return false;
                odd=true;
            }
        }
        return true;
    }
};
