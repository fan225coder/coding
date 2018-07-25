class Solution {
    public:
        int peakIndexInMountainArray(vector<int>& A) {
            // assert(A.size()>=3)
            int lo=0;
            int hi=A.size()-1;
            while (lo<hi) {
                int mid=lo+(hi-lo)/2;
                if (/*mid<A.size()-1 && */A[mid]>A[mid+1]) {
                    hi=mid;
                } else {
                    lo=mid+1;
                }
            }
            // assert(lo<A.size()-1 && A[lo]>A[lo+1])
            return lo;
        }
};
