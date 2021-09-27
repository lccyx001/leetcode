int numWays(int n)
{
    if (n == 0 || n == 1)
        return 1;
    int a1 = 1, a2 = 1, sn = 0;
    for (int i = 2; i <= n; i++)
    {
        sn = (a1 + a2) % 1000000007;
        a1 = a2;
        a2 = sn;
    }
    return sn;
}