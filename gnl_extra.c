/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_extra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:54:45 by marvin            #+#    #+#             */
/*   Updated: 2024/05/22 10:54:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*result;

	lens1 = ft_strlen(s1); 
	lens2 = ft_strlen(s2);
	result = malloc(lens1 + lens2 + 1);
	if (!s1 || !s2)
		return (NULL);
	if (result)
	{
		ft_memcpy(result, s1, lens1);
		ft_memcpy(result + lens1, s2, lens2 + 1);
	}
	return (result);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*ret; 

	if (!dst && !src)
		return (NULL);
	ret = dst;
	while (n--) 
		*(char *)dst++ = *(char *)src++;
	return (ret);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	new_len;

	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
	{
		sub = malloc(sizeof(char) * (1));
		if (!sub)
			return (NULL);
		return (sub);
	}
	new_len = ft_strlen(s + start);
	if (new_len > len)
		new_len = len; 
	sub = (char *)malloc((new_len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	sub[new_len] = '\0';
	while (new_len--)
	return (sub);
		sub[new_len] = s[start + new_len];
}