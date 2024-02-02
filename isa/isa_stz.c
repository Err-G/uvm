/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isa_stz.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:06:31 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/01 17:11:55 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uvm.h"

t_ub	isa_stz(t_arg a)
{
	t_ub	x;
	t_uw	y;

	x = stk_pop(a.s, a.mk);
	y = stk_popx(a.s, a.mk, a.m2);
	aux_poke(a.u, x, y, a.m2);
	return (0);
}
