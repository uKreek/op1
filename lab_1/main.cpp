#include <iostream>

int main()
{
	 std::cout << "char: 8 bit [-128, 127] or [0, 255]" << '\n' 
		 << "short: 16 bit [-32768, 32767]" << '\n'
		 << "int: 16 or 32 bit [-32768, 32767] or [-2147483648, 2147483647]" << '\n'
		 << "long: 32 or 64 bit [-2147483648, 2147483647] or [-9223372036854775, 9223372036854774]" << '\n'
		 << "bool: True or False" << '\n'
		 << "float: 32 bit [+/- 3.4E-38, 3.4E+38]" << '\n'
		 << "double: 64 bit [+/- 1.7E-308, 1.7E+308]" << '\n' << std::endl;
	 
	 std::cout << "int: 4 + 5 = " << 4+5 << '\n'
		 << "float: 0.2 * 50 = " << 0.2*50 << std::endl;


	return 0;
}