/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:16:57 by azinchen          #+#    #+#             */
/*   Updated: 2024/12/26 16:16:58 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	free_fields(t_res *res)
{
	if (res->philos)
		free(res->philos);
	if (res->forks)
		free(res->forks);
	if (res->args)
		free(res->args);
}

int	destroy_all_mutex_fields(t_res *res, size_t limit)
{
	size_t	i;

	i = 0;
	while (i < limit)
	{
		if (mutex_action(&(res->forks[i]), DESTROY) != 0)
			return (1);
		i++;
	}
	if (mutex_action(&(res->print), DESTROY) != 0)
		return (1);
	return (0);
}

int	destroy_forks_mutex_fields(t_res *res, size_t limit)
{
	size_t	i;

	i = 0;
	while (i < limit)
	{
		if (mutex_action(&(res->forks[i]), DESTROY) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	clean_destroy(t_res **res)
{
	if (destroy_all_mutex_fields(*res, (*res)->args->num) != 0)
		return (1);
	free_fields(*res);
	free(*res);
	*res = NULL;
	return (1);
}

int	clean(t_res **res)
{
	free_fields(*res);
	free(*res);
	*res = NULL;
	return (1);
}
