/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 00:58:43 by msharpe           #+#    #+#             */
/*   Updated: 2017/12/22 17:48:09 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

#include "libft/libft.h"
#include <fcntl.h>

typedef struct		s_information
{
	void			**newarray;
	size_t			r;
}					t_information;

int					get_next_line(const int fd, char **line);

#endif
