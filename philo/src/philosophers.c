/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:46:36 by azinchen          #+#    #+#             */
/*   Updated: 2024/12/23 19:03:29 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	main(int argc, char **argv)
{
	t_res	*res;

	if (argc < 5 || argc > 6)
		return (error_msg(ARGS_NUM));
	res = (t_res *)ft_calloc(1, sizeof(t_res));
	if (!res)
		return (error_msg(MLLC));
	if (validation(argc, argv, res))
		return (clean(&res));
	if (init_resourses(res))
		return (1);
	if (create_threads(res))
		return (clean_destroy(&res));
	check_for_finish(res);
	if (join_threads(res, res->args->num))
		return (clean_destroy(&res));
	clean_destroy(&res);
	return (0);
}
