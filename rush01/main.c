#include <stdio.h>

//initialisation.c
int	ft_entry(char *argv[]);
char **ft_init(int len);
void	ft_param(char **tab, char **argv, int len);


//affichage du tableau
void	ft_putgrid(char **tab, int len);






int	main(int argc, char *argv[])
{
	//mettre len et param



	//possible de trouver la taille avec le nombre d'arguement
	//dimension du tableau len+2 pour param + 
	int	len;
	char **tab;

	len = 4;
	len += 2;


	//parsing de argv pour empecher les erreurs
	if (argc != 2)
		return (1);
	if (ft_entry(argv) == 1)
		return (1);

	//creation tab
	tab = ft_init(len);
	ft_param(tab, argv, len);

	
	//test test test test
	//remplissage des solutions
	char	sol[] = "1234";

	int	h = 0;
	while (sol[h] != '\0')
	{
		tab[1][h + 1] = sol[h];
		h++;
	}

	//comptage pour les verifications
	int	f;
	int	comp;
	char	max;

	f = 0;
	comp = 0;
	max = '0';

	while (sol[f] != '\0')
	{
		if (sol[f] > max)
		{
			max = sol[f];
			comp++;
		}
		f++;
	}

	printf("\n\n%d\n\n", comp);


	//affichage du tableau
	ft_putgrid(tab, len);
	printf("%s", "\n\n");


}


