nt		main(int ac, char **av)
{
	int		i;
	int		fd;
	char	*str;
	int		q;

	i = 1;
	q = 0;
	while (i < ac)
	{
		fd = open(av[i++], O_RDONLY, 0);
		while (get_next_line(fd,&str)==1)
		{
			ft_putstr(str);
			free(str);
		}
	}
	return (0);
}
