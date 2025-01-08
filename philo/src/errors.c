/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:05:42 by azinchen          #+#    #+#             */
/*   Updated: 2024/12/26 16:05:44 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	error_msg(int code)
{
	if (code == ARGS_NUM)
		printf("Invalid number of arguments\n"); //stderr??
	if (code == INV_ARGS)
		printf("Invalid arguments\n");
	if (code == MLLC)
		printf("Malloc error\n");
	if (code == THRD_CRT)
		printf("Pthread_create error\n");
	if (code == THRD_JN)
		printf("Pthread_join error\n");
	if (code == MTX_INIT)
		printf("Pthread_mutex_init error\n");
	if (code == MTX_DSTR)
		printf("Pthread_mutex_destroy error\n");
	if (code == MTX_LCK)
		printf("Pthread_mutex_lock error\n");
	if (code == MTX_UNLCK)
		printf("Pthread_mutex_unlock error\n");
	return (1);
}
