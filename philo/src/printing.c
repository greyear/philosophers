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

size_t	get_time(t_res *res) //long? //tv inside the philo?
{
	//struct timeval tv;
	if (gettimeofday(&(res->tv), NULL) == -1)
		return (-1); //protect after calling
	return ((res->tv.tv_sec * 1000) + (res->tv.tv_usec / 1000));
	//sec -> millisec					microces->millisec
}

void	print_msg(t_res *res, t_oper oper) //pointer to oper?
{
	//mutex
	if (oper == THINK) //other conditions
		printf("%zu %d is thinking\n", get_time(res), res->philos->id);
	else if (oper == EAT) //other conditions
	{
		//forks?
		printf("%zu %d is eating\n", get_time(res), res->philos->id);
	}
		
	else if (oper == SLEEP) //other conditions
		printf("%zu %d is sleeping\n", get_time(res), res->philos->id);
	//mutex
}

