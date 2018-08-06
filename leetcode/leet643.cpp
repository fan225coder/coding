class Solution {
public:
    double findMaxAverage(vector<int>& a, int k) {
        const int n=a.size();
        int sum=0;
        for (int i=0;i<k;i++) sum+=a[i];
        int max_sum=sum;
        for (int i=k;i<n;i++) {
            sum+=a[i]-a[i-k];
            max_sum=max(max_sum,sum);
        }
        return (double)max_sum/k;
    }
};
