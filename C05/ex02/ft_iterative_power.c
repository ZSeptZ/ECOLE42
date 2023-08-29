/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzeggai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 12:24:34 by zzeggai           #+#    #+#             */
/*   Updated: 2023/08/28 12:24:37 by zzeggai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	if (power < 0)
	{
		return (0);
	}
	if (nb == 0 || power == 0)
	{
		return (1);
	}
	return (nb * ft_iterative_power(nb, power - 1));
}
