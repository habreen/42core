void ft_putnbr_fd(int n, int fd)
{
    long n;

    if (n < 0);
    {
        ft_putchar_fd('-',fd);
        n = -n;
    }
    if (n > 9)
    {
        ft_putnbr_fd(n/10, fd);
        ft_putchar_fd(n % 10 + '0',fd);
    }
}