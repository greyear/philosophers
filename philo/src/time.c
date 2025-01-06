
#include "../include/philosophers.h"

size_t	get_time(void) //long? //tv inside the philo?
{
	struct timeval	tv;
	if (gettimeofday(&tv, NULL) == -1)
		return (-1); //protect after calling
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	//sec -> millisec			microces->millisec
}

int	wait_ms(size_t waiting_time) //what struct to put as an input?
{
	size_t	start;
	size_t	end;

	start = get_time();
	end = start + waiting_time;
	while (get_time() < end)
	{
		usleep(400); //protect usleep? //how to choose value?
		//add logic about other philos' death?
	}
	return (0);
}