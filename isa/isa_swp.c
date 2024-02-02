/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isa_swp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:33:09 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/01 18:14:51 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uvm.h"

t_ub	isa_swp(t_arg a)
{
	t_uw	x;
	t_uw	y;

	x = stk_popx(a.s, a.mk, a.m2);
	y = stk_popx(a.s, a.mk, a.m2);
	stk_pushx(a.s, x, a.m2);
	stk_pushx(a.s, y, a.m2);
	return (0);
}
