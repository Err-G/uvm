/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:40:26 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/01 14:50:58 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uvm.h"

void	aux_jump(t_uw *pc, t_uw addr, t_ub m2)
{
	if (m2)
		*pc = addr;
	else
		*pc += (t_ub)addr;
}

t_uw	aux_peek(t_uxn *u, t_uw addr, t_ub m2)
{
	if (m2)
		return ((u->ram[addr] << 8) | u->ram[addr + 1]);
	else
		return (u->ram[addr]);
}

void	aux_poke(t_uxn *u, t_uw addr, t_uw value, t_ub m2)
{
	if (m2)
	{
		u->ram[addr] = value >> 8;
		u->ram[addr + 1] = value;
	}
	else
		u->ram[addr] = value;
}

t_uw	aux_device_read(t_uxn *u, t_uw addr, t_ub m2)
{
	if (m2)
		return ((uvm_dei(u, addr) << 8) | uvm_dei(u, addr + 1));
	else
		return (uvm_dei(u, addr));
}

void	aux_device_write(t_uxn *u, t_uw addr, t_uw value, t_ub m2)
{
	if (m2)
	{
		uvm_deo(u, addr, value >> 8);
		uvm_deo(u, addr + 1, value);
	}
	else
		uvm_deo(u, addr, value);
}
