/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uvm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:57:00 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/01 20:19:28 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "uvm.h"

t_arg	get_arg(t_uxn *u, t_uw *pc)
{
	t_arg	res;

	res.u = u;
	res.ins = u->ram[*pc];
	res.pc = pc;
	(*res.pc)++;
	res.mk = res.ins & 0x80;
	res.m2 = res.ins & 0x20;
	if (res.ins & 0x40)
		res.s = &u->rstk;
	else
		res.s = &u->wstk;
	return (res);
}

/* imm: brk, jci, jmi, jsi, lit, li2;
 * opr: inc, pop, nip, swp, rot, dup, ovr, equ, neq, gth, lth, jmp, jcn, jsr,
 * sth, ldz, stz, ldr, str, lda, sta, dei, deo, add, sub, mul, div, and, ora,
 * eor, sft
 */
t_ub	uvm_eval(t_uxn *u, t_uw pc)
{
	t_isa	*imm;
	t_isa	*opr;
	t_arg	arg;
	t_ub	res;

	imm = (t_isa[]){
		isa_brk, isa_jci, isa_jmi, isa_jsi, isa_lit, isa_li2, isa_lit, isa_li2};
	opr = (t_isa[]){
		isa_inc, isa_pop, isa_nip, isa_swp, isa_rot, isa_dup, isa_ovr, isa_equ,
		isa_neq, isa_gth, isa_lth, isa_jmp, isa_jcn, isa_jsr, isa_sth, isa_ldz,
		isa_stz, isa_ldr, isa_str, isa_lda, isa_sta, isa_dei, isa_deo, isa_add,
		isa_sub, isa_mul, isa_div, isa_and, isa_ora, isa_eor, isa_sft};
	if (!pc || u->dev[0x0f])
		return (0);
	while (1)
	{
		arg = get_arg(u, &pc);
		if ((arg.ins & 0x1f) == 0 && (arg.ins % 0x20) == 0)
			res = imm[arg.ins / 0x20](arg);
		else
			res = opr[arg.ins](arg);
		if (res)
			return ((int)res);
	}
}
