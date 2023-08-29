/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzeggai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:58:21 by zzeggai           #+#    #+#             */
/*   Updated: 2023/08/28 13:58:24 by zzeggai          ###   ########.fr       */
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
