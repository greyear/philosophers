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

static int	one_philo(t_res *res)
{
	//start from thinking?
	printf("%d %d has taken a fork\n", 0, 1);
	printf("%zu %d died\n", res->args->time_to_die, 1);
	free_fields(res);
	free(res);
	exit (0); //IS IT ALLOWED?
}

static int	zeros(t_res *res)
{
	error_msg(INV_ARGS);
	free_fields(res);
	free(res);
	exit (0); //IS IT ALLOWED?
}

int	validation(int argc, char **argv, t_res *res)
{
	res->args = (t_args *)ft_calloc(1, sizeof(t_args));
	if (!res->args)
		return (error_msg(MLLC));
	if (ft_atoi(argv[1], &(res->args->num))
		|| ft_atoi(argv[2], &(res->args->time_to_die))
		|| ft_atoi(argv[3], &(res->args->time_to_eat))
		|| ft_atoi(argv[4], &(res->args->time_to_sleep)))
		return (error_msg(INV_ARGS));
	res->args->meals_must_eat = -1;
	if (argc == 6 && ft_atoi(argv[5], &(res->args->meals_must_eat)))
		return (error_msg(INV_ARGS));
	if (res->args->num == 1)
		one_philo(res);
	if (res->args->num == 0 || res->args->time_to_die == 0
		|| res->args->time_to_eat == 0 || res->args->time_to_sleep == 0
		|| res->args->meals_must_eat == 0)
		zeros(res);
	return (0);
}
