#include "..\Header\Common.hpp"

std::string mult(std::string op1, std::string op2)
{
	std::cout << "  mult : op1 = " << op1 << " op2 = " << op2 << std::endl;

	std::string result;

	if (op2 == "01")
	{
		result = op1;
	}
	else
	{
		result = add(op1, mult(op1, sub(op2, "1")));
	}

	return result;
}