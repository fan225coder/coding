class Solution {
    vector<short> s;
    vector<int> lps;

    void convert(const string& orig) {
        const int l=orig.length();
        s=vector<short>(l*2+3,-1);
        s.front()=-2;
        s.back()=-3;
        for (int i=0;i<l;i++) s[(i+1)*2]=orig[i];
    }


    void Manacher(const vector<short>& s) {
        const int n=s.size();
        lps=vector<int>(n, 0);
        int c=0;
        for (int i=1;i<n-1;i++) {
            if (i<lps[c]+c) {
                lps[i]=min(lps[2*c-i], lps[c]+c-i);
            }
            while (s[i+lps[i]+1]==s[i-lps[i]-1]) lps[i]++;
            if (i+lps[i]>c+lps[c]) c=i;
        }

    }

    vector<string> extract(const vector<int>& p, const int k) {
        vector<string> pp;
        for (int i=1;i<=k;i++) {
            string ps;
            for (int j=p[i-1];j<=p[i];j++) {
                if (s[j]>=0) ps+=(char)s[j];
            }
            if (ps.length()) pp.push_back(ps);
        }
        return pp;
    }

    vector<vector<string>> ans;

    vector<int> p;
    int k;

    void partition(int i, int k) {
        p[k]=i;
        if (i>=s.size()-2) {
            ans.push_back(extract(p, k));
        } else {
            for (int j=i+1;j<s.size()-1;j++){
                if (j-lps[j]<=i) {
                    partition(2*j-i, k+1);
                }
            }
        }
    }

    public:
    vector<vector<string>> partition(string orig) {
        convert(orig);
        Manacher(s);
        p=vector<int>(s.size(),0);
        partition(1, 0);

        return ans;

    }
};
