/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_file.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 13:07:18 by jbakker       #+#    #+#                 */
/*   Updated: 2025/01/15 14:17:47 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

#define BUFF_SIZE 1024

typedef enum e_file_err
{
	NONE,
	MALLOC,
	READ,
	EOF_REACHED
}	t_file_err;

typedef struct s_file_buffer
{
	char	*data;
	size_t	len;
	size_t	capacity;
	short	eof;
}	t_file_buffer;

typedef struct s_file
{
	int				fd;
	t_file_err		error;
	t_file_buffer	buff;
}	t_file;

t_file_err	ft_file_fill_buffer(t_file *file, size_t new_len);
char		*ft_file_extract_str_from_buffer(t_file_buffer *buff, \
											size_t start, size_t len);

t_file		*ft_file_open(const char *filename, int flags);
void		ft_file_close(t_file **file);

char		*ft_file_readall(t_file *file);
char		*ft_file_get_next_line(t_file *file);
char		**ft_file_readlines(t_file *file);