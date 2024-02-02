/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isa_ovr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:41:09 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/01 16:41:54 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uvm.h"

t_ub	isa_ovr(t_arg a)
{
	t_uw	x;
	t_uw	y;

	x = stk_popx(a.s, a.mk, a.m2);
	y = stk_popx(a.s, a.mk, a.m2);
	stk_pushx(a.s, y, a.m2);
	stk_pushx(a.s, x, a.m2);
	stk_pushx(a.s, y, a.m2);
	return (0);
}
