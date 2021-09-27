int getMaximumGenerated(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    int maxv = 0;
    int *nums = new int[n + 1]();
    nums[0] = 0;
    nums[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (i % 2 == 0)
            nums[i] = nums[i / 2];
        else
            nums[i] = nums[i / 2] + nums[i / 2 + 1];
        maxv = nums[i] > maxv ? nums[i] : maxv;
    }
    return maxv;
}