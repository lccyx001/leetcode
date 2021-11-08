int firstBadVersion(int n)
{
    int left = 1, right = n;
    int mid = left + (right - left) / 2;
    while (left < right)
    {
        if (isBadVersion(mid))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
        mid = left + (right - left) / 2;
    }
    return mid;
}