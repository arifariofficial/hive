// C0100 Reproduce the behavior of the function strcpy
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
char	*ft_strcpy(char *dest, char *src) {
	char *original_destination = dest;

	while (*src != '\0') {
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return original_destination;
}

// Reproduce the behavior of the function strncpy 
