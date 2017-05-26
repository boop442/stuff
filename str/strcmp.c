#include <stdio.h>

int strcmp(char* str1, char* str2);
int strcmp2(char* str1, char* str2);

int main()
{
	char* b = "";
	char* a = "ab";
	int res = strcmp2(a, b);
	//if (res == 1) { printf("equal\n"); }
	//if (res == 0) { printf("not equal\n"); }
	printf("%i\n", res);
}

int strcmp(char* str1, char* str2)
{
	do 	
	{
		if (*str1 != *str2)
		{
			return 0;
		}
		else
		{
			str1 += 1;
			str2 += 1;
		}
	} while ((*(str1-1) != '\0') && (*(str1-1) != '\0'));


	return 1;
}



int strcmp2(char* str1, char* str2)
{
	while ((*str1 != '\0') || (*str2 != '\0'))
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		str1 += 1;
		str2 += 1;
	}
	return 0;
}
