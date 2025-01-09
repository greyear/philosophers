/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:52:36 by azinchen          #+#    #+#             */
/*   Updated: 2025/01/08 12:52:38 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

size_t	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (error_msg(GETTIME)); //should I set finish flag equal to 1???
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	wait_ms(size_t waiting_time, t_res *res)
{
	size_t	start;
	size_t	end;

	start = get_time();
	end = start + waiting_time;
	while (get_time() < end)
	{
		usleep(400);
		mutex_action(&(res->print), LOCK);
		if (res->flag_finish == 1)
		{
			mutex_action(&(res->print), UNLOCK);
			return (1);
		}
		mutex_action(&(res->print), UNLOCK);
	}
	return (0);
}
