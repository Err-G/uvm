/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stkx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 23:18:55 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/01/31 19:33:24 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uvm.h"

t_uw	stk_popx(t_stk *stk, t_ub mk, t_ub m2);
void	stk_pushx(t_stk *stk, t_uw value, t_ub m2);

t_uw	stk_popx(t_stk *stk, t_ub mk, t_ub m2)
{
	if (m2)
		return (stk_pop2(stk, mk));
	else
		return (stk_pop(stk, mk));
}

void	stk_pushx(t_stk *stk, t_uw value, t_ub m2)
{
	if (m2)
		stk_push2(stk, value);
	else
		stk_push(stk, value);
}
