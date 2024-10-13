struct Hashing
{
    ///bases:100001,313,3797,717,1337
    int len;
    ll base = 313;
    static const ll mod = 1e9+7;
    vector<ll> hashF, hashR, pw;

    Hashing(const string& str,ll base):base(base)
    {
        len = str.length();
        hashF.assign(len + 2, 0);
        hashR.assign(len + 2, 0);
        pw.assign(len + 2, 1);

        for (int i = 1; i <= len; i++)
        {
            pw[i] = (pw[i - 1]*base)%mod;
        }

        for (int i = 1; i <= len; i++)
        {
            hashF[i] = ((hashF[i - 1]*base)%mod + str[i - 1]) % mod;
            hashR[len - i + 1] = ((hashR[len - i + 2]*base)%mod + str[len - i]) % mod;
        }
    }

    ll getForwardHash(int l, int r)
    {
        if (l == 1) return hashF[r];
        return (hashF[r] - (hashF[l - 1]*pw[r - l + 1])%mod + mod) % mod;
    }

    ll getBackwardHash(int l, int r)
    {
        if (r == len) return hashR[l];
        return (hashR[l] - (hashR[r + 1]*pw[r - l + 1])%mod + mod) % mod;
    }

    ll getCombinedHash(int l1, int r1, int l2, int r2)
    {
        ll hash1 = getForwardHash(l1, r1);
        ll hash2 = getForwardHash(l2, r2);
        int len1 = r2 - l2 + 1;
        ll combinedHash = (hash1 * pw[len1]) % mod;
        combinedHash = (combinedHash + hash2) % mod;
        return combinedHash;
    }

    bool isPalin(int l, int r)
    {
        if (r < l) return false;
        return getForwardHash(l, r) == getBackwardHash(l, r);
    }
};
