class Solution {
    int lower_bound(const vector<int>& A, const int t) {
        int lo=0;
        int hi=A.size()-1;
        while (lo<hi){
            int mid=lo+(hi-lo)/2;
            if (t<=A[mid]) {
                hi=mid;
            } else {
                lo=mid+1;
            }
        }
        return t<=A[lo]?lo:A.size();
    }

    int upper_bound(const vector<int>& A, const int t) {
        int lo=0;
        int hi=A.size()-1;
        while (lo<hi){
            int mid=lo+(hi-lo)/2;
            if (t<A[mid]) {
                hi=mid;
            } else {
                lo=mid+1;
            }
        }
        return t<A[lo]?lo:A.size();
    }

    int last_le(const vector<int>& A, const int t) {
        int lo=0;
        int hi=A.size()-1;
        while (lo<hi){
            int mid=lo+(hi-lo+1)/2;
            if (A[mid]<=t) {
                lo=mid;
            } else {
                hi=mid-1;
            }
        }
        return A[lo]<=t?lo:-1;
    }

    public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1,-1};
        int first=lower_bound(nums, target);
        if (first>=nums.size() || nums[first]!=target) return {-1,-1};
        //int last=upper_bound(nums, target)-1;
        int last=last_le(nums, target);
        return {first, last};
    }
};
