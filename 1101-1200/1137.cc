int tribonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    int a0 = 0, a1 = 1, a2 = 1, sn;
    for (int i = 2; i < n; i++)
    {
        sn = a0 + a1 + a2;
        a0 = a1;
        a1 = a2;
        a2 = sn;
    }
    return sn;
}