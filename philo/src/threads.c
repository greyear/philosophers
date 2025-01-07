/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:55:49 by azinchen          #+#    #+#             */
/*   Updated: 2024/12/30 14:55:51 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int create_threads(t_res *res)
{
	size_t	i;

	i = 0;
	while (i < res->args->num)
	{
		if (thread_action(&res->philos[i].thread, &routine,
			(void *)&res->philos[i], CREATE) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	join_threads(t_res *res)
{
	size_t	i;

	i = 0;
	while (i < res->args->num)
	{
		if (thread_action(&res->philos[i].thread, &routine,
			(void *)&res->philos[i], JOIN) != 0)
			return (1);
		i++;
	}
	return (0);
}
