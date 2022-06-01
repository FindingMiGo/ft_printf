#include"ft_printf.h"

static size_t	ft_count_digits_ull(unsigned long long n)
{
	size_t	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

static void	put_num_ull(char *rtn, int n, unsigned long long ln, size_t len)
{
	if (n == 0)
	{
		rtn[0] = '0';
		return ;
	}
	while (len > 0)
	{
		rtn[len - 1] = (char)((ln % 10) + '0');
		ln /= 10;
		len--;
	}
}

char	*ft_uitoa(unsigned int n)
{
	size_t				len;
	char				*rtn;
	unsigned long long	ln;

	ln = (unsigned long long)n;
	len = ft_count_digits_ull(ln);
	rtn = (char *)malloc(sizeof(char) * (len + 1));
	if (!rtn)
		return (NULL);
	put_num_ull(rtn, n, ln, len);
	rtn[len] = '\0';
	return (rtn);
}

static size_t	ft_count_digits_hex(unsigned long ul)
{
	size_t	len;

	len = 0;
	while (ul)
	{
		ul /= 16;
		len++;
	}
	return (len);
}

char	*ft_dectohex(unsigned long ul, int flag)
{
	size_t	i;
	size_t	len;
	char	*hex;
	char	rtn[20];

	if (flag == 1)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	i = 0;
	len = 0;
	if (ul == 0)
		return (ft_strdup("0"));
	len = ft_count_digits_hex(ul);
	while (i < len)
	{
		rtn[len - 1 - i] = hex[ul % 16];
		ul /= 16;
		i++;
	}
	rtn[len] = '\0';
	return (ft_strdup(rtn));
}
