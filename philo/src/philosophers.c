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

//#include "../include/philosophers.h"

#include <pthread.h>
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


/*
void	*routine(char *str)
{

}


int	main(int argc, char **argv)
{
	
	return (0);
}*/

/*
each philosopher is a thread
each fork is a mutex (mutual exclusion): variable, that can be locked or unlocked
	mutex protects object from other processes' access to it,
	bc only one thread can change the data of the object at a time


*/
