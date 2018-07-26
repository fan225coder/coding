class Solution {
    public:
        string minWindow(string s, string t) {
            int total=t.length();
            vector<int> remain(256,0);
            for (auto c:t) remain[c]++;

            const int n=s.length();
            int i=0, j=-1;
            int ii, len=n+1;
            while (i<n) {
                while (j+1<n) {
                    char c=s[j+1];
                    remain[c]--;
                    if (remain[c]>=0) total--;
                    if (total==0) {
                        if (j-i+2<len) {
                            ii=i;
                            len=j-i+2;
                        }
                        remain[c]++;
                        total++;
                        break;
                    }
                    j++;
                }
                if (j<i) {
                    return s.substr(i,1);
                } else if (j==n-1) {
                    break;
                } else {
                    char c=s[i];
                    remain[c]++;
                    if (remain[c]>0) total++;
                    i++;
                }
            }
            return len==n+1?"":s.substr(ii,len);
        }
};
