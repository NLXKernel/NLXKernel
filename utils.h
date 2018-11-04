#ifndef UTILS_H
#define UTILS_H

#define true 1
#define false 0

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

#endif