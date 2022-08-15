/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spcf2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 21:14:28 by user              #+#    #+#             */
/*   Updated: 2022/06/01 21:14:28 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prtf_c(t_flag *conv, va_list *ap)
{
	conv->sign = 1;
	conv->c = (char)va_arg(*ap, int);
	conv->len = 1;
}

void	ft_prtf_percent(t_flag *conv)
{
	conv->spcf = SPCF_C;
	conv->sign = 1;
	conv->c = '%';
	conv->len = 1;
}
