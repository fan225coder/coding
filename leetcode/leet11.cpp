class Solution {
    public:
        int maxArea(vector<int>& h) {
            const int n=h.size();
            int i=0,j=n-1;
            int most=0;
            while (i<j) {
                int hi=h[i],hj=h[j];
                most=max(most, min(hi,hj)*(j-i));
                if (hi<=hj) i++;
                if (hi>=hj) j--;
            }
            return most;
        }
};
