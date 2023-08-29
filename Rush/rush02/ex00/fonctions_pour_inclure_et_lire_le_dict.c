/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-02-avec-malloc-mais-malloc-marhce-pa          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahanak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:33:09 by vahanak           #+#    #+#             */
/*   Updated: 2023/08/27 21:51:58 by vahanak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct {
	char *key;
	char *value;
} DictEntry;

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*ft_strdup(char *src)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	p = malloc(sizeof(char) * i);
	if (!p)
		return (NULL);
	while (src[j] != '\0')
	{
		p[j] = src[j];
		j++;
	}
	return (p);
}

ssize_t read_line(int fd, char **ligne, size_t *longueur)
{
    ssize_t octets_lus = 0;
    ssize_t total_lus = 0;

    while (1)
    {
        if (octets_lus >= total_lus)
        {
            total_lus += BUFSIZ;
	    printf("salut\n");

            // Changement de realloc à malloc
            char *nouvelle_ligne = malloc(total_lus);
            if (nouvelle_ligne == NULL)
            {
                return -1; // Erreur d'allocation de mémoire
            }

            if (*ligne)
            {
                // Copie du contenu précédent s'il existe
                memcpy(nouvelle_ligne, *ligne, total_lus - BUFSIZ);
                free(*ligne);
            }

            *ligne = nouvelle_ligne;
        }

        octets_lus = read(fd, *ligne + total_lus - octets_lus, BUFSIZ);
        if (octets_lus == -1)
        {
            return -1;
        }
        if (octets_lus == 0)
        {
            if (total_lus == 0)
            {
                return -1; // Fin du fichier
            }
            break;
        }

        char *nouvelle_ligne = memchr(*ligne + total_lus - octets_lus, '\n', octets_lus);
        if (nouvelle_ligne)
        {
            *nouvelle_ligne = '\0';
            return total_lus - octets_lus + (nouvelle_ligne - (*ligne + total_lus - octets_lus)) + 1;
        }
    }
    return total_lus;
}

DictEntry *load_dictionary(const char *file_path, int *entry_count)
{
    int	fd = open(file_path, O_RDONLY);
    if (fd == -1)
    {
	write(1, "Erreur de Dictionnaire\n", 23);
	return NULL;
    }

	*entry_count = 0;
	DictEntry *entries = NULL;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while ((read = read_line(fd, &line, &len)) != -1)
    {
	    int	i;
	DictEntry *new_entries = (DictEntry *)malloc((*entry_count + 1) * sizeof(DictEntry));
        if (new_entries == NULL)
        {
	    int	i;
	    i = 0;
            while (i < *entry_count)
            {
                free(entries[i].key);
                free(entries[i].value);
		i++;
            }
            free(entries);
            close(fd);
            return NULL;
        }
        i = 0;
        while (i < *entry_count)
        {
	new_entries[i] = entries[i];
	i++;
        }

	entries = new_entries;

	char *delimiter = strchr(line, ':');
        if (delimiter)
        {
		*delimiter = '\0';
		entries[*entry_count].key = ft_strdup(line);
		entries[*entry_count].value = ft_strdup(delimiter + 1);
        }
	(*entry_count)++;
    }

	close(fd);
	if (line)
	{
	free(line);
	}
	return entries;
}

void	convert_to_text(int num, DictEntry *dict, int entry_count)
{
	if (num == 0)
	{
		char *text = find_in_dict(dict, entry_count, "0");
		if (text)
		{
		write(1, text, ft_strlen(text));
		}
		return ;
	}
	
	int billions = num / 1000000000;
	int millions = (num % 1000000000) / 1000000;
	int thousands = (num % 1000000) / 1000;
	int remainder = num % 1000;

	if (billions > 0)
	{
		convert_to_text(billions, dict, entry_count);
		write(1, " billion ", 9);
	}
	
	if (millions > 0)
	{
		convert_to_text(millions, dict, entry_count);
		write(1, " million ", 9);
	}
	
	if (thousands > 0)
	{
		convert_to_text(thousands, dict, entry_count);
		write(1, " thousand ", 10);
	}
	
	if (remainder > 0)
	{
		if (remainder >= 100)
		{
			char key[4];
			sprintf(key, "%d", remainder / 100);
			char *text = find_in_dict(dict, entry_count, key);
			if (text)
			{
				write(1, text, ft_strlen(text));
			}
			write(1, " hundred ", 9);
			remainder %= 100;
		}
		
		if (remainder >= 20) 
		{
			char key[4];
			sprintf(key, "%d", (remainder / 10) * 10);
			char *text = find_in_dict(dict, entry_count, key);
			if (text)
			{
				write(1, text, ft_strlen(text));
			}
			write(1, " ", 1);
			remainder %= 10;
		}
		
		if (remainder > 0)
		{
			char key[4];
			sprintf(key, "%d", remainder);
			char *text = find_in_dict(dict, entry_count, key);
			if (text) 
			{
				write(1, text, ft_strlen(text));
			}
		}
	}
}


	

