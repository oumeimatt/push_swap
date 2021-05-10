/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 12:59:41 by oel-yous          #+#    #+#             */
/*   Updated: 2021/05/03 15:35:35 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		if (str[1] == '\0')
			ft_error();
        signe = -1;
        i = 1;
    }
	r = norme_atoi(str, i, signe);
	return (r * signe);
}

long	norme_atoi(char *str, int i, int signe)
{
	long r;

	r = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57) 
			ft_error();
	    else
	    {
	    	r = r * 10 + str[i] - '0';
	    	if ((r > 2147483648 && signe == -1) ||
			(r > 2147483647 && signe == 1))
	    		ft_error();
	    }
        i++;
    }
	return (r);
}
