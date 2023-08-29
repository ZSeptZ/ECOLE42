/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzeggai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 05:48:06 by zzeggai           #+#    #+#             */
/*   Updated: 2023/08/16 05:48:16 by zzeggai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 1;
	ft_strlowcase(str);
	while (str[i] != '\0' )
	{
		if (i2 == 1 && str[i] >= 'a' && str [i] <= 'z')
		{
			str[i] -= 32;
			i2 = 0;
		}
		else if ((str[i] >= 'a' && str[i] <= 'z')
			|| (str [i] >= '0' && str [i] <= '9'))
		{
			i2 = 0;
		}
		else
		{
			i2 = 1;
		}
		i++;
	}
	return (str);
}
