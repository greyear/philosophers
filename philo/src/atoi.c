/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:51:54 by azinchen          #+#    #+#             */
/*   Updated: 2025/01/08 12:51:55 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || \
				c == '\r' || c == '\f' || c == '\v')
		return (1);
	return (0);
}

static int	ft_isplus(int c)
{
	if (c == '+')
		return (1);
	return (0);
}

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_empty_space(char *str)
{
	int		i;

	if (!str || str[0] == '\0')
		return (1);
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

int	ft_atoi(char *str, size_t *number)
{
	int		i;
	long	res;

	if (ft_empty_space(str))
		return (1);
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (ft_isplus(str[i]))
		i++;
	if (!ft_isdigit(str[i]))
		return (1);
	res = 0;
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i++] - '0');
		if (res > (long)INT_MAX)
			return (1);
	}
	if (str[i] != '\0')
		return (1);
	*number = (size_t)res;
	return (0);
}
