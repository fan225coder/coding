class Solution {
    int two_pointer(int s, vector<int>& a) {
        const int n=a.size();
        int i=0;
        int j=-1;
        int sum=0;
        int ans=n+1;
        while (i<n) {
            while (j+1<n && sum+a[j+1]<s) {
                j++;
                sum+=a[j];
            }
            if (j<i) {
                ans=min(ans,j+1-i+1);
                i++;j++;
            }else if (j==n-1) {
                break;
            }else {
                ans=min(ans,j+1-i+1);
                sum-=a[i];
                i++;
            }
        }
        return ans==n+1?0:ans;
    }
    public:
    int minSubArrayLen(int s, vector<int>& a) {
        return two_pointer(s,a);
    }
};
