/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzeggai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:13:50 by zzeggai           #+#    #+#             */
/*   Updated: 2023/08/28 11:13:55 by zzeggai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	fin;

	fin = nb;
	i = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (fin > i) 
	{
		nb *= i;
		i++;
	}
	return (nb);
}
