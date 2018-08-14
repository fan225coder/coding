class Solution {
    public:
        int countSubstrings(string orig) {
            vector<short> s(orig.length()*2+3, -1);
            s[0]=-2;
            for (int i=2;(i-2)/2<orig.length();i+=2) {
                s[i]=orig[(i-2)/2];
            }
            s.back()=-3;

            vector<int> lps(s.size(), 0);
            int c=0, r=0;
            for (int i=1;i<s.size()-1;i++) {
                int mi=c*2-i;
                if (i<r) {
                    lps[i]=min(r-i,lps[mi]);
                }

                while (s[i-lps[i]-1]==s[i+lps[i]+1]) {
                    lps[i]++;
                }

                if (i+lps[i]>r) {
                    r=i+lps[i];
                    c=i;
                }

            }

            int sum=0;
            for (int l:lps) sum+=(l+1)/2;

            return sum;


        }
};
