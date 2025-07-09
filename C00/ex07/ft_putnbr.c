#include <unistd.h>

void    print(char b)
{
    write(1, &b, 1);
}

void    ft_putnbr(int nb)
{
    if (nb == -2147483648)
    {
        print('-');
        print('2');
        ft_putnbr(147483648);
        return;
    }

    if (nb < 0)
    {
        print('-');
        ft_putnbr(-nb);
        return;
    }

    if (nb >= 10)
    {
        ft_putnbr(nb / 10);
    }
    print((nb % 10) + '0');
}