class Solution {
    public:
        int numSubarrayProductLessThanK(vector<int>& a, int k) {
            const int n=a.size();
            int i=0;
            int j=-1;
            int q=1;
            int count=0;
            while (i<n){
                while (j+1<n && q*a[j+1]<k) {
                    j++;
                    q*=a[j];
                }
                if (j<i) {
                    i++;
                    j++;
                } else if (j==n-1) {
                    int d=j-i+1;
                    count+= d%2 ? (d+1)/2*d : d/2*(d+1);
                    break;
                } else {
                    count+=j-i+1;
                    q/=a[i];
                    i++;
                }
            }
            return count;
        }
};
