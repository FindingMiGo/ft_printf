#include"ft_printf.h"

static void	ft_prtf_init_flag(t_flag *s)
{
	int	i;

	i = 0;
	while (i < 5)
		s->flag[i++] = 0;
	s->field = -1;
	s->accuracy = -1;
	s->spcf = -1;
	s->c = '\0';
	s->len = 0;
	s->ptr = NULL;
	s->sign = 0;
}

int	ft_prtf_putstr(const char **start, const char **fmt)
{
	int	n;

	n = 0;
	while (**fmt != '%' && **fmt)
		(*fmt)++;
	n = ft_putstr_n((char *)*start, *fmt - *start);
	return (n);
}

ssize_t	ft_prtf_check_of(int n, int n2)
{
	if (n == -1 || n > INT_MAX - n2)
		return (-1);
	else
		return (n + n2);
}

static int	ft_prtf_parse(const char **fmt, va_list *ap)
{
	t_flag	conv;
	int		n;

	n = 0;
	ft_prtf_init_flag(&conv);
	(*fmt)++;
	if (!**fmt)
		return (-1);
	ft_prtf_checkflag(&conv, &*fmt);
	conv.field = ft_atoi(*fmt);
	while (ft_isdigit(**fmt))
		(*fmt)++;
	ft_prtf_dot(&conv, &*fmt);
	conv.spcf = ft_strchr_n(SPCFS, **fmt);
	if (conv.spcf >= 0 && conv.spcf <= 8)
		ft_prtf_getnum(&conv, &*fmt, &*ap);
	else
		return (-1);
	n = ft_prtf_all_write(&conv);
	return (n);
}

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	const char	*start;
	int			tmp;
	int			n;

	n = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		start = fmt;
		if (*start != '%')
			tmp = ft_prtf_putstr(&start, &fmt);
		else
			tmp = ft_prtf_parse(&fmt, &ap);
		n = ft_prtf_check_of(n, tmp);
	}
	va_end(ap);
	return (n);
}
