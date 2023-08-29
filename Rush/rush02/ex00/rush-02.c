/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahanak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 22:02:33 by vahanak           #+#    #+#             */
/*   Updated: 2023/08/27 22:03:08 by vahanak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_is_argv_valid(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (str[i])
	{
		while (str[i][j] != '\0')
		{
			if (str[i][j] > '9' || str[i][j] < '0')
				return(0);
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result * sign);
}
//utilisation de fopen interdite
int	ft_read_dico(int nb)
{
	FILE* dico;
	int nombreMots; 
	int numMotChoisi; 
	int i;
	int caractereLu;

	dico = NULL;
	nombreMots = 0; 
	numMotChoisi = 0; 
	i = 0;
	caractereLu = 0;
	dico = fopen("numbers.dict", "r");
	if (dico == NULL)
	{
		write(1, "Impossible de charger le dictionnaire de mots\n", 1);
		return (0);
	}
}


int	ft_is_valid(char **str)
{
/*mettre tout le debut du code dans le main*/
}

int	main(int argc, char **argv)
{
	int	nb;

	nb = 0;
	if (argc <= 3 && argc > 1 && ft_is_argv_valid(argv))
	{
		if (argc == 2)
		{
			nb = ft_atoi(argv[1]);
			ft_read_dico(nb);	
		}
		if (argc == 3)
		{
		}
	}
	else
	{
		write(1, "Error\n", 6);
		return (0);
	}
}
