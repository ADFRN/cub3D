/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afournie <afournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:54:07 by afournie          #+#    #+#             */
/*   Updated: 2026/05/26 12:15:03 by afournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	replace_tabs(char *line, char *new_line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == '\t')
		{
			new_line[j++] = ' ';
			new_line[j++] = ' ';
			new_line[j++] = ' ';
			new_line[j++] = ' ';
		}
		else
			new_line[j++] = line[i];
		i++;
	}
	return (j);
}

char	*expand_tabs(char *line)
{
	int		i;
	int		tab_count;
	char	*new_line;
	int		j;

	i = 0;
	tab_count = 0;
	while (line[i])
	{
		if (line[i++] == '\t')
			tab_count++;
	}
	new_line = malloc(i + tab_count * 3 + 1);
	if (!new_line)
		return (NULL);
	j = replace_tabs(line, new_line);
	new_line[j] = '\0';
	return (new_line);
}
