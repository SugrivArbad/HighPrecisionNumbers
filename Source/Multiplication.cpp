#include "..\Header\Common.hpp"

std::string mult(std::string op1, std::string op2)
{
#ifdef TRACE_L_1
	std::cout << "  mult : op1 = " << op1 << " op2 = " << op2 << std::endl;
#endif TRACE_L_1

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