/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarles <emarles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:45:37 by emarles           #+#    #+#             */
/*   Updated: 2025/03/02 16:12:40 by emarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char *ft_linechar(char **lines);
static void    free_arrays(char **lines);
char	*combining(char *s1, char *temp_buffer);

int grid_lentgh(char *line) // when 2 or more spaces __ - not calculated properly
{
    char **lines;
    int i;
    int size;

    lines = ft_split(line, ' '); // split INCLUDES the \n character at the end of the string;
    i = 0;   
    while (lines[i] != NULL)
    {
        printf("the %i string is '%s'\n", i, lines[i]);
        i++;
    }
    size = 0;
    while (lines[size] != NULL)
        size++;
    if (ft_linechar(lines))
        size--;
    free_arrays(lines); // function for freeing;
    return (size);
}

static char *ft_linechar(char **lines)
{
	int	i;

	i = 0;
	while (lines[i] != NULL)
	{
        // ft_strchr(lines[i], '\n') 
		if (ft_strchr(lines[i], '\n'))
			return (lines[i]);
		i++;
	}
	return (NULL);
}

static void    free_arrays(char **lines)
{
    int i;

    i = 0;
    while (lines[i] != NULL)
    {
        free(lines[i]);
        i++;
    }  
    free(lines);
}

int grid_height(int fd)
{
    int size;
    char    *temp_buffer;
    char    *line;
    size = 0;
    temp_buffer = NULL;
    
    while ((line = (get_next_line(fd)))) // how to iterate over the array?
    {
        temp_buffer = combining(temp_buffer, line);
        size++;
        free(line);
    }
    size++; // making up for a lost line
    printf("the map is : \n%s\n", temp_buffer);
    // free(line);
    free(temp_buffer);
    return (size);
}

char	*combining(char *s1, char *temp_buffer)
{
	char	*res;

	if (!s1 && !temp_buffer)
		return (NULL);
	if (!s1)
		return (ft_strdup(temp_buffer));
	if (!temp_buffer)
		return (ft_strdup(s1));
	res = ft_strjoin(s1, temp_buffer);
	free(s1);
    // free(temp_buffer);
	return (res);
}