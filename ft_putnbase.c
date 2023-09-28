void    putnbase(long long n, int base, int *len)
{
    if (n < 0)
    {
        *len += write(1, "-", 1);
        n = -n;
    }
    if (n >= base)
        putnbase (n / base, base, len);
        *len += write(1, &"0123456789abcdef"[n % base, 1]);
}