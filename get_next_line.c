/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajouanna <ajouanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:04:19 by ajouanna          #+#    #+#             */
/*   Updated: 2016/12/02 19:31:28 by ajouanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

/*
** le principe de fonctionnement : je lis le fichier par blocs de taille
** BUFF_SIZE. Dans le buffer lu, je vais jusqu'au retour chariot. S'il n'y en a
** pas, je lis un nouveau bloc. S'il y en a, je garde dans une varable statique
** ou j'en suis, pour la prochaine lecture
*/

int		get_next_line(const int fd, char **line)
{
	static t_sbuf	sbuf = {.pos_in_buf = 0 };
	char			*pos_nl;
	int				res;
	int				len;
	/*
	int				i;
	int				j;
	char			*subline;
	char			*line2;
	int				ret;
	int				found_nl;
	*/

	if (sbuf.pos_in_buf == 0)
	{
		res = read(fd, sbuf.buf, BUFF_SIZE);
		if (res == -1)
			return (-1);
		if (res == 0)
			return (0);
		sbuf.buf[res] = 0;
	}
	if ((pos_nl = ft_strchr(sbuf.buf + sbuf.pos_in_buf, '\n')) != NULL)
	{
		len = pos_nl - (sbuf.buf + sbuf.pos_in_buf);
		if ((*line = malloc(sizeof(char) * (len + 1))) == NULL)
			return (-1);
		*line = ft_strncpy(*line, sbuf.buf + sbuf.pos_in_buf, len);
		(*line)[len] = 0;
		sbuf.pos_in_buf = len + 1;
		return (1);
	}
	if ((*line = malloc(sizeof(char) * (1))) == NULL)
		return (-1);
	(*line)[0] = 0;
	sbuf.pos_in_buf = 0;
	while ((res = read(fd, sbuf.buf, BUFF_SIZE) > 0))
	{
		if ((pos_nl = ft_strchr(sbuf.buf + sbuf.pos_in_buf, '\n')) != NULL)
		{
			// faire un join entre ce quil y a dans *line et la sous chaine
			// delimitee par \n... il faut peut etre un strnjoin ?
			// puis sortir de la boucle
		}
		else
		{
			// faire un join de *line avec buf 
			// puis continuer la boucle
		}
		
	}
	return (res);
}
