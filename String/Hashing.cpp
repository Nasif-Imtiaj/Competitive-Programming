/*const int base = 1337;
ll pw[300015];
void pre_power()
{
    pw[0] = 1;
    for(int i = 1; i < 300015; i++)
    {
        pw[i] = (pw[i - 1] * base) % MOD;
    }
}
ll get_hashval(string str, int len)
{
    ll hash_val=0;
    for(int i = 0; i < len; i++)
    {
        hash_val=(hash_val*pw[i])+str[i];
    }
    return hash_val;
}


void Hash_pattern_search(string str, int len)
{
    ull hash_val = 0;
    for(int i = 0; i < len; i++)
    {
        hash_val = (hash_val * base + str[i]);
        Hash_pattern[i + 1] = hash_val;
    }
}
ll SubstringHash1(int l, int r,int pos)
{
    return (Hash[pos][r] - (Hash[pos][l - 1] * pw[r - l + 1]) % MOD + MOD) % MOD;
}
ll SubstringHash2(int l, int r)
{
    return (Hash_pattern[r] - (Hash_pattern[l - 1] * pw[r - l + 1]) % MOD + MOD) % MOD;
}*/

const int base = 1337;
ll pw[300015];
ll HASH[300015];
void pre_power()
{
    pw[0] = 1;
    for(int i = 1; i < 300015; i++)
    {
        pw[i] = (pw[i - 1] * base) % MOD;
    }
}
void get_hashval(string str, int len)
{
    ll hash_val=0;
    for(int i = 0; i < len; i++)
    {
        hash_val=(hash_val*pw[i])+str[i];
        HASH[i]=hash_val;
    }
}
ll SubstringHash(int l, int r)
{
    return (HASH[r] - (HASH[l - 1] * pw[r - l + 1]) % MOD + MOD) % MOD;
}
