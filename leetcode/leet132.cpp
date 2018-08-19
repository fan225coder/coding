class Solution {
    vector<short> s;
    vector<int> lps;
    int R(const int i) {return i+lps[i];};
    int L(const int i) {return i-lps[i];};
    void Manacher(const string& orig) {
        s=vector<short>(orig.length()*2+3, -1);
        s.front()=-2;
        s.back()=-3;
        for (int i=0;i<orig.length();i++) s[(i+1)*2]=orig[i];
        lps=vector<int>(s.size(), 0);
        int c=1;
        for (int i=2;i<s.size()-2;i++) {
            if (i<R(c)) lps[i]=min(lps[c*2-i], R(c)-i);
            while (s[R(i)+1]==s[L(i)-1]) lps[i]++;
            if (R(i)>R(c)) c=i;
        }
    }

    bool check(int i, int j) {
        int c=i+j+2;
        return L(c)<=(i+1)*2 && R(c)>=(j+1)*2;
    }

    public:
    int minCut(string orig) {
        Manacher(orig);
        const int n=orig.length();

        vector<int> dp(n, n+1);

        for (int i=0;i<n;i++) {
            if (check(0,i)) dp[i]=0;
            else {
                for (int j=0;j<i;j++) {
                    if (check(j+1,i)) {
                        dp[i]=min(dp[i], dp[j]+1);
                    }
                }
            }
        }

        return dp[n-1];
    }
};
