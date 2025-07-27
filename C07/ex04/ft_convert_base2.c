int ft_nbr_len(int nbr, int base_len)
{
    int len;

    if (nbr <= 0)
        len = 1;
    else
        len = 0;
    while (nbr)
    {
        nbr/= base_len;
        len++;
    }
    return (len);


}



int	ft_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_verif_base(char *base)
{
	int	i;
	int	j;
    int len;

    len = ft_str_len(base);
	if (len < 2)
		return (1);
	i = 0;
	j = 0;
	while (i < len)
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
			return (1);
		while (j < len)
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}