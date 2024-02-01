/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uvm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:57:09 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/01 13:02:32 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UVM_H
# define UVM_H

/* types */
typedef unsigned char	t_ub; /* unsigned byte  */
typedef unsigned short	t_uw; /* unsigned word  */
typedef unsigned int	t_ud; /* unsigned dword */

typedef signed char		t_sb; /* signed byte  */
typedef signed short	t_sw; /* signed word  */
typedef signed int		t_sd; /* signed dword */

/* stack */
typedef struct s_stk	t_stk;
struct s_stk
{
	t_ub	dat[0x100]; /* data */
	t_ub	ptr; /* pointer */
};

t_ub		stk_pop(t_stk *stk, t_ub mk);
void		stk_push(t_stk *stk, t_ub value);

t_uw		stk_pop2(t_stk *stk, t_ub mk);
void		stk_push2(t_stk *stk, t_uw value);

t_uw		stk_popx(t_stk *stk, t_ub mk, t_ub m2);
void		stk_pushx(t_stk *stk, t_uw value, t_ub m2);

/* uxn */
typedef struct s_uxn	t_uxn;
struct s_uxn
{
	t_ub	ram[0x10000]; /* memory */
	t_ub	dev[0x100]; /* devices */
	t_stk	wstk; /* working stack */
	t_stk	rstk; /* return stack */
};

void		aux_jump(t_uw *pc, t_uw addr, t_ub m2);
t_uw		aux_peek(t_uxn *u, t_uw addr, t_ub m2);
void		aux_poke(t_uxn *u, t_uw addr, t_uw value, t_ub m2);
t_uw		aux_device_read(t_uxn *u, t_uw addr, t_ub m2);
void		aux_device_write(t_uxn *u, t_uw addr, t_uw value, t_ub m2);

typedef struct s_arg t_arg;
struct s_arg
{
	t_uxn	*u;
	t_stk	*s;
	t_uw	*pc;
	t_ub	ins;
	t_ub	mk;
	t_ub	m2;
};

typedef t_ub			(*t_isa)(t_arg a);

t_ub		isa_brk(t_arg a);
t_ub		isa_jci(t_arg a);
t_ub		isa_jmi(t_arg a);
t_ub		isa_jsi(t_arg a);
t_ub		isa_lit(t_arg a);
t_ub		isa_li2(t_arg a);

t_ub		isa_inc(t_arg a);
t_ub		isa_pop(t_arg a);
t_ub		isa_nip(t_arg a);
t_ub		isa_swp(t_arg a);
t_ub		isa_rot(t_arg a);
t_ub		isa_dup(t_arg a);
t_ub		isa_ovr(t_arg a);
t_ub		isa_equ(t_arg a);
t_ub		isa_neq(t_arg a);
t_ub		isa_gth(t_arg a);
t_ub		isa_lth(t_arg a);
t_ub		isa_jmp(t_arg a);
t_ub		isa_jcn(t_arg a);
t_ub		isa_jsr(t_arg a);
t_ub		isa_sth(t_arg a);
t_ub		isa_ldz(t_arg a);
t_ub		isa_stz(t_arg a);
t_ub		isa_ldr(t_arg a);
t_ub		isa_str(t_arg a);
t_ub		isa_lda(t_arg a);
t_ub		isa_sta(t_arg a);
t_ub		isa_dei(t_arg a);
t_ub		isa_deo(t_arg a);
t_ub		isa_add(t_arg a);
t_ub		isa_sub(t_arg a);
t_ub		isa_mul(t_arg a);
t_ub		isa_div(t_arg a);
t_ub		isa_and(t_arg a);
t_ub		isa_ora(t_arg a);
t_ub		isa_eor(t_arg a);
t_ub		isa_sft(t_arg a);

t_ub		uvm_eval(t_uxn *u, t_uw pc);

extern t_ub	uvm_dei(t_uxn *u, t_ub addr);
extern void	uvm_deo(t_uxn *u, t_ub addr, t_ub value);

#endif
