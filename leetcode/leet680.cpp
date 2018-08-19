class Solution {
    public:
        bool validPalindrome(string s) {

            auto pal=[&](int i, int j) {
                while (i<j) {
                    if (s[i++]!=s[j--]) return false;
                }
                return true;
            };

            int i=0, j=s.length()-1;
            int d=0;
            while (i<j && s[i]==s[j]) {
                i++;
                j--;
            }
            if (i<j && !pal(i+1,j) && !pal(i,j-1)) return false;

            return true;

        }
};
