class Solution {
    public:
        int kthSmallest(vector<vector<int>>& a, int k) {
            const int n=a.size();
            // a is square and n>0
            int max_le;
            auto count = [&](int x) {
                int c=0; // count number of elements <= x
                int j=n;
                max_le=a[0][0];
                for (int i=0;i<n;i++) {
                    while (j-1>=0 && a[i][j-1]>x) j--;
                    if (j==0) break;
                    max_le=max(max_le, a[i][j-1]);
                    c+=j;
                    if (c>k) break;
                }
                return c;
            };

            int lo=a[0][0];
            int hi=a[n-1][n-1];

            while (lo<hi) {
                int mid=lo+(hi-lo)/2;
                int c=count(mid);
                if (c>=k) {
                    if (c==k) return max_le;
                    hi=mid;
                } else {
                    lo=mid+1;
                }
            }
            int c=count(lo);
            // assert c == k
            return max_le;

        }
};
