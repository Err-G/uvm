/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isa_jsr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:51:43 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/01 18:12:23 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uvm.h"

t_ub	isa_jsr(t_arg a)
{
	t_uw	x;

	x = stk_popx(a.s, a.mk, a.m2);
	if (a.s == &a.u->wstk)
		stk_push2(&a.u->rstk, *a.pc);
	else
		stk_push2(&a.u->wstk, *a.pc);
	aux_jump(a.pc, x, a.m2);
	return (0);
}
