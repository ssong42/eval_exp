/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_exp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:04:45 by ssong             #+#    #+#             */
/*   Updated: 2018/01/14 16:00:40 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistro.h"

long double		parseSum (char *str, int *i, long double *sum);

void		parseSign (char *str, int *i, long double *sign)
{
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign *= -1;
		(*i)++;
	}
}

void		parseNumber (char *str, int *i, long double *number, long double sign)
{
	long double	deci;

	deci = 1;
	*number = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*number = *number * 10;
		*number += str[*i] - '0';
		(*i)++;
	}
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			deci = deci / 10;
	   		*number = *number + (str[*i] - '0') * deci;
			(*i)++;
		}
	}
	*number *= sign;
}

long double		parseFactor(char *str, int *i, long double *fac)
{
	long double sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
		parseSign(str, i, &sign);
	if (str[*i] >= '0' && str[*i] <= '9')
	{
		parseNumber(str, i, fac, sign);
		return (1);
	}
	else if (str[*i] == '(')
	{
		(*i)++;
		if (parseSum(str, i, fac))
		{	
			(*i)++;
			return (1);
		}
	}
	return (0);
}

long double		parseProduct(char *str, int *i, long double *pro)
{
	long double fac1;
	long double fac2;

	if (!parseFactor(str, i, &fac1))
		return (0);
	while (str[*i] == '*' || str[*i] == '/')
	{
		if (str[*i] == '*')
		{
			(*i)++;
			if (!parseFactor(str, i, &fac2))
				return (0);
			fac1 = fac1 * fac2;
		}
		else if (str[*i] == '/')
		{
			(*i)++;
			if (!parseFactor(str, i, &fac2))
				return (0);
			fac1 = fac1 / fac2;
		}
	}
	*pro = fac1;
	return (1);
}

long double		parseSum (char *str, int *i, long double *sum)
{
	long double pro1;
	long double pro2;

	if (!parseProduct(str, i, &pro1))
		return (0);
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '+')
		{
			(*i)++;
			if (!parseProduct(str, i, &pro2))
				return (0);
			pro1 = pro1 + pro2;
		}
		else if (str[*i] == '-')
		{
			(*i)++;
			if (!parseProduct(str, i, &pro2))
				return (0);
			pro1 = pro1 - pro2;
		}
	}
	*sum = pro1;
	return (1);
}


