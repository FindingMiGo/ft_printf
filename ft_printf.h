#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

# define SPCFS "cspdiuxX%"
# define SPCF_C 0
# define SPCF_S 1
# define SPCF_P 2
# define SPCF_D 3
# define SPCF_I 4
# define SPCF_U 5
# define SPCF_LOWX 6
# define SPCF_UPX 7

# define FLAGS "#0+ -"
# define FLAG_HASH 0
# define FLAG_ZERO 1
# define FLAG_PLUS 2
# define FLAG_SPACE 3
# define FLAG_MINUS 4

typedef struct s_flag
{
	int		flag[5];
	int		field;
	int		accuracy;
	int		spcf;
	char	c;
	size_t	len;
	int		sign;
	char	*ptr;
}					t_flag;

int		ft_printf(const char *fmt, ...);
void	ft_prtf_checkflag(t_flag *conv, const char **fmt);
void	ft_prtf_getnum(t_flag *conv, const char **fmt, va_list *ap);
void	ft_prtf_dot(t_flag *conv, const char **fmt);
ssize_t	ft_prtf_all_write(t_flag *conv);
ssize_t	ft_prtf_check_of(int n, int tmp);
ssize_t	ft_prtf_put_zerox(t_flag *conv);
ssize_t	ft_prtf_put_sign(t_flag *conv);
ssize_t	ft_prtf_put_field(t_flag *conv);
ssize_t	ft_prtf_put_spcf(t_flag *conv);
ssize_t	ft_prtf_put_accuracy(t_flag *conv);
void	ft_prtf_di(t_flag *conv, va_list *ap);
void	ft_prtf_s(t_flag *conv, va_list *ap);
void	ft_prtf_p(t_flag *conv, va_list *ap);
void	ft_prtf_x(t_flag *conv, va_list *ap, char x);
void	ft_prtf_u(t_flag *conv, va_list *ap);
void	ft_prtf_c(t_flag *conv, va_list *ap);
void	ft_prtf_percent(t_flag *conv);
void	ft_prtf_fix(t_flag *conv);
char	*ft_dectohex(unsigned long ul, int flag);
char	*ft_uitoa(unsigned int n);
#endif
