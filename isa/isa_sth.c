/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isa_sth.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:56:44 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/01 18:13:39 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uvm.h"

t_ub	isa_sth(t_arg a)
{
	t_uw	x;

	x = stk_popx(a.s, a.mk, a.m2);
	if (a.s == &a.u->wstk)
		stk_push2(&a.u->rstk, x);
	else
		stk_push2(&a.u->wstk, x);
	return (0);
}
