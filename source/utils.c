#include <utils.h>

unsigned int strlen(char* str)
{
	unsigned int len = 0;
	while(true)
	{
		if(str[len] == '\0')
		{
			break;
		}
		len++;
	}
	return len;
}