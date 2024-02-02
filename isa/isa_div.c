/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isa_div.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:02:25 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/01 18:10:46 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uvm.h"

t_ub	isa_div(t_arg a)
{
	t_sw	x;
	t_sw	y;

	x = stk_popx(a.s, a.mk, a.m2);
	y = stk_popx(a.s, a.mk, a.m2);
	if (x)
		stk_pushx(a.s, y / x, a.m2);
	else
		stk_pushx(a.s, 0, a.m2);
	return (0);
}
