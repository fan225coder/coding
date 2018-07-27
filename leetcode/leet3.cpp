class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int n=s.length();
        int len=0;
        int j=-1;
        unordered_set<char> occurred;
        for (int i=0;i<n;i++) {
            while (j+1<n && !occurred.count(s[j+1])) {
                occurred.insert(s[j+1]);
                j++;
            }
            if (j-i+1>len) 
                len=j-i+1;
            if (j==n-1) break;
            occurred.erase(s[i]);
        }
        return len;
    }
};
