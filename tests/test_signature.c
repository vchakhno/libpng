/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_signature.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 01:05:15 by vchakhno          #+#    #+#             */
/*   Updated: 2024/03/15 02:17:17 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"
#include <criterion/criterion.h>

Test(signature, invalid)
{
	t_image	image;

	cr_assert(!decode_png("ressources/signature/invalid.jpg", &image));
}

Test(signature, early_EOF)
{
	t_image	image;

	cr_assert(!decode_png("ressources/signature/early_EOF.png", &image));
}

Test(signature, valid)
{
	t_image	image;

	cr_assert(decode_png("ressources/signature/valid.png", &image));
}
