void    putnbase(long long n, int base, int *len)
{
    if (n < 0)
    {
        if(*len += write(1, "-", 1) == -1)
        {
            *len = -1;
            return;
        }
        *len ++;
        n = -n;
    }
    if (n >= base)
        putnbase (n / base, base, len);
        if(write(1, &"0123456789abcdef"[n % base, 1]) == -1)
        {
            *len = -1;
            return;
        }
        *len ++;
        
}