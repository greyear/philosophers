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

int	message_lock(t_philo *philo, t_oper oper)
{
	size_t	timestamp;

	//protect mutex_actions
	mutex_action(&(philo->res->print), LOCK);
	if (philo->res->flag_finish == 1)
	{
		mutex_action(&(philo->res->print), UNLOCK);
		return (1); //check when call it
	}
	timestamp = get_time() - philo->res->start;
	if (oper == THINK)
		printf("%zu %d is thinking\n", timestamp, philo->id);
	else if (oper == FORKS)
		printf("%zu %d has taken a fork\n", timestamp, philo->id);
	else if (oper == EAT)
		printf("%zu %d is eating\n", timestamp, philo->id);
	else if (oper == SLEEP)
		printf("%zu %d is sleeping\n", timestamp, philo->id);
	mutex_action(&(philo->res->print), UNLOCK);
	return (0);
}

int	message(t_philo *philo, t_oper oper)
{
	size_t	timestamp;

	timestamp = get_time() - philo->res->start;
	if (oper == DEATH)
		printf("%zu %d died\n", timestamp, philo->id);
	if (oper == FULL)
		printf("All philosophers ate at least %ld times\n",
			philo->args->meals_must_eat);
	return (0);
}
