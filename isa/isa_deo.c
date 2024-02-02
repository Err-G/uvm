/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isa_deo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:31:52 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/01 17:35:49 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uvm.h"

t_ub	isa_deo(t_arg a)
{
	t_sb	x;
	t_sw	y;

	x = stk_pop(a.s, a.mk);
	y = stk_popx(a.s, a.mk, a.m2);
	aux_device_write(a.u, x, y, a.m2);
	return (0);
}
