/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isa_pop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:26:39 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/01 16:28:23 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uvm.h"

t_ub	isa_pop(t_arg a)
{
	stk_popx(a.s, a.mk, a.m2);
	return (0);
}
