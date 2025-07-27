#include <stdlib.h>
#include <stdio.h>

int ft_nbr_len(int nbr, int base_len);
int	ft_str_len(char *str);
int	ft_verif_base(char *base);

char	*ft_atoi(char *str, int *sign)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			*sign *= -1;
		}
		i++;
	}
	return (&str[i]);
}

int	ft_in_base(char *str, char *base)
{
	int	j;

	j = 0;
	while (base[j] != '\0')
	{
		if (*str == base[j])
			return (j);
		j++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	nbr;
	int	len;
	int	i;

	sign = 1;
	len = ft_str_len(base);
	str = ft_atoi(str, &sign);
	i = 0;
	nbr = 0;
	while (ft_in_base(&str[i], base) >= 0)
	{
		nbr *= len;
		nbr += ft_in_base(&str[i], base);
		i++;
	}
	return (nbr * sign);
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    int nbr_value;
    int tmp;
    int len_base_to;
    int nbr_base_to;
    char *result;
    
    if (ft_verif_base(base_from) || ft_verif_base(base_to))
        return NULL;

    nbr_value = ft_atoi_base(nbr, base_from);
    
    len_base_to = ft_str_len(base_to);
    nbr_base_to = ft_nbr_len(nbr_value, len_base_to);

    result = malloc(sizeof(char) * (nbr_base_to + 1));
    if (result == NULL)
        return (NULL);
    result[nbr_base_to] = '\0';
    tmp = nbr_value;

    if (nbr_value < 0)
        nbr_value *= -1;

    result[nbr_base_to] = '\0';
    while (nbr_base_to > 0)
    {
        result[--nbr_base_to] = base_to[nbr_value % len_base_to];
        nbr_value /= len_base_to;
    }
    

    if (tmp < 0)
        result[0] = '-';
    return(result);


}



int main(void)
{
    printf("%s", ft_convert_base("456", "0123456789", "0123456789"));

    return (0);
}