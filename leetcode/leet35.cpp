class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            if (nums.empty()) return 0;
            int lo=0;
            int hi=nums.size()-1;
            while (lo<hi) {
                int mid=lo+(hi-lo)/2;
                if (target<=nums[mid]) {
                    hi=mid;
                } else {
                    lo=mid+1;
                }
            }
            return target<=nums[lo]?lo:nums.size();
        }
};
