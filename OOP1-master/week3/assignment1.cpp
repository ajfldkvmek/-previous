#include <iostream>

int *add(int x){
	
	int* res;
		
	return res;
}

int main() {

	
	int *code;//code
	const char *rodata = "asdaa";
	int var1;//bss
	int var2 = 10;//data
	int *alloc = new int[2];
	alloc[0] = 123;//heap
	int *temp = add(10);	
	std::cout << "code area: " << &code << std::endl;
	std::cout << "rodata area: " << &rodata << std::endl;
	std::cout << "data area: " << &var2 << std::endl;
	std::cout << "bss area : " << &var1 << std::endl;
	std::cout << "heap area: " << &alloc  <<std::endl;
	std::cout << "stack area: :" << &temp  << std::endl;
}
