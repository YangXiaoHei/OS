int fun(int x, int y)
{
    int val = 0;
    while (x < y) {
        val *= (x + y);
        x++;
    }
    return val;
}
