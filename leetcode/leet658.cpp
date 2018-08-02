class Solution {
    public:
        vector<int> findClosestElements(vector<int>& a, int k, int x) {
            const int n=a.size();
            int lo=0, hi=n-1;
            while (lo<hi) {
                int mid=lo+(hi-lo)/2;
                if (a[mid]<x) {
                    lo=mid+1;
                } else {
                    hi=mid;
                }
            }
            int en=a[lo]<x ? n : lo;
            int st=en-1;
            vector<int> res;
            res.reserve(k);
            for (int i=0;i<k;i++) {
                if (en>=n) {
                    st--;
                } else if (st<0) {
                    en++;
                } else {
                    if (x-a[st]<=a[en]-x) st--;
                    else en++;
                }
            }
            for (int i=st+1;i<en;i++) {
                res.push_back(a[i]);
            }
            return res;

        }
};
