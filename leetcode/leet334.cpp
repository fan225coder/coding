class Solution {
public:
    bool increasingTriplet(vector<int>& a) {
        vector<int> t;
        for (int x:a) {
            int i=0;
            while (i<t.size() && t[i]<x) i++;
            if (i<t.size()) {
                t[i]=x;
            } else {
                t.push_back(x);
                if (t.size()>=3) return true;
            }
        }
        return false;
    }
};
