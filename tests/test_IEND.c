/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_IEND.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 01:05:15 by vchakhno          #+#    #+#             */
/*   Updated: 2024/03/15 04:02:12 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"
#include <criterion/criterion.h>

Test(IEND, no_IEND)
{
	t_image	image;

	cr_assert(!decode_png("ressources/IEND/no_IEND.png", &image));
}

Test(IEND, wrong_chunk_size)
{
	t_image	image;

	cr_assert(!decode_png("ressources/IEND/wrong_chunk_size.png", &image));
}

Test(IEND, early_EOF)
{
	t_image	image;

	cr_assert(!decode_png("ressources/IEND/early_EOF.png", &image));
}

Test(IEND, valid)
{
	t_image	image;

	cr_assert(decode_png("ressources/IEND/valid.png", &image));
}
