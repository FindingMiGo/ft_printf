#include"ft_printf.h"

static size_t	ft_prtf_adjust(t_flag *conv)
{
	size_t	adjust;

	adjust = conv->len;
	if (conv->accuracy >= 0 && (size_t)conv->accuracy > conv->len)
		adjust = (size_t)conv->accuracy;
	if (conv->flag[FLAG_SPACE] || conv->flag[FLAG_PLUS] || conv->sign == -1)
		adjust += 1;
	if (((conv->spcf == SPCF_LOWX || conv->spcf == SPCF_UPX)
			&& conv->flag[FLAG_HASH] == 1)
		|| conv->spcf == SPCF_P)
		adjust += 2;
	if (conv->accuracy >= 0 && (size_t)conv->accuracy > adjust)
		adjust = (size_t)conv->accuracy;
	return (adjust);
}

ssize_t	ft_prtf_put_field(t_flag *conv)
{
	char	*p;
	char	c;
	size_t	i;
	size_t	len;
	int		adjust;

	if (!conv->field)
		return (0);
	adjust = ft_prtf_adjust(&*conv);
	if (conv->field <= adjust)
		return (0);
	i = 0;
	if (conv->flag[FLAG_ZERO] == 1 && conv->flag[FLAG_MINUS] != 1)
		c = '0';
	else
		c = ' ';
	p = (char *)malloc(sizeof(char) * (conv->field - adjust + 1));
	if (!p)
		return (-1);
	while (i < (size_t)(conv->field - adjust))
		p[i++] = c;
	p[i] = '\0';
	len = ft_putstr_n(p, (size_t)(conv->field - adjust));
	free(p);
	return (len);
}
