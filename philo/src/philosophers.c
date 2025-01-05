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

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*int	mails = 0;
pthread_mutex_t	mutex;


void	*routine()
{
	for (int i = 0; i < 1000000; i++)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
	}
}

int	main(int argc, char	*argv[])
{
	pthread_t	t1;
	pthread_t	t2;
	pthread_mutex_init(&mutex, NULL); 

	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		return 1;
	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
		return 2;
	if (pthread_join(t1, NULL) != 0)
		return 3;
	if (pthread_join(t2, NULL) != 0)
		return 4;
	pthread_mutex_destroy(&mutex);
	printf("Number of mails: %d\n", mails);
	return (0);
}*/


/*
void	*computation(void *add)
{
	long	*add_num;

	add_num = (long *)(add);
	printf("Add: %ld\n", *add_num);
	return NULL;
}

int main()
{
	pthread_t	thread1;
	pthread_t	thread2;
	long		value1 = 1;
	long		value2 = 2;

	pthread_create(&thread1, NULL, computation, (void *)&value1);
	pthread_create(&thread2, NULL, computation, (void *)&value2);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	return 0;
}*/

/*
// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void* myThreadFun(void* vargp)
{
	sleep(1);
	printf("Printing GeeksQuiz from Thread \n");
	return NULL;
}

int main()
{
	pthread_t thread_id;
	printf("Before Thread\n");
	pthread_create(&thread_id, NULL, myThreadFun, NULL);
	pthread_join(thread_id, NULL);
	printf("After Thread\n");
	exit(0);
}
*/
/*#include <pthread.h>
#include <stdio.h>

void* some_work(void* arg) 
{
	for(int i = 0; i < 5; ++i) 
	{
		puts(arg);
	}
	return NULL;
}
int main(void) 
{ 
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, some_work, "Hello World" );
	pthread_create(&thread2, NULL, some_work, "Hello METANIT.COM" );
 
	printf("End...\n");
	return 0;
}
*/


int	main(int argc, char **argv)
{
	t_res	*res;

	if (argc < 5 || argc > 6)
		return (error_msg(ARGS_NUM));
	res = (t_res *)ft_calloc(1, sizeof(t_res));
	if (!res)
		return (error_msg(MLLC));
	if (validation(argc, argv, res))
	{
		clean_resourses(&res);
		return (1);
	}
	if (init_resourses(res))
	{
		clean_resourses(&res);
		return (1);
	}
	if (create_threads(res))
	{
		clean_resourses(&res);
		return (1);
	}
	if (join_threads(res))
	{
		clean_resourses(&res);
		return (1);
	}
	return (0);
}

/*
each philosopher is a thread
each fork is a mutex (mutual exclusion): variable, that can be locked or unlocked
	mutex protects object from other processes' access to it,
	bc only one thread can change the data of the object at a time


*/
