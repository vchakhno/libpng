/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_IEND.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 01:05:15 by vchakhno          #+#    #+#             */
/*   Updated: 2024/03/15 03:34:05 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"
#include <criterion/criterion.h>

Test(IEND, no_IEND)
{
	t_image	image;

	cr_assert(!decode_png("ressources/IEND/no_IEND.png", &image));
}

Test(IEND, valid)
{
	t_image	image;

	cr_assert(decode_png("ressources/IEND/valid.png", &image));
}
