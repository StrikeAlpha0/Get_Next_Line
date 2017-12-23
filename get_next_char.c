/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharpe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 00:56:10 by msharpe           #+#    #+#             */
/*   Updated: 2017/12/17 22:12:27 by msharpe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



/*int			get_next_line(const int fd, char **line)
{
	
**	int len;
**	char buf[BUFF_SIZE + 1];
**	int fl;
**	int i;
**	int j;
**
**	i = 0;
**	j = 0;
**
**	fl = open(av[j], O_RDONLY);
**	while ((len = read(fl, buf, BUFF_SIZE)) > 0)
**	{
**		ft_putstr_fd(len, 1);



}*/

#include <stdio.h>
#include <unistd.h>

int			ft_strlen(char *s)
{
	int i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}


void		dunk(void)
{

	char *str = "Wub dub get fucking recked scrub.";
	int whole = ft_strlen(str);
	static int print = 2;
	static int onlythis = 0;
	if (str[onlythis] != '\0')
	{
		if (onlythis < print)
		{
			ft_putchar(str[onlythis]);
			onlythis++;
			if (str[onlythis] != '\0')
			{
				ft_putchar(str[onlythis]);
				onlythis++;
			}
		}
	}
//	if (str[onlythis] == '\0')
//		ft_putchar(str[onlythis]);
	if (print <= whole)
		print += 2;
//	x = str;
//	printf("%s\n", x);
}

int		main()
{
	int i;

	i = 0;
	while (i < 20)
	{
		dunk();
		//printf("%d\n", i);
		i++;
	}
//	printf("\n");
	return (0);
}
