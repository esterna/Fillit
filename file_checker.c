

int		checkchrs(char *str)
{
	int i;

	i = 0;
	while (*str && (*str == '.' || *str == '#' || *str == '\n'))
	{
		if (*str == '#')
			i++;
		str++;
	}
	if (!*str || i != 4)
		return (0);
	return (1);
}

int		checkrows(char *str)
{
	int i;

	while (*str)
	{
		i = 4;
		while (i)
		{
			if (!(*str == '.' || *str == '#'))
			   str++;
			else
				return (0);
			i--;	
		}
		if (*str != '\n' && (*(++str) != '\n' || *str != '\0'))
			return (0);
		str++;
	}
	return (1);
}

int		checktets(char *str)
{
	char *tmp;

	tmp = str;
	while (*str)
	{
		while (*str == '.' || *str == '\n')
			str++;
		if (*str == '#')
		{
			if (*(str - 1) != '#' && *(str + 1) != '#' && *(str + 5) != '#'
					&& *(str - 5) != '#')
				return (0);
			str++;
		}
	}
	return (1);
}

int		filechecker(char *filename)
{
	int		i;
	int		fd;
	char	*buf;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("error in opening file\n");
		return (0);
	}
	while (write(fd, buf, 21) != -1)
	{
		i++;
		if (!checkchrs(buf) || !checkrows(buf) || !checktets(buf) || i > 26)
		{
			ft_putstr("error\n");
			return (0);
		}
	}
	if (i > 26)
	{
		ft_putstr("error\n");
		return (0);
	}
	if (close(fd) == -1)
		return (0);
	return (i);	
}
