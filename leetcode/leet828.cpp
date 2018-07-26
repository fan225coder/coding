class Solution {
    public:
        int uniqueLetterString(string s) {
            vector<int> pre(256,-1);
            vector<int> cur(256,-1);
            int total=0;
            const int m=1e9+7;

            for (int i=0;i<s.length();i++) {
                auto ch=s[i];
                if (cur[ch]==-1) {
                    cur[ch]=i;
                } else {
                    total+=(cur[ch]-pre[ch])*(i-cur[ch])%m;
                    total%=m;
                    pre[ch]=cur[ch];
                    cur[ch]=i;
                }
            }
            for (char ch='A';ch<='Z';ch++) {
                if (cur[ch]==-1) continue;
                total+=(cur[ch]-pre[ch])*(s.length()-cur[ch])%m;
                total%=m;
            }
            return total;
        }
};
