int sumDivisorsOfDivisors(int n)
{
    // Calculating powers of prime factors and
    // storing them in a map mp[].
    map<int, int> mp;
    for (int j=2; j<=sqrt(n); j++)
    {
        int count = 0;
        while (n%j == 0)
        {
            n /= j;
            count++;
        }

        if (count)
            mp[j] = count;
    }

    // If n is a prime number
    if (n != 1)
        mp[n] = 1;

    // For each prime factor, calculating (p^(a+1)-1)/(p-1)
    // and adding it to answer.
    int ans = 1;
    for (auto it : mp)
    {
        int pw = 1;
        int sum = 0;

        for (int i=it.second+1; i>=1; i--)
        {
            sum += (i*pw);
            pw *= it.first;
        }
        ans *= sum;
    }

    return ans;
}
