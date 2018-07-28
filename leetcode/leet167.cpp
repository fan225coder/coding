class Solution {
    public:
        vector<int> twoSum(vector<int>& a, int target) {
            const int n=a.size();
            int j=n-1;
            for (int i=0;i<j;i++) {
                while (j-1>i && a[i]+a[j-1]>=target) j--;
                if (a[i]+a[j]==target) return {i+1,j+1};
                if (j==i+1) break;
            }
            return {}; // error
        }
};
