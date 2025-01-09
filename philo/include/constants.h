/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:51:18 by azinchen          #+#    #+#             */
/*   Updated: 2025/01/08 12:51:21 by azinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

typedef enum e_oper
{
	THINK,
	EAT,
	SLEEP,
	FORKS,
	DEATH,
	FULL
}	t_oper;

typedef enum e_err
{
	ARGS_NUM,
	INV_ARGS,
	MLLC,
	GETTIME,
	THRD_CRT,
	THRD_JN,
	MTX_INIT,
	MTX_DSTR,
	MTX_LCK,
	MTX_UNLCK,
}	t_err;

typedef enum e_thread
{
	CREATE,
	JOIN
}	t_thread;

typedef enum e_mtx
{
	INIT,
	DESTROY,
	LOCK,
	UNLOCK
}	t_mtx;

#endif
