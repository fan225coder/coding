class Solution {
    public:
        int lengthOfLongestSubstringKDistinct(string s, int k) {
            const int n=s.length();
            unordered_map<char, int> sub;
            int j=-1;
            int len=0;
            for (int i=0;i<n;i++) {
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
                if (j<i){
                    j++;
                    continue;
                }
                if (j==n-1) {
                    len=max(len, j-i+1);
                    break;
                }
                if (sub[s[i]]==1) sub.erase(s[i]);
                else sub[s[i]]--;
            }
            return len;
        }
};
