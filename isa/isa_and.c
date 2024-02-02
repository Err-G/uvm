/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isa_and.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:05:56 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/01 18:09:35 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uvm.h"

t_ub	isa_and(t_arg a)
{
	t_sw	x;
	t_sw	y;

	x = stk_popx(a.s, a.mk, a.m2);
	y = stk_popx(a.s, a.mk, a.m2);
	stk_pushx(a.s, y & x, a.m2);
	return (0);
}
