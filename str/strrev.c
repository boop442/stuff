#include <stdio.h>
#include <stdlib.h>

char* strrev(char* str);

int main(){
	char* str = "huy";

	char* rts = strrev(str);
	while (*rts != '\0'){
		printf("%c", *rts);
		rts += 1;
	}
}

char* strrev(char* str){
	int counter = 0;
	while (*str != '\0'){
		counter++;
		str++;
	}
	counter--;
	str--;
	char* result;
	result = malloc(100 * sizeof(char));
	char* ptr = result;
	while(counter >= 0){
		*result = *str;
		result++;
		counter--;
		str--;
	}
	*result = '\0';
	return ptr;
}
