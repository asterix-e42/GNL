
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"
#include <math.h>
#include <stdlib.h>

char *ft_base2base(int nb, char *b2)
{
char *ret;
int tmp;
size_t size;
int skt;
int max;

if(!b2 && !*b2 && !*(b2 + 1))
	return(0);
tmp = nb;
skt = 0;
max = strlen(b2);
size = (nb < max) + 1;
while(tmp /= max)
	++size;
ret = (char *)malloc(sizeof(char) * (size + 1));
printf("%d\n", (int)(size + 1));
*(ret + size) = '\0';
while(--size + 1)
{
	*(ret + size) = *(b2 + (nb % max));

	nb /= max;
}

return(ret);
}

int main(void)
{
char *i;
i = ft_base2base(1237653574, "0123456");
	printf("%s\n", i);
}

