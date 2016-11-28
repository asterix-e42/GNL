
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"
#include <math.h>

int ft_base2base(char *nb, char *b1)
{
char *ret;
int tmp;
size_t size;
int skt;
int max;

if(!b1)
	return(0);
tmp = -1;
skt = 0;
max = strlen(nb) - 1;
size = strlen(b1);
while(*(nb + ++tmp))
{
	ret = b1 - 1;
	while(*(++ret) != *(nb + tmp))
		if(!*(ret))
			return 0;
	skt += (int)(ret - b1) * pow(size, max - tmp);
}

return(skt);
}

int main(void)
{
int i;
i = ft_base2base("1r3", "012r39", "0123");
	printf("%d\n", i);
}

