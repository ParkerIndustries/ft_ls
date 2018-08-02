/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smickael <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 23:03:29 by smickael          #+#    #+#             */
/*   Updated: 2018/03/30 23:03:31 by smickael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	lst_column(t_file *lst, t_index row_col, t_index maxlen, int flags)
{
	int				tmp_column;
	int				tmp_row;
	t_file			*lst_tmp;
	int				counter;

	counter = row_col.y;
	while (lst && counter--)
	{
		tmp_column = row_col.x;
		lst_tmp = lst->next;
		while (lst && tmp_column--)
		{
			display_name(lst, flags, maxlen.y);
			if (tmp_column)
				ft_putnchar(MAX(maxlen.x - ft_strlen(lst->name), 0), ' ');
			tmp_row = row_col.y;
			while (lst && tmp_row--)
				lst = lst->next;
		}
		ft_putchar('\n');
		lst = lst_tmp;
	}
	return (1);
}

int			lst_blocks_len(t_file *lst, int *total)
{
	int				maxlen;

	maxlen = 0;
	while (lst)
	{
		maxlen = MAX(integer_len(lst->st_blocks), maxlen);
		*total += lst->st_blocks;
		lst = lst->next;
	}
	return (maxlen);
}

static int	display_basic_list(t_file *lst, int flags)
{
	t_index			maxlen;
	struct ttysize	ts;
	t_index			i;
	t_file			*tmp_lst;
	int				total;

	total = 0;
	maxlen.x = lst_maxlen(lst) + ((flags & LS_G) ? 1 : 4);
	maxlen.y = (flags & LS_S) ? lst_blocks_len(lst, &total) : 0;
	if (flags & LS_S)
		ft_printf("total %d\n", total);
	ioctl(0, TIOCGWINSZ, &ts);
	i.x = (!(flags & 128)) ? ts.ts_cols / (maxlen.x + maxlen.y) : 1;
	i.y = 0;
	tmp_lst = lst;
	while (tmp_lst)
	{
		++i.y;
		tmp_lst = tmp_lst->next;
	}
	if (!(flags & 128))
		i.y = (i.y % i.x ? 1 : 0) + (i.y / i.x);
	lst_column(lst, i, maxlen, flags);
	return (1);
}

int			display_list(t_file **lst, int flags)
{
	sort_list(lst, flags);
	if (!(flags & LS_L))
		display_basic_list(*lst, flags);
	else
		display_detailed_list(*lst, flags);
	return (1);
}

void		display_name(t_file *l, int flags, int blocks_len)
{
	if (blocks_len)
	{
		ft_putnchar(MAX(blocks_len - integer_len(l->st_blocks), 0), ' ');
		ft_printf("%d ", l->st_blocks);
	}
	if (flags & LS_G)
	{
		if (S_ISDIR(l->mode))
			ft_printf("%{cyan}%s%{eoc}", l->name);
		else
			ft_printf((S_IXUSR & l->mode) ? "%{red}%s%{eoc}" : "%s", l->name);
	}
	else
		ft_printf("%s", l->name);
}
