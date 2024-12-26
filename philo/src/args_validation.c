/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:11:51 by azinchen          #+#    #+#             */
/*   Updated: 2024/12/26 15:11:53 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	validation(int argc, char **argv, t_args *args) //should I put args as a field of another struct?
{
	if (ft_atoi(argv[1], &(args->num_of_philos))
		|| ft_atoi(argv[2], &(args->time_to_die))
		|| ft_atoi(argv[3], &(args->time_to_eat))
		|| ft_atoi(argv[4], &(args->time_to_sleep)))
		return (error_msg(2));
	args->meals_must_eat = 0;
	if (argc == 6 && ft_atoi(argv[5], &(args->meals_must_eat)))
		return (error_msg(2));
	return (0);
}


