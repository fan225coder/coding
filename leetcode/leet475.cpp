class Solution {

    public:
        int findRadius(vector<int>& houses, vector<int>& heaters) {
            const int n=heaters.size();
            sort(heaters.begin(),heaters.end()); // n*log(n)

            auto search=[&](int x) {
                int lo=0, hi=n-1;
                while (lo<hi) {
                    int mid=lo+(hi-lo)/2;
                    if (x<=heaters[mid]) {
                        hi=mid;
                    } else {
                        lo=mid+1;
                    }
                }
                if (heaters[lo]<x) return x-heaters[lo];
                else if (lo==0) return heaters[lo]-x;
                return min(heaters[lo]-x,x-heaters[lo-1]);
            };

            int radius=0;

            for (int h:houses) radius=max(radius, search(h));
            return radius;

        }
};
