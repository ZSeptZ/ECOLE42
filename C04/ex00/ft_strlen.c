/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzeggai <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:16:10 by zzeggai           #+#    #+#             */
/*   Updated: 2023/08/19 13:16:15 by zzeggai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;
	int	comp;

	i = 0;
	comp = 0;
	while (str[i] != '\0')
	{
		i++;
		comp++;
	}
	return (comp);
}
/*int main()
{
    char phrase[] = "la zip";
    int length = ft_strlen(phrase);
    printf("le nombre de caracteres est de : %d\n", length);
    
    return 0;
}*/
