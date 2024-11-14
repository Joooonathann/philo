/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:05:52 by jalbiser          #+#    #+#             */
/*   Updated: 2024/11/14 12:22:55 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_value(int *value, t_data *data)
{
	int	v;

	pthread_mutex_lock(&data->mtx_get);
	v = *value;
	pthread_mutex_unlock(&data->mtx_get);
	return (v);
}

void	set_value(int *value, int new, t_data *data)
{
	pthread_mutex_lock(&data->mtx_set);
	*value = new;
	pthread_mutex_unlock(&data->mtx_set);
}
