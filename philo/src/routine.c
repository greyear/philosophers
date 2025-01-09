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
	mutex_action(philo->fork_l, LOCK);
	if (message_lock(philo, FORKS) == 1)
	{
		mutex_action(philo->fork_l, UNLOCK);
		return (1);
	}
	if (check_before_fork(philo))
	{
		mutex_action(philo->fork_l, UNLOCK);
		return (1);
	}
	mutex_action(philo->fork_r, LOCK);
	if (message_lock(philo, FORKS) == 1)
	{
		mutex_action(philo->fork_l, UNLOCK);
		mutex_action(philo->fork_r, UNLOCK);
		return (1);
	}
	return (0);
}

void	eat(t_philo *philo) //?
{
	mutex_action(&(philo->res->print), LOCK);
	philo->meals_eaten++;
	philo->last_meal_time = get_time();
	mutex_action(&(philo->res->print), UNLOCK);
	message_lock(philo, EAT); //? return 1?
	wait_ms(philo->res->args->time_to_eat, philo->res); //? return 1?
	mutex_action(philo->fork_l, UNLOCK);
	mutex_action(philo->fork_r, UNLOCK);
	mutex_action(&(philo->res->print), LOCK);
	if (philo->meals_eaten == philo->args->meals_must_eat)
		philo->res->num_full++;
	mutex_action(&(philo->res->print), UNLOCK);
}

int	sleep_think(t_philo *philo)
{
	if (message_lock(philo, SLEEP) == 1)
		return (1);
	if (wait_ms(philo->res->args->time_to_sleep, philo->res) == 1)
		return (1);
	if (message_lock(philo, THINK) == 1)
		return (1);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		wait_ms(50, philo->res); //?
	while (1)
	{
		if (forks(philo) == 1)
			break ;
		eat(philo); //if?
		if (sleep_think(philo) == 1)
			break ;
	}
	return (NULL);
}
