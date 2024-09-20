
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

size_t  ft_strlen(const char *s)
{
        size_t  cont;

        cont = 0;
        while (*s != '\0')
        {
                cont ++;
                s ++;
        }
        return (cont);
}

char    *ft_strdup(const char *s1)
{
        char    *aux;
        int             len;

        len = ft_strlen(s1);
        aux = malloc(len + 1);
        if (!aux)
                return (NULL);
        while (*s1 != '\0')
        {
                *aux = *s1;
                aux++;
                s1++;
        }
        *aux = '\0';
        while (len > 0)
        {
                len--;
                aux--;
        }
        return (aux);
}

char    *ft_strcpy(char *dst, const char *src)
{
        while (*src != '\0')
                *(dst++) = *(src++);
        return (dst);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
        char    *newstr;
        int             size;

        size = ft_strlen(s1) + ft_strlen(s2) + 1;
        newstr = malloc(size);
        if (!newstr)
                return (NULL);
        while (*s1 != '\0')
                *newstr++ = *s1++;
        while (*s2 != '\0')
                *newstr++ = *s2++;
        *newstr = '\0';
        newstr -= (size - 1);
        return (newstr);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
        char    *aux;
        size_t  cont;

        cont = 0;
        if (start < 0 || ft_strlen(s) < start)
                return (ft_strdup(""));
        if (len > (ft_strlen(s) - start))
                aux = malloc(ft_strlen(s) - start + 1);
        else
                aux = malloc(len + 1);
        if (!aux)
                return (NULL);
        s += start;
        while (len > 0 && *s != '\0')
        {
                *(aux++) = *(s++);
                cont++;
                len--;
        }
        *aux = '\0';
        while (cont-- > 0)
                aux--;
        return (aux);
}

char    *get_next_line(int fd)
{
        static char     *buf;
        int                     i;
        int                     j;
        char            *aux;
        char            *bufaux;

        i = 0;
        bufaux = NULL;
        if (!buf/* || buf[i] == '\0'*/)
        {
                buf = malloc(BUFFER_SIZE + 1);
                j = read(fd, buf, BUFFER_SIZE);
                buf[j] = '\0';
        }
        else
                j = ft_strlen(buf);
        while (buf[i] != '\n' && buf[i] != '\0' && j > 0)
        {
                i++;
                if (buf[i] == '\0')
                {
                        if (!bufaux)
                                bufaux = malloc(BUFFER_SIZE);
                        bufaux = ft_strjoin(bufaux, buf);
                        j = read(fd, buf, BUFFER_SIZE);
                        buf[j + 1] = '\0';
                        i = 0;
                }
        }
        i++;
        if (!bufaux)
        {
                bufaux = malloc(i);
                bufaux = ft_substr(buf, 0, i);
        }
        else
        {
                char    *subbuf; //-----CAMBIA ESTO DE SITIO ZORRA
                subbuf = ft_substr(buf, 0, i);
                bufaux = ft_strjoin(bufaux, subbuf);
        }
        ft_strcpy(aux, buf);
        free(buf);
        buf = malloc(j - i);
        buf = ft_substr(aux, i, j - i);
        return (bufaux);
}

int     main()
{
        int fd = open("pruebaDOS.txt", O_RDONLY);
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        return (0);
}
