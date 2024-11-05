/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalbiser <jalbiser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 00:36:44 by jalbiser          #+#    #+#             */
/*   Updated: 2024/11/05 01:00:27 by jalbiser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	long res;

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
