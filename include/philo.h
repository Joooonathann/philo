/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 22:44:59 by jalbiser          #+#    #+#             */
/*   Updated: 2024/11/05 01:13:04 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>

# define PH_MAX 200

typedef struct s_data
{
	long	ph_total;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	meals_total;
}			t_data;

int			get_data_numbers(int argc, char **argv, t_data *data);
bool		whitespace(char c);
bool		is_digit(char c);
long		ft_atol(const char *s);

#endif