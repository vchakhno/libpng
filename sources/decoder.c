/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 01:04:30 by vchakhno          #+#    #+#             */
/*   Updated: 2024/03/15 01:20:03 by vchakhno         ###   ########.fr       */
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

// Decodes a four-byte unsigned integer according to the PNG specification.
// In the PNG spec, they only go up to 2**31-1, spanning 31 bits,
// hence the name u31.

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

//	General chunk layout:
//	 - Length				(4 bytes) [0, 2^31-1]
//	 - Chunk type			(4 bytes)
//	 - Chunk data			(length bytes)
//	 - CRC					(4 bytes)

// Decodes only the type and the length.

bool	decode_chunk_header(int fd, t_u32 *chunk_len, t_u8 chunk_type[4])
{
	if (!decode_u31(fd, chunk_len))
		return (false);
	if (read(fd, chunk_type, 4) != 4)
		return (false);
	return (true);
}

//	IHDR data layout:
//	 - Width				(4 bytes) [1, 2^31-1]
//	 - Height				(4 bytes) [1, 2^31-1]
//	 - Bit depth			(1 bytes) {1, 2, 4, 8, 16} (depends on colour type)
//	 - Colour type			(1 bytes) {0, 2, 3, 4, 6}
//	 - Compression method	(1 bytes) {0}
//	 - Filter method		(1 bytes) {0}
//	 - Interlace method		(1 bytes) {0, 1}

// Decodes the whole chunk, type and length included.

bool	decode_ihdr_header(int fd, t_u32 *width, t_u32 *height)
{
	t_u32	chunk_len;
	t_u8	chunk_type[4];

	if (!decode_chunk_header(fd, &chunk_len, chunk_type))
		return (false);
	if (chunk_len != 13 || !ft_mem_equal(chunk_type, "IHDR", 4))
		return (false);
	if (!decode_u31(fd, width) || !*width)
		return (false);
	if (!decode_u31(fd, height) || !*height)
		return (false);
	if (read(fd, (t_u8 [9]){0}, 9) != 9)
		return (false);
	return (true);
}

// Skips bytes present in unknown chunks.
// Optimally, we should check wether those chunks are critical,
// and check their CRC too.

bool	skip_bytes(int fd, t_u32 nb_bytes)
{
	t_u8	buf[1024];

	while (nb_bytes > 1024)
	{
		if (read(fd, buf, 1024) != 1024)
			return (false);
		nb_bytes -= 1024;
	}
	if (read(fd, buf, nb_bytes) != nb_bytes)
		return (false);
	return (true);
}

bool	decode_png_stream(int fd, t_image *image)
{
	t_u32	chunk_len;
	t_u8	chunk_type[4];

	if (!check_signature(fd))
		return (false);
	if (!decode_ihdr_header(fd, &image->width, &image->height))
		return (false);
	while (true)
	{
		if (!decode_chunk_header(fd, &chunk_len, chunk_type))
			return (false);
		if (ft_mem_equal(chunk_type, "IEND", 4))
			break ;
		if (!skip_bytes(fd, chunk_len + 4))
			return (false);
	}
	return (true);
}

bool	decode_png(char *file, t_image *image)
{
	int		fd;
	bool	status;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (false);
	status = decode_png_stream(fd, image);
	close(fd);
	return (status);
}
