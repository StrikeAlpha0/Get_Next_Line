/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 22:49:05 by msharpe           #+#    #+#             */
/*   Updated: 2017/12/22 17:51:03 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <fcntl.h>

/*
**  For a new file. Program initially runs in a way that the printing statment
** is called in main. That being said, the new file function allows for the
** buf to be saved to a double pointer in a static array. From there, the
** information is called and the str_split function is ran to arrange
** the info in the best possible way.
*/

typedef struct s_information {
	char		**newarray;
	size_t		r;
}				t_information;

static int		new_file(int fd, t_information *info)
{
	char	buf[BUFF_SIZE + 1];
	int		w;
	char	*temp;
	char	*array;

	info->r = 0;
	array = ft_strnew(0);
	while ((w = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[w] = '\0';
		temp = ft_strjoin(array, buf);
		free(array);
		array = temp;
	}
	if (w >= 0)
		info->newarray = ft_strsplit(array, '\n');
	free(array);
	return ((w < 0) ? 0 : 1);
}

/*
** When GNL is called, it takes the argv info and casts it into a fd.
** the buff then reads it and our other functions manipulate that info.
** The main function used is str_split which places all of the text in
** an array that's delimited by the character '\n'. After that, the
** calls the item in the first array slot, sets a pointer to it, and
** returns info stating if the pointer is pointing to a continuing
**or end of file string.
*/

int		get_next_line(int fd, char **line)
{
	static t_information	info[4864];

	if (fd < 0 || fd >= 4864)
		return (-1);
	if (!info[fd].newarray && !new_file(fd, &info[fd]))
		return (-1);
	if (info[fd].newarray[info[fd].r])
	{
		*line = info[fd].newarray[info[fd].r];
		info[fd].r++;
		return (1);
	}
	free(info[fd].newarray);
	info[fd].newarray = 0;
	return (0);
}
