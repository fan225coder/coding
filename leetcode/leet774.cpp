class Solution {
    public:
        double minmaxGasDist(vector<int>& stations, int K) {
            vector<int> gap(stations.size()-1);
            for (int i=1; i<stations.size(); i++) {
                gap[i-1]=stations[i]-stations[i-1];
            }
            sort(gap.begin(),gap.end());
            double lo=0,hi=gap.back();
            const double e=1E-6;
            auto p=[&](double x) {
                int k=K;
                int i=gap.size()-1;
                while (i>=0 && k>=0 && gap[i]>x) {
                    k-=ceil(gap[i--]/x)-1;
                }
                return k>=0;
            };
            while (lo<hi-e) {
                double mid=(lo+hi)/2;
                if (p(mid)) {
                    hi=mid;
                } else {
                    lo=mid;
                }
            }
            return lo;
        }
};
