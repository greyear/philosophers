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

void	message(t_philo *philo, t_oper oper) //pointer to oper?
{
	size_t	timestamp;

	//protect mutex_actions
	mutex_action(&(philo->res->print), LOCK);
	timestamp = get_time() - philo->res->start;
	if (oper == THINK) //other conditions
		printf("%zu %d is thinking\n", timestamp, philo->id);
	else if (oper == FORKS) //other conditions
		printf("%zu %d has taken a fork\n", timestamp, philo->id);
	else if (oper == EAT) //other conditions
		printf("%zu %d is eating\n", timestamp, philo->id);
	else if (oper == SLEEP) //other conditions
		printf("%zu %d is sleeping\n", timestamp, philo->id);
	else if (oper == DEATH) //other conditions
		printf("%zu %d died\n", timestamp, philo->id);
	mutex_action(&(philo->res->print), UNLOCK);
}

