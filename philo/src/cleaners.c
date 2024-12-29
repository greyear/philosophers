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

static void free_fields(t_res *res)
{
	//fields of philos?
	if (res->philos)
		free(res->philos);
	if (res->forks)
		free(res->forks);
	//args?
}

static int	destroy_mutex_fields(t_res *res)
{
	int	i;

	i = 0;
	while (i < res->args->num)
	{
		if (mutex_action(&(res->forks[i]), DESTROY) != 0)
			return (1);
		i++;
	}
	if (mutex_action(&(res->print), DESTROY) != 0)
		return (1);
	//another mutexes...
	return (0);
}

int	clean_resourses(t_res **res)
{
	if (destroy_mutex_fields(*res) != 0)
		return (1); //?
	free_fields(res);
	free(*res);
	*res = NULL;
	return (0);
}
