/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdi-pint <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:57:49 by pdi-pint          #+#    #+#             */
/*   Updated: 2023/11/22 14:57:53 by pdi-pint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_freejoin_bonus(char *str1, char *str2)
{
	char	*temp;

	temp = ft_strjoin_bonus(str1, str2);
	free(str1);
	return (temp);
}

char	*ft_sep_str_bonus(char **testo)
{
	char	*buffer;
	char	*temp;
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = *testo;
	ret = NULL;
	while (temp[i] && temp[i] != '\n')
	{
		i++;
	}
	if (!temp[i])
		j = -1;
	i++;
	while (j != -1 && temp[i + j])
		j++;
	buffer = ft_substr_bonus(*testo, 0, i);
	if (j != -1)
		ret = ft_substr_bonus(*testo, i, j);
	free(temp);
	*testo = ret;
	return (buffer);
}

char	*ft_get_line_bonus(int fd, char *testo)
{
	int		bytes_read;
	char	*buffer;

	bytes_read = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1 || \
			(bytes_read == 0 && ft_strlen_bonus(testo) == 0))
		{
			free(testo);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		testo = ft_freejoin_bonus(testo, buffer);
		if (ft_strchr_bonus(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (testo);
}

char	*get_next_line_bonus(int fd)
{
	static char	*testo[1024];
	char		*buffer;

	buffer = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(testo[fd]);
		return (NULL);
	}
	if (!testo[fd])
		testo[fd] = ft_calloc_bonus(1, 1);
	if (!testo[fd])
		return (NULL);
	testo[fd] = ft_get_line_bonus(fd, testo[fd]);
	if (!testo[fd])
		return (NULL);
	buffer = ft_sep_str_bonus(&testo[fd]);
	return (buffer);
}
/* 
int main()
{
    int fd1 = open("prova1.txt", O_RDONLY);
     int fd2 = open("prova2.txt", O_RDONLY);
      int fd3 = open("prova3.txt", O_RDONLY);
       int fd4 = open("prova4.txt", O_RDONLY);

    char *str;

	for (int i = 0; i < 4; i++)
	{
		str = get_next_line_bonus(fd1);
    	printf("Linea letta del file %i: (riga %i) :%s", 1, i +1, str);
		free(str);
        str = get_next_line_bonus(fd2);
    	printf("Linea letta del file %i: (riga %i) :%s", 2, i +1, str);
		free(str);
        str = get_next_line_bonus(fd3);
    	printf("Linea letta del file %i: (riga %i) :%s", 3, i +1, str);
		free(str);
        str = get_next_line_bonus(fd4);
    	printf("Linea letta del file %i: (riga %i) :%s", 4, i +1, str);
		free(str);
    }
} */

// int main(int ac, char **av)
// {
//         int fd[1024]= {0};
//         int i  = 1;
//         int j = 0;
//         while (i <= ac - 1)
//         {
//             fd[j++] = open(av[i], O_RDONLY);
//             i++;
//         }

//         char *str;
//         j = 0;
//         while (j < ac - 1)
//         {   
//             str = get_next_line_bonus(fd[j]);
//             while (str)
//             {
//                 printf("Linea letta primo file : (riga ) :%s\n", str);
//                 free(str);
//                 if (fd[j + 1])
//                 {
//                     str = get_next_line_bonus(fd[j + 1]);
//                     printf("Linea letta secondo file : (riga ) :%s\n", str);
//                     free(str);
//                     str = get_next_line_bonus(fd[j]);
//                 }
//             }
//             free(str);
//             j++;
//         }
// }

// int	main(int argc, char **argv)
// {
// 	int	fd[argc - 1];
// 	int	i = 0;
// 	int	y = 0;
// 	char *str;
// 	while (argv[++i])
// 		fd[i - 1] = open(argv[i], O_RDONLY);
// 	i = 0;
// 	while (i < argc && y < (4 * (argc - 1)))
// 	{
// 		if (i == argc - 1)
// 			i = 0;
// 		str = get_next_line_bonus(fd[i]);
// 		printf("Linea letta del file %i: (riga %d): %s", i, y / 4, str);
// 		i++;
// 		y++;
// 		free(str);
// 	}
// }
