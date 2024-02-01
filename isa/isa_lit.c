/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isa_lit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:13:33 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/01 16:15:24 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uvm.h"

t_ub	isa_lit(t_arg a)
{
	stk_push(a.s, a.u->ram[*a.pc++]);
	return (0);
}