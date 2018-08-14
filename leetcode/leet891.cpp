class Solution {
    unordered_map<int, unordered_map<int, int>> ans;
    int solve(int k, int n) {
        if (ans.count(k) && ans[k].count(n)) return ans[k][n];
        if (k==1) return n;
        int kk=ceil(log2(n+1));
        if (kk<=k) return kk;

        int lo=2,hi=n-1;
        int best=numeric_limits<int>::max();
        while (lo<hi) {
            int mid=lo+(hi-lo)/2;
            int l=solve(k-1, mid-1);
            int r=solve(k, n-mid);
            //printf("l=%d, r=%d\n", l, r);
            best=min(best,max(l,r));
            if (l==r) {
                break;
            } else if (l<r) {
                lo=mid+1;
            } else {
                hi=mid;
            }
        }
        best++;
        if (!ans.count(k)) ans[k]=unordered_map<int,int>();
        if (!ans[k].count(n)) ans[k][n]=best;
        return best;
    }
public:
    int superEggDrop(int K, int N) {
        return solve(K, N);
    }
};
