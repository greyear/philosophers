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

int	wait_ms(size_t waiting_time)
{
	size_t	start;
	size_t	end;

	start = get_time();
	end = start + waiting_time;
	while (get_time() < end)
	{
		usleep(400); //protect usleep? //how to choose value?
		//add logic about other philos' death?
	}
}

void	message(t_philo *philo, t_oper oper) //pointer to oper?
{
	size_t	timestamp;

	//protect mutex_actions
	mutex_action(&(philo->res->print), LOCK);
	timestamp = get_time() - philo->res->start;
	if (oper == THINK) //other conditions
		printf("%zu %d is thinking\n", timestamp, philo->id);
	else if (oper == EAT) //other conditions
	{
		//forks?
		mutex_action(philo->fork_l, LOCK);
		printf("%zu %d has taken a fork\n", timestamp, philo->id);
		mutex_action(philo->fork_r, LOCK);
		printf("%zu %d has taken a fork\n", timestamp, philo->id);
		printf("%zu %d is eating\n", timestamp, philo->id);
		mutex_action(philo->fork_l, UNLOCK);
		mutex_action(philo->fork_r, UNLOCK);
	}
	else if (oper == SLEEP) //other conditions
		printf("%zu %d is sleeping\n", timestamp, philo->id);
	mutex_action(&(philo->res->print), UNLOCK);
}

