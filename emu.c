/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:56:15 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/01 19:33:49 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uvm.h"
#include <unistd.h>
#include <fcntl.h>

t_ub	uvm_dei(t_uxn *u, t_ub addr)
{
	return (u->dev[addr]);
}

void	uvm_deo(t_uxn *u, t_ub addr, t_ub value)
{
	u->dev[addr] = value;
	if (addr == 0x18)
		write(1, &u->dev[0x18], 1);
	if (addr == 0x19)
		write(2, &u->dev[0x19], 1);
}

int	usage(char *name)
{
	int	i;

	i = -1;
	write(1, "usage: ", 7);
	while (name[++i])
		write(1, &name[i], 1);
	write(1, " file.rom [args ...]\n", 21);
	return (0);
}

char	ft_getc(int fd)
{
	char	res;

	read(fd, &res, 1);
	return (res);
}

int	cli_in(t_uxn *u, char c, int type)
{
	t_uw	vector;

	vector = u->dev[0x10] << 8 | u->dev[0x11];
	u->dev[0x12] = c;
	u->dev[0x17] = type;
	return (uvm_eval(u, vector));
}

int	main(int ac, char **av)
{
	int		fd;
	int		i;
	char	c;
	char	*p;
	t_uxn	u;

	if (ac == 1)
		return (usage(av[0]));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (1);
	read(fd, &u.ram[0x100], 0xff00);
	close(fd);
	u.dev[0x17] = ac - 1;
	if (uvm_eval(&u, 0x0100))
	{
		write(1, "eval\n", 5);
		i = 0;
		while (++i < ac)
		{
			p = av[i];
			while (*p)
				cli_in(&u, *p++, 2);
			if (i == ac - 1)
				cli_in(&u, '\n', 4);
			else
				cli_in(&u, '\n', 3);
		}
		while (!u.dev[0xf])
		{
			c = ft_getc(0);
			if (c == -1)
				cli_in(&u, 0, 4);
			if (c == -1)
				break ;
			cli_in(&u, (t_ub)c, 1);
		}
	}
	return (u.dev[0xf] & 0x7f);
}
