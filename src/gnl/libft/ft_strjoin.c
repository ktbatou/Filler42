/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:40:55 by ktbatou           #+#    #+#             */
/*   Updated: 2020/11/05 23:53:25 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	if (!(s1) || !(s2))
		return (NULL);
	len = ft_strlen(s1);
	if (!(str = (char *)malloc(sizeof(char) * (len + ft_strlen(s2) + 1))))
		return (NULL);
	ft_memcpy(str, s1, len);
	while (s2[i])
	{
		str[len] = s2[i];
		len++;
		i++;
	}
	str[len] = '\0';
	return (str);
}
