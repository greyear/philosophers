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

void	*routine(void	*arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	
	/*if (philo) //delete
		sleep(1);*/
	//printf("Printing from thread %d \n", philo->id);
	message(philo, EAT);
	message(philo, SLEEP);
	message(philo, THINK);

	return NULL;

}