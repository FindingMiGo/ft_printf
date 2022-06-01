#include"ft_printf.h"

void	ft_prtf_checkflag(t_flag *conv, const char **fmt)
{
	int		idx;
	char	*flg;

	flg = FLAGS;
	idx = ft_strchr_n(flg, **fmt);
	while (idx >= 0)
	{
		conv->flag[idx] = 1;
		(*fmt)++;
		if (!**fmt)
			break ;
		idx = ft_strchr_n(flg, **fmt);
	}
}

void	ft_prtf_getnum(t_flag	*conv,	const char **fmt, va_list *ap)
{
	if (conv->spcf == SPCF_D || conv->spcf == SPCF_I)
		ft_prtf_di(&*conv, &*ap);
	else if (conv->spcf == SPCF_P)
		ft_prtf_p(&*conv, &*ap);
	else if (conv->spcf == SPCF_LOWX || conv->spcf == SPCF_UPX)
		ft_prtf_x(&*conv, &*ap, **fmt);
	else if (conv->spcf == SPCF_U)
		ft_prtf_u(&*conv, &*ap);
	else if (conv->spcf == SPCF_C)
		ft_prtf_c(&*conv, &*ap);
	else if (conv->spcf == SPCF_S)
		ft_prtf_s(&*conv, &*ap);
	else if (**fmt == '%')
		ft_prtf_percent(&*conv);
	else if (**fmt == '\0')
		return ;
	(*fmt)++;
	return ;
}

static ssize_t	ft_printf_left_write(t_flag *conv)
{
	ssize_t	n;

	n = ft_prtf_put_sign(&*conv);
	n = ft_prtf_check_of(n, ft_prtf_put_zerox(&*conv));
	n = ft_prtf_check_of(n, ft_prtf_put_accuracy(&*conv));
	n = ft_prtf_check_of(n, ft_prtf_put_spcf(&*conv));
	free(conv->ptr);
	conv->ptr = NULL;
	n = ft_prtf_check_of(n, ft_prtf_put_field(&*conv));
	return (n);
}

ssize_t	ft_prtf_all_write(t_flag *conv)
{
	ssize_t	n;
	int		acc_on;

	acc_on = 0;
	ft_prtf_fix(&*conv);
	if (conv->field >= conv->accuracy && conv->accuracy > 0)
		acc_on = 1;
	n = 0;
	if (conv->flag[FLAG_MINUS] == 1)
		n = ft_printf_left_write(&*conv);
	else
	{
		if (!(acc_on == 0 && conv->flag[FLAG_ZERO] == 1))
			n = ft_prtf_check_of(n, ft_prtf_put_field(&*conv));
		n = ft_prtf_check_of(n, ft_prtf_put_sign(&*conv));
		n = ft_prtf_check_of(n, ft_prtf_put_zerox(&*conv));
		if (acc_on == 0 && conv->flag[FLAG_ZERO] == 1)
			n = ft_prtf_check_of(n, ft_prtf_put_field(&*conv));
		n = ft_prtf_check_of(n, ft_prtf_put_accuracy(&*conv));
		n = ft_prtf_check_of(n, ft_prtf_put_spcf(&*conv));
	}
	free(conv->ptr);
	return (n);
}

void	ft_prtf_dot(t_flag *conv, const char **fmt)
{
	if (**fmt == '.')
	{
		(*fmt)++;
		conv->accuracy = ft_atoi(*fmt);
		while (ft_isdigit(**fmt) && **fmt != 0)
			(*fmt)++;
	}
}
