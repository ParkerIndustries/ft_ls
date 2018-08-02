/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smickael <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 22:57:16 by smickael          #+#    #+#             */
/*   Updated: 2018/03/30 22:57:22 by smickael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <time.h>
# include <sys/types.h>
# include <sys/acl.h>
# include <sys/xattr.h>
# include <limits.h>
# include <sys/ioctl.h>

enum	e_list
{
	ERRNO,
	USAGE
};

# define LS_A	1
# define LS_L	2
# define LS_RR	4
# define LS_R	8
# define LS_T	16
# define LS_D	32
# define LS_G	64
# define LS_ONE 128
# define LS_SS	256
# define LS_S	512

typedef struct stat		t_stat;
typedef struct dirent	t_dirent;
typedef struct passwd	t_passwd;
typedef struct group	t_group;

typedef struct			s_index
{
	int					y;
	int					x;
}						t_index;

typedef struct			s_file
{
	blkcnt_t			st_blocks;
	mode_t				mode;
	nlink_t				st_nlink;
	uid_t				st_uid;
	gid_t				st_gid;
	off_t				size;
	dev_t				st_rdev;
	time_t				time;
	long				ntime;
	char				*name;
	char				full_path[PATH_MAX];
	struct s_file		*next;
	t_list				list;
}						t_file;

int						parsing(int ac, char **av, int *flags);
int						parse_options(char *s, int *flags);
int						ls_error(char *s, int error);

t_file					*init_files_list(char **av, int ac, int first);
void					only_files(t_file **begin);
int						add_new_file(char path[PATH_MAX], char *name,
		t_file **begin);

int						display_all(t_file *begin, int flags,
		t_bool recursive, int no_files);

int						sort_list(t_file**begin, short flags);
t_file					*ft_reverse_lst(t_file *lst);

int						display_list(t_file **begin, int options);

int						display_detailed_list(t_file *begin, int flags);
int						get_row_size(t_file *begin, int size[6], int *total);
int						display_list_items(t_file *file,
		int size[5], int flags);

void					display_name(t_file *l, int flags, int blocks_len);

t_file					*lst_swap(t_file *p1, t_file *p2);
int						lst_maxlen(t_file *lst);
int						free_list_content(t_file **lst);
int						integer_len(int n);
int						ft_sort_tab(char **tab, int size,
		int (*f)(const char*, const char*));

#endif
