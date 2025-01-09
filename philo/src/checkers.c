/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:52:13 by azinchen          #+#    #+#             */
/*   Updated: 2025/01/08 12:52:14 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static int	all_ate_enough(t_res *res)
{
	size_t	i;

	i = 0;
	while (i < res->args->num)
	{
		mutex_action(&(res->print), LOCK);
		if (res->num_full >= res->args->num)
		{
			res->flag_finish = 1;
			message(&res->philos[i], FULL);
			mutex_action(&(res->print), UNLOCK);
			return (1);
		}
		mutex_action(&(res->print), UNLOCK);
		i++;
	}
	return (0);
}

static int	death_happened(t_res *res)
{
	size_t	now;
	size_t	i;

	i = 0;
	while (i < res->args->num)
	{
		mutex_action(&(res->print), LOCK);
		now = get_time();
		if (now - res->philos[i].last_meal_time >= res->args->time_to_die)
		{
			res->flag_finish = 1;
			message(&res->philos[i], DEATH);
			mutex_action(&(res->print), UNLOCK);
			return (1);
		}
		mutex_action(&(res->print), UNLOCK);
		i++;
	}
	return (0);
}

void	check_for_finish(t_res *res)
{
	while (1)
	{
		if (death_happened(res) || all_ate_enough(res))
			break ;
	}
}
