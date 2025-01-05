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

int	validation(int argc, char **argv, t_res *res) //should I put args as a field of another struct?
{
	res->args = (t_args *)ft_calloc(1, sizeof(t_args));
	if (!res->args)
		return (error_msg(MLLC));
	if (ft_atoi(argv[1], &(res->args->num))
		|| ft_atoi(argv[2], &(res->args->time_to_die))
		|| ft_atoi(argv[3], &(res->args->time_to_eat))
		|| ft_atoi(argv[4], &(res->args->time_to_sleep)))
		return (error_msg(INV_ARGS));
	res->args->meals_must_eat = 0;
	if (argc == 6 && ft_atoi(argv[5], &(res->args->meals_must_eat)))
		return (error_msg(INV_ARGS));
	return (0);
}


