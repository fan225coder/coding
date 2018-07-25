class Solution {
    double frac(int n, int d){
        return (double)n/d;
    }
    bool predicate(const vector<int>& a, const int k, const double bound, int& count, vector<int>& ans) {
        const int n=a.size();
        double max_f=1;
        int i=0;
        int j=0;
        while (count<=k && i<n){
            while (count<=k && j+1<n && frac(a[j+1],a[i])<=bound) j++; // linear scan or binary search
            if (j<=i) {
                i++;
                j++;
            } else {
                if (frac(a[j],a[i])>max_f) {
                    max_f=frac(a[j],a[i]);
                    ans[0]=a[i];
                    ans[1]=a[j];
                }
                const int d=j-i;
                if (j==n-1) {
                    count+= d%2 ? (d+1)/2*d : d/2*(d+1); // avoid overflow
                    break;
                }
                count+=d;
                i++;
            }
        }
        return count>=k;
    }
    public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        const int n=A.size();
        // finding K-th smallest p/q is equal to fining k= n*(n-1)/2 - K + 1 largest p/q
        const int k=n*(n-1)/2-K+1;
        // fining k largest p/q is equal to finding k smallest q/p
        double lo=1;
        double hi=A[n-1]/A[0];
        vector<int> ans(2);
        while (lo<hi){
            double mid=lo+(hi-lo)/2;
            int count_le=0;
            if (predicate(A,k,mid,count_le,ans)){
                if (count_le==k){
                    break;
                } else {
                    hi=mid;
                }
            } else {
                lo=mid;
            }
        }
        return ans;
    }
};

