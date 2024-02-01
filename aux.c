/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:40:26 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/01/31 19:21:55 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uvm.h"

void	aux_jump(t_uw pc, t_uw addr, t_ub m2)
{
	if (m2)
		pc = addr;
	else
		pc += (t_ub)addr;
}

t_uw	aux_peek(t_uxn *u, t_uw addr, t_ub m2)
{
	if (m2)
		return ((u->ram[addr++] << 8) | u->ram[addr]);
	else
		return (u->ram[addr]);
}

void	aux_poke(t_uxn *u, t_uw addr, t_uw value, t_ub m2)
{
	if (m2)
	{
		u->ram[addr++] = value >> 8;
		u->ram[addr] = value;
	}
	else
		u->ram[addr] = value;
}

t_uw	aux_device_read(t_uxn *u, t_uw addr, t_ub m2)
{
	if (m2)
		return ((uvm_dei(u, addr++) << 8) | uvm_dei(u, addr));
	else
		return (uvm_dei(u, addr));
}

void	aux_device_write(t_uxn *u, t_uw addr, t_uw value, t_ub m2)
{
	if (m2)
	{
		uvm_deo(u, addr++, value >> 8);
		uvm_deo(u, addr, value);
	}
	else
		uvm_deo(u, addr, value);
}
