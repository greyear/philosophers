/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:45:53 by azinchen          #+#    #+#             */
/*   Updated: 2024/12/26 17:45:55 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

size_t	get_time(void) //long? //tv inside the philo?
{
	struct timeval	tv;
	if (gettimeofday(&tv, NULL) == -1)
		return (-1); //protect after calling
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	//sec -> millisec			microces->millisec
}

void	message(t_res *res, t_oper oper) //pointer to oper?
{
	size_t	timestamp;

	mutex_action(&(res->print), LOCK);
	timestamp = get_time() - res->start;
	if (oper == THINK) //other conditions
		printf("%zu %d is thinking\n", timestamp, res->philos->id);
	else if (oper == EAT) //other conditions
	{
		//forks?
		printf("%zu %d is eating\n", timestamp, res->philos->id);
	}
	else if (oper == SLEEP) //other conditions
		printf("%zu %d is sleeping\n", timestamp, res->philos->id);
	mutex_action(&(res->print), UNLOCK);
}


