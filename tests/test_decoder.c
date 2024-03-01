/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_decoder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 01:05:15 by vchakhno          #+#    #+#             */
/*   Updated: 2024/03/01 03:13:40 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"
#include <criterion/criterion.h>

Test(decoder, invalid_path)
{
	cr_assert(!decode_png("ressources/doesntexist.png"));
}

Test(decoder, invalid_signature)
{
	cr_assert(!decode_png("ressources/panoramic.jpg"));
}

Test(decoder, invalid_start_chunk)
{
	cr_assert(!decode_png("ressources/invalid_start_chunk.png"));
}

Test(decoder, valid_start_chunk)
{
	cr_assert(decode_png("ressources/panoramic.png"));
}
