#include <unistd.h>

typedef struct s_list
{
	double	diff;
	d_list	*next;
	d_list	*prev;
}	d_list;



double 	func(double p)
{
	return ((1 / p) + p);
}

int recursive(d_list *d, double p_s[], char dir, int layer)
{
	double	newp;

	if (layer > 100)
		return (1);

	if (dir == 'x')
		p_s[0] = p_s[0] * p_s[1];
	else if (dir == ':')
		p_s[0] = p_s[0] * p_s[1];

	newp = func(p_s[0]);

	if (res == d)
	{
		sres = ft_dtoa(res);
		write(1, sres, getlen(sres));
		return (0);
	}
	if (res > d)
	{
		recursive(res, p, 1);
	}	
	return (0);	
}

int	main()
{
	d_list	*d;
	double	p_s[2];

	d = calloc(1, sizeof(d_list));
	p_s[0] = 1;
	p_s[1] = 1;
	if (recursive(d, p_s, 'x', 0))
		return (1);
	else
		return (0);
}
