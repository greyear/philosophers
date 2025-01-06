/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:55:34 by azinchen          #+#    #+#             */
/*   Updated: 2024/12/30 14:55:37 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	forks(t_philo *philo)
{
	//check for stop
	mutex_action(philo->fork_l, LOCK);
	message(philo, FORKS); //if returns an error
	//solo philosopher
	mutex_action(philo->fork_r, LOCK);
	message(philo, FORKS); //if returns an error
	return (0);
}

void	eat(t_philo *philo) //?
{
	mutex_action(&(philo->res->print), LOCK); //rename?
	philo->meals_eaten++;
	philo->last_meal_time = get_time();
	mutex_action(&(philo->res->print), UNLOCK);
	message(philo, EAT);
	wait_ms(philo->res->args->time_to_eat);
	//проверка, наелся ли он
	mutex_action(philo->fork_l, UNLOCK);
	mutex_action(philo->fork_r, UNLOCK);
}

int	sleep_think(t_philo *philo)
{
	//protect everything
	message(philo, SLEEP);
	wait_ms(philo->res->args->time_to_sleep); // easier??
	message(philo, THINK);
	return (0);
}

void	*routine(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	
	if (philo->id % 2 == 0)
		wait_ms(10); //?
	while (1)
	{
		if (forks(philo) == 1)
			break ;
		eat(philo);
		if (sleep_think(philo) == 1)
			break ;
	}
	return NULL;
}