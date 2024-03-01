/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 01:04:30 by vchakhno          #+#    #+#             */
/*   Updated: 2024/03/01 03:34:09 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"
#include <unistd.h>
#include <fcntl.h>

bool	check_signature(int fd)
{
	t_u8	signature[8];

	if (read(fd, signature, 8) != 8)
		return (false);
	if (!ft_mem_equal(signature, "\x89\x50\x4E\x47\x0D\x0A\x1A\x0A", 8))
		return (false);
	return (true);
}

bool	decode_u31(int fd, t_u32 *n)
{
	t_u8	bytes[4];

	if (read(fd, bytes, 4) != 4)
		return (false);
	if (bytes[0] > 0x7f)
		return (false);
	*n = bytes[0] << 24 | bytes[1] << 16 | bytes[2] << 8 | bytes[3];
	return (true);
}

bool	decode_ihdr_header(int fd, t_u32 *width, t_u32 *height)
{
	t_u32	chunk_len;
	char	chunk_type[4];

	if (!decode_u31(fd, &chunk_len) || chunk_len != 13)
		return (false);
	if (read(fd, chunk_type, 4) != 4 || !ft_mem_equal(chunk_type, "IHDR", 4))
		return (false);
	if (!decode_u31(fd, width) || !decode_u31(fd, height))
		return (false);
	return (true);
}

bool	decode_png(char *file, t_image *image)
{
	int		fd;

	(void) image;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (false);
	if (!check_signature(fd))
	{
		close(fd);
		return (false);
	}
	if (!decode_ihdr_header(fd, &image->width, &image->height))
	{
		close(fd);
		return (false);
	}
	close(fd);
	return (true);
}
