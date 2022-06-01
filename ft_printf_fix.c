#include"ft_printf.h"

static void	ft_prtf_fix_hex(t_flag *conv)
{
	if (conv->spcf == SPCF_LOWX || conv->spcf == SPCF_UPX)
	{
		if (conv->sign == 0)
			conv->flag[FLAG_HASH] = 0;
		if (conv->sign == 0 && conv->accuracy == 0)
			conv->len = 0;
		conv->flag[FLAG_PLUS] = 0;
		conv->flag[FLAG_SPACE] = 0;
	}
}

static void	ft_prtf_fix_p(t_flag *conv)
{
	if (conv->spcf == SPCF_P)
	{
		conv->flag[FLAG_PLUS] = 0;
		conv->flag[FLAG_SPACE] = 0;
		if (conv->accuracy == 0 && conv->sign == 0)
			conv->len = 0;
		else if (conv->accuracy >= 0 && (size_t)conv->accuracy <= conv->len
			&& conv->sign != 0)
			conv->accuracy = -1;
	}
}

static void	ft_prtf_fix_s(t_flag *conv)
{
	if (conv->spcf == SPCF_S)
	{
		conv->flag[FLAG_PLUS] = 0;
		conv->flag[FLAG_SPACE] = 0;
		if (!conv->ptr && conv->accuracy >= 0
			&& conv->accuracy < 6 && conv->sign == 0)
			conv->len = conv->accuracy;
		else if (!conv->ptr && conv->accuracy >= 0
			&& conv->accuracy > 6 && conv->sign == 0)
			conv->accuracy = -1;
		if (conv->sign != 0 && conv->accuracy >= 0
			&& (size_t)conv->accuracy > conv->len)
			conv->accuracy = -1;
		else if (conv->accuracy >= 0 && (size_t)conv->accuracy < conv->len)
			conv->len = (size_t)conv->accuracy;
	}
}

static void	ft_prtf_fix_u(t_flag *conv)
{
	if (conv->spcf == SPCF_U)
	{
		conv->flag[FLAG_PLUS] = 0;
		conv->flag[FLAG_SPACE] = 0;
		if (conv->accuracy >= 0
			&& (size_t)conv->accuracy < conv->len && !conv->sign)
			conv->len = 0;
	}
}

void	ft_prtf_fix(t_flag *conv)
{
	if (conv->accuracy >= 0 && conv->spcf != SPCF_C && conv->spcf != SPCF_S)
		conv->flag[FLAG_ZERO] = 0;
	if (conv->spcf == SPCF_C)
	{
		conv->flag[FLAG_PLUS] = 0;
		conv->flag[FLAG_SPACE] = 0;
		conv->accuracy = -1;
	}
	if (conv->spcf == SPCF_D || conv->spcf == SPCF_I)
	{
		if (conv->sign == 0 && conv->accuracy == 0)
			conv->len = 0;
		if (conv->accuracy >= 0)
		{
			if (((size_t)conv->accuracy < conv->len) && (conv->sign != 0))
				conv->accuracy = -1;
		}
	}
	ft_prtf_fix_hex(&*conv);
	ft_prtf_fix_s(&*conv);
	ft_prtf_fix_p(&*conv);
	ft_prtf_fix_u(&*conv);
}
