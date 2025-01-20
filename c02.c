// C0100 Reproduce the behavior of the function strcpy (man strcpy)
char	*ft_strcpy(char *dest, char *src) {
	int	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

