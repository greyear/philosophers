
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