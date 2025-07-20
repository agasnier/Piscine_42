#include <unistd.h>

void	ft_putgrid(char **tab, int len)
{
	int	i;
	int	j;

	j = 0;
	while (j < len)
	{
		i = 0;
		while (i < len)
		{
			write(1, &tab[j][i], 1);
			write(1, " ", 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}