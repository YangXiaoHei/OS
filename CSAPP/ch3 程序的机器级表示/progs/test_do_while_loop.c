int fun(int x, int y)
{
    int val = 0;
    do {
        val += (x * y);
        ++x;
    } while (x < y);
    return val;
}
