#include"ft_printf.h"

void	ft_prtf_p(t_flag *conv, va_list *ap)
{
	unsigned long	ul;

	ul = (unsigned long)va_arg(*ap, void *);
	if (ul == 0)
	{
		conv->sign = 0;
		conv->ptr = ft_strdup("0");
		conv->len = 1;
	}
	else
	{
		conv->sign = 1;
		conv->ptr = ft_dectohex(ul, 0);
		if (conv->ptr)
			conv->len = ft_strlen(conv->ptr);
	}
}

void	ft_prtf_x(t_flag *conv, va_list *ap, char x)
{
	unsigned int	ui;

	ui = (unsigned int)va_arg(*ap, unsigned int);
	if (x == 'X')
		conv->ptr = ft_dectohex(ui, 1);
	else
		conv->ptr = ft_dectohex(ui, 0);
	if (ui)
		conv->sign = 1;
	if (conv->ptr)
		conv->len = ft_strlen(conv->ptr);
}

void	ft_prtf_di(t_flag *conv, va_list *ap)
{
	char	*p;
	int		tmp;

	tmp = (int)va_arg(*ap, int);
	if (tmp > 0)
		conv->sign = 1;
	else if (!tmp)
		conv->sign = 0;
	else if (tmp < 0)
		conv->sign = -1;
	p = ft_itoa(tmp);
	if (conv->sign == -1 && p)
		ft_memmove(p, p + 1, ft_strlen(p + 1) + 1);
	conv->ptr = p;
	if (conv->ptr)
		conv->len = ft_strlen(p);
}

void	ft_prtf_s(t_flag *conv, va_list *ap)
{
	char	*s;

	s = (char *)va_arg(*ap, char *);
	if (s)
	{
		conv->sign = 1;
		conv->ptr = ft_strdup(s);
		if (conv->ptr)
			conv->len = ft_strlen(conv->ptr);
	}
	else
	{
		conv->sign = 0;
		conv->ptr = NULL;
		conv->len = 6;
	}
}

void	ft_prtf_u(t_flag *conv, va_list *ap)
{
	unsigned int	num;

	num = (unsigned int)va_arg(*ap, unsigned int);
	if (num)
		conv->sign = 1;
	else
		conv->sign = 0;
	conv->ptr = ft_uitoa(num);
	if (conv->ptr)
		conv->len = ft_strlen(conv->ptr);
}
