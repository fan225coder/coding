class Solution {

    public:
        int longestMountain(vector<int>& a) {
            int ans=0;
            int state=0;
            int count=0;
            for (int i=1;i<a.size();i++) {
                if (a[i]==a[i-1]) {
                    if (state==2) ans=max(ans,count);
                    state=0;
                    count=0;
                } else if (a[i]>a[i-1]) {
                    if (state!=1) {
                        if (state==2) ans=max(ans,count);
                        count=1;
                    }
                    count++;
                    state=1;
                } else { // a[i]<a[i-1]
                    if (state) count++;
                    if (state==1) state=2;
                }
            }
            if (state==2) ans=max(ans,count);
            return ans;
        }
};

