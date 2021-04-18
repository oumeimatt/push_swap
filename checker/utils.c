/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 12:59:41 by oel-yous          #+#    #+#             */
/*   Updated: 2021/04/18 13:51:49 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while ((unsigned char)s1[i] == (unsigned char)s2[i])
	{
		if (s1[i] == '\0' || i >= (n - 1))
			return (0);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] == s2[i])
		{
			i++;
		}
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);
}

int		ft_atoi(char *str)
{
	long	signe;
	long	r;
    int i;

    i = 0;
	signe = 1;
    if (str[0] == '-')
    {
        signe = -1;
        i = 1;
    }
    r = 0;
	while (str[i] != '\0')
	{
		if ((int)str[i] < 48 || (int)str[i] > 57)
		{
			write(1, "111\n",4);
			ft_error();
		}
	    else
	    {
	    	r = r * 10 + str[i] - '0';
	    	if ((r > 2147483648 && signe == -1) || (r > 2147483647 && signe == 1))
			{
				write(1, "222\n",4);
	    		ft_error();
			}
	    }
        i++;
    }
	r = r * signe;
	return (r);
}
