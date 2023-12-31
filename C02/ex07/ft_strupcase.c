/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzeggai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 10:23:41 by zzeggai           #+#    #+#             */
/*   Updated: 2023/08/09 10:24:06 by zzeggai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	char	*s;

	s = str;
	while (*s)
	{
		if (*s >= 'a' && *s <= 'z')
			*s -= 32;
		s++;
	}
	return (str);
}
