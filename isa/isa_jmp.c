/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isa_jmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:47:11 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/01 16:48:11 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uvm.h"

t_ub	isa_jmp(t_arg a)
{
	t_uw	x;

	x = stk_popx(a.s, a.mk, a.m2);
	aux_jump(a.pc, x, a.m2);
	return (0);
}
