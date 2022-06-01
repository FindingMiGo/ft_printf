#include"ft_printf.h"

static ssize_t	ft_prtf_put_s(t_flag *conv)
{
	ssize_t	n;

	n = 0;
	if (conv->sign == 0 && !conv->ptr)
	{
		if (conv->spcf == SPCF_S)
			n = write(1, "(null)", conv->len);
	}
	else
	{
		if (!conv->ptr)
			return (-1);
		n = ft_putstr_n(conv->ptr, conv->len);
	}
	return (n);
}

ssize_t	ft_prtf_put_spcf(t_flag *conv)
{
	ssize_t	n;

	n = 0;
	if (conv->spcf == SPCF_D || conv->spcf == SPCF_I
		|| conv->spcf == SPCF_U || conv->spcf == SPCF_LOWX
		|| conv->spcf == SPCF_UPX)
	{
		if (!conv->ptr)
			return (-1);
		n = ft_prtf_check_of(n, ft_putstr_n(conv->ptr, conv->len));
		return (n);
	}
	if (conv->accuracy == 0)
		return (0);
	else if (conv->spcf == SPCF_S)
		n = ft_prtf_check_of(n, ft_prtf_put_s(&*conv));
	else if (conv->spcf == SPCF_C)
		n = ft_prtf_check_of(n, ft_putstr_n(&conv->c, 1));
	else
	{
		if (!conv->ptr)
			return (-1);
		n = ft_prtf_check_of(n, ft_putstr_n(conv->ptr, conv->len));
	}
	return (n);
}

ssize_t	ft_prtf_put_sign(t_flag *conv)
{
	size_t	n;

	n = 0;
	if (conv->sign == -1)
		n = write(1, "-", 1);
	else if (conv->flag[FLAG_PLUS] == 1)
		n = write(1, "+", 1);
	else if (conv->flag[FLAG_SPACE] == 1)
		n = write(1, " ", 1);
	return (n);
}

ssize_t	ft_prtf_put_zerox(t_flag *conv)
{
	ssize_t	n;

	n = 0;
	if (conv->flag[FLAG_HASH] == 1 || conv->spcf == SPCF_P)
	{
		if (conv->spcf == SPCF_LOWX || conv->spcf == SPCF_P)
			n = write(1, "0x", 2);
		else if (conv->spcf == SPCF_UPX)
			n = write(1, "0X", 2);
	}
	return (n);
}

ssize_t	ft_prtf_put_accuracy(t_flag *conv)
{
	char	*p;
	size_t	i;
	ssize_t	n;

	i = 0;
	if (conv->ptr)
	{
		if (!conv->ptr[0])
			return (0);
	}
	if (conv->accuracy == -1 || (size_t)conv->accuracy < conv->len)
		return (0);
	p = (char *)malloc(sizeof(char) * ((size_t)conv->accuracy - conv->len + 1));
	if (!p)
		return (-1);
	while (i < (size_t)conv->accuracy - conv->len)
		p[i++] = '0';
	p[i] = '\0';
	n = ft_putstr_n(p, ((size_t)conv->accuracy - conv->len));
	free(p);
	return (n);
}
