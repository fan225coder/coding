class Solution {
    vector<short> convert(const string& orig) {
        const int n=orig.length();
        vector<short> s(2*n+3, -1);
        s[0]=-2;
        s.back()=-3;
        for (int i=2;(i-1)/2<n;i+=2) s[i]=orig[(i-1)/2];

        return s;
    }

    vector<int> Manacher(const vector<short>& s) {
        const int n=s.size();
        int c=0,r=0;
        vector<int> lps(n,0);
        for (int i=1;i<n-1;i++) {
            if (i<r) {
                int mi=2*c-i;
                lps[i]=min(lps[mi], r-i);
            }
            while (s[i-lps[i]-1]==s[i+lps[i]+1]) lps[i]++;
            if (i+lps[i]>r) {
                r=i+lps[i];
                c=i;
            }
        }
        return lps;
    }

public:
    string longestPalindrome(string orig) {
        auto s = convert(orig);
        auto lps=Manacher(s);

        int ll=0;
        int li=-1;
        for (int i=0;i<lps.size();i++) {
            if (lps[i]>ll) {
                ll=lps[i];
                li=i;
            }
        }

        string ans(lps[li], '*');

        int j=0;
        for (int i=li-lps[li];i<=li+lps[li];i++) {
            if (s[i]>=0) ans[j++]=(char)s[i];
        }

        return ans;
    }
};
