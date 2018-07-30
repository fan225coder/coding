class Solution {
public:
    int findMin(vector<int>& a) {
        // assert(!a.empty())
        const int n=a.size();
        int lo=0,hi=n-1;
        while (lo<hi) {
            int mid=lo+(hi-lo)/2;
            if (a[0]>a[mid]) {
                hi=mid;
            } else {
                lo=mid+1;
            }
        }
        if (a[0]<a[lo]) return a[0];
        return a[lo];
    }
};
