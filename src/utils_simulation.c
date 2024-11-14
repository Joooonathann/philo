/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 02:57:19 by jalbiser          #+#    #+#             */
/*   Updated: 2024/11/14 12:32:46 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_simulation(t_data *data)
{
	int	i;

	if (data->forks)
	{
		i = 0;
		while (i < data->ph_total)
		{
			pthread_mutex_destroy(&data->forks[i].fork);
			i++;
		}
		free(data->forks);
		data->forks = NULL;
	}
	pthread_mutex_destroy(&data->mtx_get);
	pthread_mutex_destroy(&data->mtx_set);
	pthread_mutex_destroy(&data->mtx_write);
	if (data->philos)
	{
		free(data->philos);
		data->philos = NULL;
	}
}

static int	end_meal(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->ph_total)
	{
		if (data->philos[i].meals_total < data->meals_total)
			return (0);
		i++;
	}
	return (1);
}

void	write_status(t_philo *philo, char *status)
{
	if (philo->data->is_end)
		return ;
	printf("[PHILO] %ld %d %s\n", get_time(), philo->id, status);
}

void	*is_end(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (!get_value(&data->is_end, data))
	{
		i = 0;
		while (i < data->ph_total)
		{
			if ((get_time() - data->philos[i].last_meal) > data->time_to_die)
			{
				write_status(&data->philos[i], "died");
				set_value(&data->is_end, 1, data);
				break ;
			}
			if (end_meal(data) && data->meals_total != -1)
			{
				set_value(&data->is_end, 1, data);
				break ;
			}
			i++;
		}
	}
	return (NULL);
}
