/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isa_eor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:06:56 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/01 18:09:17 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uvm.h"

t_ub	isa_eor(t_arg a)
{
	t_sw	x;
	t_sw	y;

	x = stk_popx(a.s, a.mk, a.m2);
	y = stk_popx(a.s, a.mk, a.m2);
	stk_pushx(a.s, y ^ x, a.m2);
	return (0);
}
