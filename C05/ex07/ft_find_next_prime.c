/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzeggai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:00:58 by zzeggai           #+#    #+#             */
/*   Updated: 2023/08/28 14:01:01 by zzeggai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_is_prime(int nb)
{
	int		diviseur;
	long	n;

	diviseur = 2;
	n = nb;
	if (n <= 1) 
	{
		return (0);
	}
	while (diviseur <= n / diviseur)
	{
		if (n % diviseur == 0)
		{
			return (0);
		}
		diviseur++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	nb_a_tester;

	nb_a_tester = nb;
	while (!ft_is_prime(nb_a_tester))
	{
		nb_a_tester++;
	}
	return (nb_a_tester);
}
