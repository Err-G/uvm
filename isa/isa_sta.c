/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isa_sta.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:20:04 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/01 17:21:36 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uvm.h"

t_ub	isa_sta(t_arg a)
{
	t_sw	x;
	t_uw	y;

	x = stk_pop2(a.s, a.mk);
	y = stk_popx(a.s, a.mk, a.m2);
	aux_poke(a.u, x, y, a.m2);
	return (0);
}
