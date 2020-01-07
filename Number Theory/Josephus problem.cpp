///complexity O(N)
int josephus(int n, int k)
{
  if (n == 1)
    return 1;
  else
    return (josephus(n - 1, k) + k-1) % n + 1;
}

///When k==2, Complexity O(Log n).
int josephus(int n)
{
    // Find value of 2 ^ (1 + floor(Log n))
    // which is a power of 2 whose value
    // is just above n.
    int p = 1;
    while (p <= n)
        p *= 2;

    // Return 2n - 2^(1+floor(Logn)) + 1
    return (2 * n) - p + 1;
}
