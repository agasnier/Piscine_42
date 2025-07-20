#include <unistd.h>

void	ft_putgrid(char **tab)
{
	int	i;
	int	j;

	j = 1;
	while (j <= 4)
	{
		i = 1;
		while (i <= 4)
		{
			write(1, &tab[j][i], 1);
			write(1, " ", 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}