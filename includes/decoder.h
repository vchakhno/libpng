/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoder.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 01:02:15 by vchakhno          #+#    #+#             */
/*   Updated: 2024/03/01 03:23:36 by vchakhno         ###   ########.fr       */
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

#endif