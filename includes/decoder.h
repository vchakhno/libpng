/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoder.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 01:02:15 by vchakhno          #+#    #+#             */
/*   Updated: 2024/03/15 09:02:26 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECODER_H
# define DECODER_H

# include <stdbool.h>
# include <libft/libft.h>

typedef struct s_image
{
	t_u32	width;
	t_u32	height;
}	t_image;

bool	decode_png(char *file, t_image *image);
t_u32	update_crc32(t_u32 crc, t_u8 *bytes, t_u32 size);
t_u32	compute_crc32(t_u8 *bytes, t_u32 size);
bool	read_exact_with_crc(int fd, t_u8 *bytes, t_u32 size, t_u32 *crc);
bool	decode_u31_with_crc(int fd, t_u32 *n, t_u32 *crc);
bool	skip_bytes_with_crc(int fd, t_u32 nb_bytes, t_u32 *crc);

#endif