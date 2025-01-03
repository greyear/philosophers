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
	
	sleep(1);
	printf("Printing GeeksQuiz from Thread \n");
	return NULL;

}