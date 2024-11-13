/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 02:57:19 by jalbiser          #+#    #+#             */
/*   Updated: 2024/11/13 09:43:38 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	end_meal(t_data *data)
{
	int		i;

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
	while (!data->is_end)
	{
		i = 0;
		while (i < data->ph_total)
		{
			if ((get_time() - data->philos[i].last_meal) > data->time_to_die)
			{
				write_status(&data->philos[i], "died");
				data->is_end = 1;
				break ;
			}
			if (end_meal(data) && data->meals_total != -1)
			{
				data->is_end = 1;
				break ;
			}
			i++;
		}
	}
	return (NULL);
}
