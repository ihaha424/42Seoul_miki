#include <stdio.h>

int	main(void)
{
	int	a;

	a = 3;
	{
		printf("1. %d\n",a);
		int a = 4;
		printf("2. %d\n",a);
	}
	printf("3. %d\n",a);
}
