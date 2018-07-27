class Solution {
    public:
        int lengthOfLongestSubstringTwoDistinct(string s) {
            const int n=s.length();
            const int k=2;
            unordered_map<char, int> sub;
            int i=0,j=-1;
            int len=0;
            while (i<n) {
                while (j+1<n) {
                    char ch=s[j+1];
                    if (sub.size()>=k && !sub.count(ch)) {
                        len=max(len, j-i+1);
                        break;
                    }
                    if (!sub.count(ch)) sub[ch]=0;
                    sub[ch]++;
                    j++;
                }
                if (j==n-1) {
                    len=max(len, j-i+1);
                    break;
                } else {
                    if (sub[s[i]]==1) sub.erase(s[i]);
                    else sub[s[i]]--;
                    i++;
                }
            }
            return len;
        }
};
