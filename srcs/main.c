/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smickael <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 23:04:19 by smickael          #+#    #+#             */
/*   Updated: 2018/03/30 23:04:20 by smickael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*init_files_list(char **names_list, int ac, int first)
{
	t_file	*begin;
	int		i;

	begin = NULL;
	(!ac) ? add_new_file("", ".", &begin) :
		ft_sort_tab(names_list, ac, &ft_strcmp);
	i = -1;
	while (++i < ac)
		if (add_new_file("", names_list[i], &begin) == -1 && first)
			ls_error(names_list[i], ERRNO);
	return (begin);
}

int		main(int ac, char **av)
{
	int			i;
	int			flags;
	t_file		*file_lst;
	int			first;

	first = 2;
	if ((i = parsing(ac, av, &flags)) == -1)
		return (1);
	av += i;
	ac -= i;
	file_lst = init_files_list(av, ac, 1);
	display_all(file_lst, flags, first, ac);
	free_list_content(&file_lst);
	return (0);
}
