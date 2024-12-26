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

int error_msg(int code)
{
	if (code == 1)
		printf("Invalid number of arguments\n");
	if (code == 2)
		printf("Invalid arguments\n");
	return (1);
}