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

/*
-- what to protect?
-- valgrind --tool=helgrind

*/

/*
cases:
200 130 60 60 should live, works from school pc, not from home
4 2147483648 200 200 should be invalid args
2147483648 410 200 200 should be invalid args
2147483647 410 200 200 malloc problem (check if everyone has it?)

2147483 410 200 200 DOESN'T WORK! mutex problem
20 410 200 200 works but odd numbers don't (less or more than 20, whyyy)


exit code???? should be 0 every time or not?
more mutexes for different things?
*/

/*
operations which we should protect:
init
destroy NE NADO!!!!!!!!!!
create, join

*/