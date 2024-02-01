/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 22:59:06 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/01 14:54:38 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uvm.h"

t_ub	stk_pop(t_stk *stk, t_ub mk);
void	stk_push(t_stk *stk, t_ub value);
t_uw	stk_pop2(t_stk *stk, t_ub mk);
void	stk_push2(t_stk *stk, t_uw value);

t_ub	stk_pop(t_stk *stk, t_ub mk)
{
	if (mk)
		return (stk->dat[stk->ptr]);
	else
		return (stk->dat[--stk->ptr]);
}

void	stk_push(t_stk *stk, t_ub value)
{
	stk->dat[stk->ptr++] = value;
}

t_uw	stk_pop2(t_stk *stk, t_ub mk)
{
	if (mk)
	{
		return (stk->dat[stk->ptr - 1] | stk->dat[stk->ptr - 2] << 8);
	}
	else
		return (stk_pop(stk, mk) | stk_pop(stk, mk) << 8);
}

void	stk_push2(t_stk *stk, t_uw value)
{
	stk_push(stk, value >> 8);
	stk_push(stk, value);
}
