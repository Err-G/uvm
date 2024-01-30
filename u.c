/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:57:00 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/01/30 10:45:55 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "u.h"

int	uxn_eval(t_uxn *u, t_u16 pc)
{
	t_u8	ins;

	if (!pc || u->dev[0x0f]) return 0;
	while (1)
	{
		ins = ram[pc++];
	}
}

int	main(int ac, char **av)
{
	int	fd;
	int	i;
	uxn	u;
}
