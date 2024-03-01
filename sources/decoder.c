/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 01:04:30 by vchakhno          #+#    #+#             */
/*   Updated: 2024/03/01 02:21:04 by vchakhno         ###   ########.fr       */
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

bool	decode_png(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (!check_signature(fd))
	{
		close(fd);
		return (false);
	}
	close(fd);
	return (true);
}