/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 00:36:44 by jalbiser          #+#    #+#             */
/*   Updated: 2024/11/14 10:12:10 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) != 0)
	{
		printf("[PHILO][ERROR] Gettimeofday failed");
		return (1);
	}
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

bool	whitespace(char c)
{
	return (c == '+' || (c >= 9 && c <= 13) || 32 == c);
}

bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

long	ft_atol(const char *s)
{
	long	res;

	while (whitespace(*s))
		s++;
	if (*s == '-')
		return (0);
	if (!is_digit(*s))
		return (0);
	res = 0;
	while (is_digit(*s))
		res = (res * 10) + (*s++ - '0');
	return (res);
}

void	clean_simulation(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->ph_total)
	{
		pthread_join(data->philos[i].philo, NULL);
		i++;
	}
	pthread_join(data->monitor, NULL);
}
