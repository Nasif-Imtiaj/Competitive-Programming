struct ZAlgorithm
{
    vector<int> zFunction(const std::string &s)
    {
        int n = s.size();
        vector<int> z(n, 0);
        int l = 0, r = 0;

        for (int i = 1; i < n; ++i)
        {
            if (i > r)
            {
                l = r = i;
                while (r < n && s[r] == s[r - l])
                {
                    r++;
                }
                z[i] = r - l;
                r--;
            }
            else
            {
                int k = i - l;
                if (z[k] < r - i + 1)
                {
                    z[i] = z[k];
                }
                else
                {
                    l = i;
                    while (r < n && s[r] == s[r - l])
                    {
                        r++;
                    }
                    z[i] = r - l;
                    r--;
                }
            }
        }
        return z;
    }

    vector<int> substringOccurrences(const string &text, const string &pattern)
    {
        string concat = pattern + "$" + text;
        vector<int> Z = ZAlgorithm(concat);
        vector<int> occurrences;

        for (int i = 0; i < Z.size(); ++i)
        {
            if (Z[i] == pattern.size())
            {
                occurrences.push_back(i - pattern.size() - 1);
            }
        }
        return occurrences;
    }

    bool isSubstring(const string &text, const string &pattern)
    {
        return !substringOccurrences(text, pattern).empty();
    }

    int longestCommonPrefix(const string &s1, const string &s2)
    {
        string concat = s1 + "#" + s2;
        vector<int> Z = ZAlgorithm(concat);
        return Z[s1.size() + 1] == std::min(s1.size(), s2.size());
    }
};
