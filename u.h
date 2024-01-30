/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:57:09 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/01/30 11:32:41 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef U_H
# define U_H

typedef unsigned char	t_u8;
typedef unsigned short	t_u16;
typedef unsigned int	t_u32;

typedef signed char		t_s8;
typedef signed short	t_s16;
typedef signed int		t_s32;

typedef struct s_stk	t_stk;
struct s_stk
{
	t_u8	data[0x100];
	t_u8	ptr;
};

typedef struct s_uxn	t_uxn;
struct s_uxn
{
	t_u8	ram[0x10000];
	t_u8	dev[0x100];
	t_stk	wst;
	t_stk	rst;
};

int	uxn_eval(t_uxn *u, t_u16 pc);

#endif
