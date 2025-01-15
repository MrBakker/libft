/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_file_buffer.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 13:10:45 by jbakker       #+#    #+#                 */
/*   Updated: 2025/01/15 14:18:34 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_file.h"

static t_file_err	resize_buffer(t_file_buffer *buff, size_t new_capacity)
{
	char	*new;

	if (new_capacity <= buff->capacity)
		return (NONE);
	new = (char *)malloc(new_capacity * sizeof(char));
	if (!new)
		return (MALLOC);
	ft_memcpy(new, buff->data, buff->len * sizeof(char));
	free(buff->data);
	buff->data = new;
	buff->capacity = new_capacity;
	return (NONE);
}

t_file_err	ft_file_fill_buffer(t_file *file, size_t new_len)
{
	int	chars_read;

	if (file->buff.eof)
		return (EOF_REACHED);
	if (new_len > file->buff.capacity)
		if (resize_buffer(&file->buff, new_len) == MALLOC)
			return (MALLOC);
	chars_read = read(file->fd, file->buff.data + \
						file->buff.len, new_len - file->buff.len);
	if (chars_read < 0)
		return (READ);
	file->buff.len += chars_read;
	if ((size_t)chars_read < new_len - file->buff.len)
		file->buff.eof = 1;
	return (NONE);
}

char	*ft_file_extract_str_from_buffer(\
	t_file_buffer *buff, size_t start, size_t len)
{
	char	*str;

	if (start + len > buff->len)
		return (NULL);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	ft_memcpy(str, buff->data + start, len * sizeof(char));
	ft_memcpy(buff->data + start, buff->data + start + len, \
		(buff->len - start - len) * sizeof(char));
	buff->len -= len;
	return (str);
}
