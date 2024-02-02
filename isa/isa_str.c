/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isa_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:18:28 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/01 18:18:29 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uvm.h"

t_ub	isa_str(t_arg a)
{
	t_sb	x;
	t_uw	y;

	x = stk_pop(a.s, a.mk);
	y = stk_popx(a.s, a.mk, a.m2);
	aux_poke(a.u, *a.pc + x, y, a.m2);
	return (0);
}
