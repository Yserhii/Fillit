char	*ft_foldtetrim(t_list **lst, int count)
{
	t_list		*point;
	char		*square;
	int			i;
	int			a;
	int			hesh;

	point =  *lst;
	square = (char*)ft_memalloc(sizeof(char) * (4 * 4));
	ft_memset(square, '.', (4 * 4));
	while (point)
	{
		i = 0;
		a = 0;
		count = 0;
		hesh = 4;
		while(square[i])
		{
			while (square[i] != '.')
				i++;
			while (((char*)point->content)[a] == '.' || ((char*)point->content)[a] == '\n')
				a++;
			while (square[i] == '.' && hesh > 0)
			{
				if (((char*)point->content)[a] == '\n')
						a++;
				if (((char*)point->content)[a] != '.' && hesh--)
					square[i] = ((char*)point->content)[a];
				if (((char*)point->content)[a] == '\0')
					break;
				i++;
				a++;
			}
			i++;
		}
	point = point->next;
	printf("%s\n", square);
	}
	return (square);
}