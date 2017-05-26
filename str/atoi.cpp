#include <iostream>

int atoi(const char* str);

int main(){
	int a = atoi("");
	std::cout << a << std::endl;
}

int atoi(const char* str){
	int result = 0;
		
	while (*str == ' '){
		str += 1;
		continue;
	}

	while ((*str <= '9') && (*str >= '0')){
		int i = (int) (*str - '0');
		result = result*10 + i;
		str += 1;
	}
	return result;
}
