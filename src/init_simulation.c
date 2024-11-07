/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:20:59 by jalbiser          #+#    #+#             */
/*   Updated: 2024/11/07 03:03:59 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_forks(t_data *data)
{
	data->forks = malloc(sizeof(t_fork) * data->ph_total);
	if (!data->forks)
		return (0);
	return (1);
}

static int	init_philos(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->ph_total);
	if (!data->philos)
		return (0);
	return (1);
}

int	init_simulation(t_data *data)
{
	int	i;

	i = 0;
	if (!init_forks(data) || !init_philos(data))
		return (0);
	while (i < data->ph_total)
	{
		data->philos[i].id = i;
		data->philos[i].last_meal = get_time();
		data->philos[i].meals_total = 0;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->ph_total];
		data->philos[i].data = data;
		data->philos[i].is_dead = 0;
		pthread_mutex_init(&data->forks[i].fork, NULL);
		i++;
	}
	return (1);
}
