/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isa_dei.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:23:46 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/01 17:25:45 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uvm.h"

t_ub	isa_dei(t_arg a)
{
	t_sb	x;

	x = stk_pop(a.s, a.mk);
	stk_pushx(a.s, aux_device_read(a.u, x, a.m2), a.m2);
	return (0);
}
