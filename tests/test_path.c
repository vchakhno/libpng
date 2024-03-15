/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchakhno <vchakhno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 01:05:15 by vchakhno          #+#    #+#             */
/*   Updated: 2024/03/15 02:22:00 by vchakhno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"
#include <criterion/criterion.h>

Test(path, doesnt_exit)
{
	t_image	image;

	cr_assert(!decode_png("ressources/path/doesnt_exist.png", &image));
}

Test(path, valid)
{
	t_image	image;

	cr_assert(decode_png("ressources/path/valid.png", &image));
}
