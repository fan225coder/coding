class Solution {
    public:
        int minEatingSpeed(vector<int>& piles, int H) {

            int hi=0;
            int sum=0;
            for (int x:piles) {
                sum+=x;
                hi=max(hi,x);
            }
            int lo=(sum+H-1)/H;

            auto predicate=[&](int k) {
                if (sum/k>H) return false;
                int c=0;
                for (int x:piles) {
                    c+=(x+k-1)/k;
                    if (c>H) break;
                }
                return c<=H;
            };

            while (lo<hi) {
                int mid=lo+(hi-lo)/2;
                if (predicate(mid)) {
                    hi=mid;
                } else {
                    lo=mid+1;
                }
            }

            return lo;
        }
};
