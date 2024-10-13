#include <vector>
#include <string>
using namespace std;

struct KMP
{
    vector<int> buildLPS(const string &pattern)
    {
        int m = pattern.size();
        vector<int> lps(m);
        int len = 0;
        lps[0] = 0;

        for (int i = 1; i < m; )
        {
            if (pattern[i] == pattern[len])
            {
                lps[i++] = ++len;
            }
            else if (len)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i++] = 0;
            }
        }
        return lps;
    }

    vector<int> substringOccurrences(const string &text, const string &pattern)
    {
        int n = text.size(), m = pattern.size();
        vector<int> lps = buildLPS(pattern), result;
        int i = 0, j = 0;

        while (i < n)
        {
            if (pattern[j] == text[i])
            {
                i++;
                j++;
            }
            if (j == m)
            {
                result.push_back(i - j);
                j = lps[j - 1];
            }
            else if (i < n && pattern[j] != text[i])
            {
                j ? j = lps[j - 1] : i++;
            }
        }
        return result;
    }

    bool isSubstring(const string &text, const string &pattern)
    {
        int n = text.size(), m = pattern.size();
        if (m == 0) return true;
        vector<int> lps = buildLPS(pattern);
        int i = 0, j = 0;

        while (i < n)
        {
            if (pattern[j] == text[i])
            {
                i++;
                j++;
            }
            if (j == m) return true;
            else if (i < n && pattern[j] != text[i])
            {
                j ? j = lps[j - 1] : i++;
            }
        }
        return false;
    }

    int longestCommonPrefix(const string &s1, const string &s2)
    {
        string concat = s1 + "#" + s2;
        vector<int> lps = buildLPS(concat);
        return lps.back();
    }
};
