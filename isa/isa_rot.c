/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isa_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:36:50 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/01 16:39:50 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uvm.h"

t_ub	isa_rot(t_arg a)
{
	t_uw	x;
	t_uw	y;
	t_uw	z;

	x = stk_popx(a.s, a.mk, a.m2);
	y = stk_popx(a.s, a.mk, a.m2);
	z = stk_popx(a.s, a.mk, a.m2);
	stk_pushx(a.s, y, a.m2);
	stk_pushx(a.s, x, a.m2);
	stk_pushx(a.s, z, a.m2);
	return (0);
}
