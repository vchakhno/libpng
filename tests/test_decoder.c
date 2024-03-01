/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_decoder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 01:05:15 by vchakhno          #+#    #+#             */
/*   Updated: 2024/03/01 03:44:02 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"
#include <criterion/criterion.h>

Test(decoder, invalid_path)
{
	t_image	image;

	cr_assert(!decode_png("ressources/doesntexist.png", &image));
}

Test(decoder, invalid_signature)
{
	t_image	image;

	cr_assert(!decode_png("ressources/panoramic.jpg", &image));
}

Test(decoder, invalid_start_chunk)
{
	t_image	image;

	cr_assert(!decode_png("ressources/invalid_start_chunk.png", &image));
}

Test(decoder, invalid_dimensions)
{
	t_image	image;

	cr_assert(!decode_png("ressources/0x1.png", &image));
}

Test(decoder, valid_dimensions)
{
	t_image	image;

	cr_assert(decode_png("ressources/panoramic.png", &image));
	cr_assert(image.width == 1920);
	cr_assert(image.height == 1080);
}