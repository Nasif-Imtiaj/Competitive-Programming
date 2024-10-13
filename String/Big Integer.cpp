struct BigInteger
{
    string add(string x, string y)
    {
        int len1 = x.length() - 1, len2 = y.length() - 1;
        string ans;
        int carry = 0;

        while (len1 >= 0 || len2 >= 0 || carry)
        {
            int a = (len1 >= 0) ? x[len1--] - '0' : 0;
            int b = (len2 >= 0) ? y[len2--] - '0' : 0;
            int sum = a + b + carry;
            carry = sum / 10;
            ans += (sum % 10) + '0';
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    string subtract(string x, string y)
    {
        int len1 = x.length() - 1, len2 = y.length() - 1;
        string ans;
        int carry = 0;

        while (len1 >= 0 || len2 >= 0)
        {
            int a = (len1 >= 0) ? x[len1--] - '0' : 0;
            int b = (len2 >= 0) ? y[len2--] - '0' : 0;

            if (carry)
            {
                a--;
                carry = 0;
            }

            if (a < b)
            {
                a += 10;
                carry = 1;
            }

            ans += (a - b) + '0';
        }

        reverse(ans.begin(), ans.end());

        while (ans[0] == '0' && ans.length() > 1)
            ans.erase(ans.begin());

        return ans;
    }


    string multiply(string x, string y)
    {
        if (x == "0" || y == "0") return "0";

        int len1 = x.length(), len2 = y.length();
        vector<int> result(len1 + len2, 0);

        for (int i = len1 - 1; i >= 0; i--)
        {
            for (int j = len2 - 1; j >= 0; j--)
            {
                int mul = (x[i] - '0') * (y[j] - '0');
                int sum = mul + result[i + j + 1];

                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }

        string ans;
        for (int num : result)
        {
            if (!(ans.empty() && num == 0))
                ans += to_string(num);
        }

        return ans.empty() ? "0" : ans;
    }

    string intToString(int a)
    {
        if (a == 0) return "0";

        string ans;
        while (a > 0)
        {
            ans += (a % 10) + '0';
            a /= 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

};
