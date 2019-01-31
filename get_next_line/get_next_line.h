/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaryn-h <fdaryn-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 22:41:09 by fdaryn-h          #+#    #+#             */
/*   Updated: 2019/01/31 23:08:05 by fdaryn-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10
# include "libft/libft.h"

typedef struct	s_lst
{
	int				fd;
	char			buf[BUFF_SIZE];
	ssize_t			len;
	ssize_t			olen;
	int				isn;
	int				null;
	char			**line;
	struct s_lst	*next;
}				t_lst;
int				get_next_line(const int fd, char **line);

#endif
