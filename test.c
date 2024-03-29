/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:27:49 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/01 12:53:15 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int		v;
	char	**ins;

	v = -1;
	ins = (char *[]){"brk", "jci", "jmi", "jsi", "lit", "li2", "lit", "li2"};
	while (++v <= 0xff)
	{
		if ((v % 0x20) == 0)
			printf("[0x%.2x]: %s\n", v, ins[v / 0x20]);
	}
}
