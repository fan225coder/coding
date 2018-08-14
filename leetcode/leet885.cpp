class Solution {
    public:
        int numRescueBoats(vector<int>& a, int limit) {
            sort(a.begin(), a.end());

            int i=0,j=a.size()-1;
            int b=0; // boat

            while (i<j) {
                if (a[i]+a[j]<=limit) i++;
                j--;
                b++;
            }

            if (i==j) b++;
            return b;

        }
};
