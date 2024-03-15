/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_IHDR.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 01:05:15 by vchakhno          #+#    #+#             */
/*   Updated: 2024/03/15 09:24:40 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"
#include <criterion/criterion.h>

Test(IHDR, wrong_chunk_size)
{
	t_image	image;

	cr_assert(!decode_png("ressources/IHDR/wrong_chunk_size.png", &image));
}

Test(IHDR, wrong_chunk_type)
{
	t_image	image;

	cr_assert(!decode_png("ressources/IHDR/wrong_chunk_type.png", &image));
}

Test(IHDR, zero_width)
{
	t_image	image;

	cr_assert(!decode_png("ressources/IHDR/0x1080.png", &image));
}

Test(IHDR, zero_height)
{
	t_image	image;

	cr_assert(!decode_png("ressources/IHDR/1920x0.png", &image));
}

Test(IHDR, width_too_high)
{
	t_image	image;

	cr_assert(!decode_png("ressources/IHDR/2^31x1080.png", &image));
}

Test(IHDR, height_too_high)
{
	t_image	image;

	cr_assert(!decode_png("ressources/IHDR/1920x2^31.png", &image));
}

Test(IHDR, wrong_crc)
{
	t_image	image;

	cr_assert(!decode_png("ressources/IHDR/wrong_crc.png", &image));
}

Test(IHDR, valid_dimensions)
{
	t_image	image;

	cr_assert(decode_png("ressources/IHDR/valid.png", &image));
	cr_assert(image.width == 1920);
	cr_assert(image.height == 1080);
}
