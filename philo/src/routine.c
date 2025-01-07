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

static int	check_before_fork(t_philo *philo)
{
	mutex_action(&(philo->res->print), LOCK);
	if (philo->res->flag_finish == 1)
	{
		mutex_action(&(philo->res->print), UNLOCK);
		return (1);
	}
	mutex_action(&(philo->res->print), UNLOCK);
	return (0);
}

int	forks(t_philo *philo)
{
	if (check_before_fork(philo))
		return (1);
	//check for stop
	mutex_action(philo->fork_l, LOCK);
	message_lock(philo, FORKS); //if returns an error
	if (check_before_fork(philo))
	{
		mutex_action(philo->fork_l, UNLOCK);
		return (1);
	}
	//solo philosopher
	mutex_action(philo->fork_r, LOCK);
	message_lock(philo, FORKS); //if returns an error
	return (0);
}

void	eat(t_philo *philo) //?
{
	mutex_action(&(philo->res->print), LOCK); //rename?
	philo->meals_eaten++;
	//printf("------------------ %d philosopher ate %ld times\n", philo->id, philo->meals_eaten);
	philo->last_meal_time = get_time();
	mutex_action(&(philo->res->print), UNLOCK);
	message_lock(philo, EAT);
	wait_ms(philo->res->args->time_to_eat, philo->res);
	mutex_action(&(philo->res->print), LOCK);
	if (philo->meals_eaten == philo->args->meals_must_eat)
	{
		philo->res->num_full++;
		//printf("------------------ %ld philosophers are full\n", philo->res->num_full);
	}
	mutex_action(&(philo->res->print), UNLOCK);
	mutex_action(philo->fork_l, UNLOCK);
	mutex_action(philo->fork_r, UNLOCK);
}

int	sleep_think(t_philo *philo)
{
	//protect everything
	message_lock(philo, SLEEP);
	wait_ms(philo->res->args->time_to_sleep, philo->res); // easier??
	message_lock(philo, THINK);
	return (0);
}

void	*routine(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	
	if (philo->id % 2 == 0)
		wait_ms(10, philo->res); //?
	while (1)
	{
		if (forks(philo) == 1)
			break ;
		eat(philo); //if?
		if (sleep_think(philo) == 1)
			break ;
	}
	return NULL;
}