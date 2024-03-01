/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_decoder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 01:05:15 by vchakhno          #+#    #+#             */
/*   Updated: 2024/03/01 02:19:22 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"
#include <criterion/criterion.h>

Test(decoder, valid_signature)
{
	cr_expect(decode_png("ressources/panoramic.png"),
		"This should be recognized as a PNG file");
}

Test(decoder, invalid_signature)
{
	cr_expect(!decode_png("ressources/panoramic.jpg"),
		"This should not be recognized as a PNG file");
}
