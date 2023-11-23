/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdi-pint <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:58:10 by pdi-pint          #+#    #+#             */
/*   Updated: 2023/11/22 14:58:12 by pdi-pint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr_bonus(const char *s, int c)
{
	unsigned char	*str;

	c = '\n';
	str = (unsigned char *)s;
	while (*str != (unsigned char)c)
	{
		if (*str == '\0')
		{
			return (NULL);
		}
		str++;
	}
	return ((char *)str);
}

size_t	ft_strlen_bonus(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin_bonus(char const *s1, char const *s2)
{
	int		i;
	int		k;
	char	*str;

	i = 0;
	k = 0;
	str = (char *)malloc(sizeof(char) * \
		(ft_strlen_bonus(s1) + ft_strlen_bonus(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[k] != '\0')
	{
		str[i + k] = s2[k];
		k++;
	}
	str[i + k] = '\0';
	return (str);
}

void	*ft_calloc_bonus(size_t count, size_t size)
{
	void			*p;
	unsigned char	*pp;
	size_t			n;

	n = count * size;
	p = malloc(n);
	if (p == NULL)
		return (p);
	pp = p;
	while (n)
	{
		*pp++ = 0;
		--n;
	}
	return (p);
}

char	*ft_substr_bonus(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (start >= ft_strlen_bonus(s))
	{
		start = ft_strlen_bonus(s);
		len = 0;
	}
	if (len + start > ft_strlen_bonus(s))
	{
		len = ft_strlen_bonus(s) - start;
	}
	str = ft_calloc_bonus(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
