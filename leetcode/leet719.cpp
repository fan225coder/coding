class Solution {
    public:
        int smallestDistancePair(vector<int>& a, int k) {
            const int n=a.size();
            sort(a.begin(), a.end());

            int max_le;

            auto count=[&](int x) {
                int c=0;
                max_le=0;
                int r=0;
                for (int l=0;l<n;l++) {
                    while (r+1<n && a[r+1]-a[l]<=x) r++;
                    if (r<=l) {
                        r++;
                    } else {
                        max_le=max(max_le, a[r]-a[l]);
                        c+=r-l;
                        if (c>k) break;
                    }
                }
                return c;
            };

            int lo=a[0], hi=a[n-1];
            while (lo<hi) {
                int mid=lo+(hi-lo)/2;
                int c=count(mid);
                if (c>=k) {
                    if (c==k) return max_le;
                    hi=mid;
                } else {
                    lo=mid+1;
                }

            }
            count(lo);
            return max_le;
        }
};
