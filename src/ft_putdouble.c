#include <unistd.h>

//not error prone, if values of double overstep limits

static int ft_putlong(long ld)
{
	char	c;

	if (ld < 0)
	{
		ld = ld * -1;
		write(1, "-", 1);
	}
	if (ld <= 9)
	{
		c = ld + '0';
		write(1, &c, 1);	
	}
	else
	{
		c = (ld % (long)10) + '0';
		ft_putlong(ld / 10);
		write(1, &c, 1);
	}
	return (1);
}

int	ft_putdouble(double d)
{
	long	ld;
	int		i;

	if (d < 0)
	{
		d = d * -1;
		write(1, "-", 1);
	}
	ld = (long) d;
	ft_putlong(ld);
	i = 0;
	ld = (long) d;
	d = d - (double) ld;
	ld = (long) d;
	d = d * ((double)(1e15));
	ld = ld * ((long)(1e15));
	if ((long)d == 0)
		return (0);
	write(1, ".", 1);
	ft_putlong((long)d);
	return (0);
}
