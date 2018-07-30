class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int lo=0,hi=a.size()-1;
        while (lo<hi) {
            int mid=lo+(hi-lo)/2;
            if (mid>0 && a[mid-1]>a[mid]) {
                // left neighbour is larger
                hi=mid-1;
            } else if (mid<a.size()-1 && a[mid+1]>a[mid]) { 
                // right neighbour is larger
                lo=mid+1;
            } else {
                return mid;
            }
        }
        return lo;
    }
};
