class Solution {
    public:
        bool isPalindrome(string s) {
            const int d='a'-'A';
            int i=0,j=s.length()-1;
            while (i<j) {
                while (i<j && !isalnum(s[i])) i++;
                while (i<j && !isalnum(s[j])) j--;
                if (i<j) {
                    const char si=s[i]+(isupper(s[i])?d:0);
                    const char sj=s[j]+(isupper(s[j])?d:0);
                    if (si==sj) {
                        i++;
                        j--;
                    } else {
                        return false;
                    }
                }

            }
            return true;
        }
};
