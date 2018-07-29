class Solution {
public:
    bool checkInclusion(string t, string s) {
        if (t.length()>s.length()) return false;
        const int m=t.length();
        const int n=s.length();
        vector<int> count(256,0);
        for (char ch:t) count[ch]++;
        int j=-1;
        for (int i=0;i<=n-m+1;i++) {
            while (j+1<n && count[s[j+1]]) {
                j++;
                count[s[j]]--;
                if (j-i+1==m) return true;
            }
            if (j==n-1) break;
            if (j<i) j++;
            else count[s[i]]++;
        }
        return false;
        
    }
};
