
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



    int binary_search(int s, vector<int>& a) {
        if (a.empty()) return 0;
        const int n=a.size();
        auto p=[&n,&s,&a](int l) {
            int sum=0;
            for (int i=0;i<l && sum<s;i++) sum+=a[i];
            for (int i=l;i<n && sum<s;i++) sum=sum-a[i-l]+a[i];
            return sum>=s;
        };
        int lo=1;
        int hi=n;
        while (lo<hi) {
            int mid=lo+(hi-lo)/2;
            if (p(mid)) {
                hi=mid;
            } else {
                lo=mid+1;
            }
        }
        if (!p(lo)) return 0;
        return lo;
    }
    public:
    int minSubArrayLen(int s, vector<int>& a) {
        //return two_pointer(s,a);
        return binary_search(s, a);
    }
};

