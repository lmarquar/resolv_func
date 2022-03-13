#include <unistd.h>

int ft_putlong(long d)
{
	char	c;

	if (d < 0)
	{
		d = d * -1;
		write(1, "-", 1);
	}
	if (d <= 9)
	{
		c = d + '0';
		write(1, &c, 1);	
	}
	else
	{
		c = (d % 10) + '0';
		ft_putlong(d / 10);
		write(1, &c, 1);
	}
	return (1);
}

#include <stdio.h>

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
	d = d - (double) ld;
	i = 0;
	printf("%lf", d);
	ld = (long) d;
	while (((double)ld - d) != 0.0)
	{
		printf("\n%d:\t%lf\n\t%lf\n", i, d, (double)ld);
		printf("%lf", ((double)ld - d));
		d = d * 10.0;
		ld = (long) d;
		i++;
	}
	printf("\n%ld\n", ld);
	if (i == 0)
		return (0);
	write(1, ".", 1);
	ft_putlong(ld);
	return (0);
}

int main()
{
	ft_putdouble(42.42);
	return (0);
}

