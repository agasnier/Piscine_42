#include <unistd.h>

void	ft_print_alphabet(void)
{
	char l;
	l = 'a';
	while(l <= 'z')
	{
		write(1, &l , 1);
		l++;
	}
}

int	main(void)
{
	ft_print_alphabet();
	return (0);
}
