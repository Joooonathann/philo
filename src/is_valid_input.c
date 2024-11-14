/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 00:13:40 by jalbiser          #+#    #+#             */
/*   Updated: 2024/11/14 16:57:10 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	set_number(char **argv, t_data *data)
{
	data->ph_total = ft_atol(argv[1]);
	if (data->ph_total > PH_MAX)
	{
		printf("[PHILO][ERROR] Input incorrect\n");
		return (0);
	}
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	data->is_end = 0;
	pthread_mutex_init(&data->mtx_get, NULL);
	pthread_mutex_init(&data->mtx_set, NULL);
	pthread_mutex_init(&data->mtx_write, NULL);
	if (argv[5])
		data->meals_total = ft_atol(argv[5]);
	else
		data->meals_total = -1;
	return (1);
}

static int	is_valid_number(char **argv)
{
	int		i;
	long	z;

	i = 1;
	while (argv[i])
	{
		z = ft_atol(argv[i]);
		if (z > INT_MAX)
		{
			printf("[PHILO][ERROR] Input incorrect\n");
			return (0);
		}
		if (z < 1)
		{
			printf("[PHILO][ERROR] Input incorrect\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	get_data_numbers(int argc, char **argv, t_data *data)
{
	if (argc < 5 || argc > 6)
	{
		printf("[PHILO][ERROR] Input incorrect\n");
		return (0);
	}
	if (!is_valid_number(argv))
		return (0);
	if (!set_number(argv, data))
		return (0);
	return (1);
}
