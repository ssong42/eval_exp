/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bistro.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 15:55:14 by ssong             #+#    #+#             */
/*   Updated: 2018/01/14 15:59:58 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BISTRO_H
# define BISTR_H
#include "libft/libft.h"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
long double		parseSum (char *str, int *i, long double *sum);
void			parseSign (char *str, int *i, long double *sign);
void			parseNumber (char *str, int *i, long double *number, long double sign);
long double		parseFactor(char *str, int *i, long double *fac);
long double		parseProduct(char *str, int *i, long double *pro);
long double		parseSum (char *str, int *i, long double *sum);

#endif
