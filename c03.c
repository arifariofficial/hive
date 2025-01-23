/* C0300 Reproduce the behavior of the function strcmp */
int ft_strcmp(char *s1, char *s2) 
{
    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return (unsigned char)*s1 - (unsigned char)*s2;
}

/* C0301 Reproduce the behavior of the function strncmp */

int ft_strncmp(char *s1, char *s2, unsigned int n) 
{
    unsigned int i = 0;

    while (i < n && s1[i] && s2[i]) {
        if (s1[i] != s2[i]) {
            return (unsigned char)s1[i] - (unsigned char)s2[i];
        }
        i++;
    }
    if (i < n) {
        return (unsigned char)s1[i] - (unsigned char)s2[i];
    }
    return 0;
}

/* C0302 Reproduce the behavior of the function strcat */
char *ft_strcat(char *dest, char *src) 
{
    char *dest_start = dest;

    while (*dest) {
        dest++;
    }
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return dest_start;
}

/* C0303 Reproduce the behavior of the function strncat */
char *ft_strncat(char *dest, char *src, unsigned int nb) {
    char *dest_start = dest;
    unsigned int i = 0;

    while (*dest) {
        dest++;
    }
    while (*src && i < nb) {
        *dest = *src;
        dest++;
        src++;
        i++;
    }
    *dest = '\0';
    return dest_start;
}

/* C0304 Reproduce the behavior of the function strstr */
char *ft_strstr(char *str, char *to_find) {
    char *s;
    char *f;

    if (!*to_find) {
        return str;
    }
    while (*str) {
        s = str;
        f = to_find;
        while (*s && *f && *s == *f) {
            s++;
            f++;
        }
        if (!*f) {
            return str;
        }
        str++;
    }
    return 0;
}

/* C0305 Reproduce the behavior of the function strlcat */
unsigned int ft_strlen(char *str) {
    unsigned int len = 0;

    while (*str++) {
        len++;
    }
    return len;
}

unsigned int ft_strlcat(char *dest, char *src, unsigned int size) {
    unsigned int dest_len = ft_strlen(dest);
    unsigned int src_len = ft_strlen(src);
    unsigned int i = 0;

    if (size <= dest_len) {
        return size + src_len;
    }
    while (src[i] && (dest_len + i) < (size - 1)) {
        dest[dest_len + i] = src[i];
        i++;
    }
    if ((dest_len + i) < size) {
        dest[dest_len + i] = '\0';
    }
    return dest_len + src_len;
}
