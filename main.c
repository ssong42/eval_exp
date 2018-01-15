/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 15:53:51 by ssong             #+#    #+#             */
/*   Updated: 2018/01/14 15:56:58 by ssong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistro.h"

int main(int argc, char **argv)
{
	char *str;
	long double result;
	int i;

	i = 0;
	result = 0;
	if (argv != 3 || !valid_base(argv[1]))
	{
		ft_putendl("syntax error\n");
		return (0);
	}
	str = read_stdin(ft_atoi(argv[2]));
	//str = convert_str(str, argv[1]);
	if (!parseSum(str, &i, &result))
	{
		printf("parse error\n");
		return (0);
	}
	printf("%Lf\n", result);
	return (0);
}
