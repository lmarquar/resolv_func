#include "resolv_func.h"

typedef struct s_list
{
	double			diff;
	int				i;
	struct s_list	*next;
	struct s_list	*prev;
}	d_list;

d_list	*create_d_list(double diff)
{
	d_list	*res;

	res = calloc(1, sizeof(d_list));	
	res->diff = diff;
	res->i = 0;
	res->next = NULL;
	res->prev = NULL;
	return (res);
}

int		dir_switch(char *dir)
{
	if (*dir == '-')
		*dir = '+';
	else if (*dir == '+')
		*dir = '-';
	return (0);
}

double 	func(double p)
{
	return ((p * p) - p);
}

int recursive(d_list *d, double p_s[], char dir)
{
	double	newp;

	if (d->i > 100)
		return (1);
	if (dir == '+')
		p_s[0] = p_s[0] + p_s[1];
	else if (dir == '-')
		p_s[0] = p_s[0] - p_s[1];

	newp = func(p_s[0]);
	d->diff = newp - p_s[0];
	if (d->diff < 0)
		d->diff = d->diff * -1;
	d->next = create_d_list(0.0); 
	d->next->prev = d;
	d->next->i = d->i + 1;

	if (d->diff < 0.01)
	{
		ft_putdouble(p_s[0]);
		return (0);
	}
	else if (d->prev == NULL)
		recursive(d->next, p_s, dir);
	else if (d->diff > d->prev->diff)
	{
		dir_switch(&dir);
		p_s[0] = p_s[0] / 2;
		recursive(d->next, p_s, dir); 
	}	
	else if (d->diff < d->prev->diff)  
	{
		p_s[0] = p_s[0] * 2;
		recursive(d->next, p_s, dir); 
	}
	return (0);	
}

int	main()
{
	d_list	*d;
	double	p_s[2];

	d = create_d_list(0.0); 
	p_s[0] = 1;
	p_s[1] = 1;
	if (recursive(d, p_s, '+'))
		return (1);
	else
		return (0);
}
