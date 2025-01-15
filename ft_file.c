/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_file.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbakker <jbakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 13:17:49 by jbakker       #+#    #+#                 */
/*   Updated: 2025/01/15 14:18:44 by jbakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_file.h"

t_file	*ft_file_open(const char *filename, int flags)
{
	t_file	*file;

	file = (t_file *)ft_calloc(1, sizeof(t_file));
	if (!file)
		return (NULL);
	file->fd = open(filename, flags);
	if (file->fd < 0)
		return (free(file), NULL);
	return (file);
}

void	ft_file_close(t_file **file)
{
	if ((*file)->fd >= 0)
		close((*file)->fd);
	if ((*file)->buff.data)
		free((*file)->buff.data);
	free(*file);
	*file = NULL;
}

char	*ft_file_get_next_line(t_file *file)
{
	char		*line;
	size_t		i;

	i = 0;
	while (1)
	{
		if (i >= file->buff.len)
		{
			if (file->buff.eof)
			{
				line = file->buff.data;
				if (line)
					line[file->buff.len] = '\0';
				file->buff.data = NULL;
				file->buff.len = 0;
				return (line);
			}
			file->error = ft_file_fill_buffer(file, file->buff.len + BUFF_SIZE);
			if (file->error)
				return (NULL);
		}
		if (file->buff.data[i] == '\n')
			return (ft_file_extract_str_from_buffer(&file->buff, 0, i + 1));
		i++;
	}
}

char	*ft_file_readall(t_file *file)
{
	char	*out;

	while (!file->buff.eof)
	{
		file->error = ft_file_fill_buffer(\
			file, (BUFF_SIZE + file->buff.len) * 2);
		if (file->error)
			return (NULL);
	}
	out = file->buff.data;
	if (out)
		out[file->buff.len] = '\0';
	file->buff.data = NULL;
	file->buff.len = 0;
	return (out);
}

char	**ft_file_readlines(t_file *file)
{
	char	*file_content;
	char	**lines;

	file_content = ft_file_readall(file);
	if (!file_content)
		return (NULL);
	lines = ft_split(file_content, '\n');
	return (free(file_content), lines);
}
