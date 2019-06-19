int Solution::isScramble(const string s1, const string s2) 
{
        if (s1.length() != s2.length())
            return 0;
        if (s1.length() == 0 || s1==s2)
            return 1;
         
        int length = s1.length();
        bool scramble[length][length][length];
         
        for (int i = 0; i < length; i++) 
        {
            for (int j = 0; j < length; j++) 
                scramble[0][i][j] = (s1[i]==s2[j]) ? true : false;
        }
         
        for (int len = 2; len <= length; len++) 
        { 
            for (int i = 0; i <= length - len; i++) 
            {
                for (int j = 0; j <= length - len; j++) 
                {
                    bool r = false;
                    for (int k = 1; k < len && r == false; k++) 
                        r = (scramble[k - 1][i][j] && scramble[len - k - 1][i + k][j + k])|| (scramble[k - 1][i][j + len - k] && scramble[len - k - 1][i + k][j]);
                    scramble[len - 1][i][j] = r;
                }
            }
        }
        return scramble[length - 1][0][0];
}
