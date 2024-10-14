struct Manacher
{
    string preprocess(const string& s)
    {
        string t = "#";
        for (char c : s)
        {
            t += c;
            t += '#';
        }
        return t;
    }

    string LongestPalindromicSubstring(const string& s)
    {
        string T = preprocess(s);
        int n = T.length();
        vector<int> P(n, 0);
        int C = 0, R = 0;
        for (int i = 0; i < n; i++)
        {
            int mirror = 2 * C - i;

            if (i < R)
            {
                P[i] = min(R - i, P[mirror]);
            }

            while (i + P[i] + 1 < n && i - P[i] - 1 >= 0 && T[i + P[i] + 1] == T[i - P[i] - 1])
            {
                P[i]++;
            }

            if (i + P[i] > R)
            {
                C = i;
                R = i + P[i];
            }
        }

        int maxLen = 0;
        int centerIndex = 0;
        for (int i = 0; i < n; i++)
        {
            if (P[i] > maxLen)
            {
                maxLen = P[i];
                centerIndex = i;
            }
        }

        int start = (centerIndex - maxLen) / 2;
        return s.substr(start, maxLen);
    }

}
