struct HashingBIT {
public:
    int len;
    ll base = 313;
    static const ll mod = 1e9 + 7;
    vector<ll> pw, bitF, bitR;

    HashingBIT(const string &str, ll base) : base(base), len(str.length()) {
        pw.assign(len + 2, 1);
        bitF.assign(len + 2, 0);
        bitR.assign(len + 2, 0);

        for (int i = 1; i <= len; i++) {
            pw[i] = (pw[i - 1] * base) % mod;
        }

        for (int i = 1; i <= len; i++) {
            bitUpdate(bitF, i, (str[i - 1] * pw[i - 1]) % mod);
            bitUpdate(bitR, i, (str[len - i] * pw[i - 1]) % mod);
        }
    }

    void bitUpdate(vector<ll> &bit, int idx, ll delta) {
        while (idx <= len) {
            bit[idx] = (bit[idx] + delta + mod) % mod;
            idx += idx & -idx;
        }
    }

    ll bitQuery(const vector<ll> &bit, int idx) {
        ll sum = 0;
        while (idx > 0) {
            sum = (sum + bit[idx] + mod) % mod;
            idx -= idx & -idx;
        }
        return sum;
    }

    void update(int idx, char newChar) {
        ll currentHashF = (bitQuery(bitF, idx) - bitQuery(bitF, idx - 1) + mod) % mod;
        ll newHashF = (newChar * pw[idx - 1]) % mod;
        bitUpdate(bitF, idx, (newHashF - currentHashF + mod) % mod);

        int rIdx = len - idx + 1;
        ll currentHashR = (bitQuery(bitR, rIdx) - bitQuery(bitR, rIdx - 1) + mod) % mod;
        ll newHashR = (newChar * pw[rIdx - 1]) % mod;
        bitUpdate(bitR, rIdx, (newHashR - currentHashR + mod) % mod);
    }

    ll getForwardHash(int l, int r) {
        ll result = (bitQuery(bitF, r) - bitQuery(bitF, l - 1) + mod) % mod;
        return (result * pw[len - r]) % mod;
    }

    ll getBackwardHash(int l, int r) {
        int rl = len - r + 1, rr = len - l + 1;
        ll result = (bitQuery(bitR, rr) - bitQuery(bitR, rl - 1) + mod) % mod;
        return (result * pw[len - rr]) % mod;
    }

    ll getCombinedHash(int l1, int r1, int l2, int r2) {
        ll hash1 = getForwardHash(l1, r1);
        ll hash2 = getForwardHash(l2, r2);
        return ((hash1 * pw[r2 - l2 + 1]) % mod + hash2) % mod;
    }

    bool isPalin(int l, int r) {
        return r >= l && getForwardHash(l, r) == getBackwardHash(l, r);
    }
};
