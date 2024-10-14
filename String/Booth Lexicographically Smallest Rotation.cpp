int booth(string s) {
    s = s + s;
    int n = s.length();
    vector<int> f(n, -1);
    int k = 0;

    for (int j = 1; j < n; ++j) {
        int i = f[j - k - 1];
        while (i != -1 && s[j] != s[k + i + 1]) {
            if (s[j] < s[k + i + 1])
                k = j - i - 1;
            i = f[i];
        }
        if (s[j] != s[k + i + 1]) {
            if (s[j] < s[k])
                k = j;
            f[j - k] = -1;
        } else {
            f[j - k] = i + 1;
        }
    }
    return k;
}
