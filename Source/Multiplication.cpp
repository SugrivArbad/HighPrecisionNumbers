#include "..\Header\Common.hpp"
#include "..\Header\PrimitiveOperations.hpp"

/*************************************************************************************************/


std::string mult1(char digOp1, std::string op2, char carry);
std::string mult2(std::string result, char digOp1, std::string op2);

std::string multChar1(std::string op1, std::string op2)
{
#ifdef TRACE_L_1
	std::cout << "          multChar1 : op1 = " << op1 << " op2 = " << op2 << std::endl;
#endif // TRACE_L_1

	std::string result;

	if (op2 == "1")
	{
		result = op1;
	}
	else
	{
		result = addition(op1, multChar1(op1, subtraction(op2, "1")));
	}

#ifdef TRACE_L_1
	std::cout << "          multChar1 : op1 = " << op1 << " op2 = " << op2 << " result = " << result << std::endl;
#endif // TRACE_L_1

	return result;
}

std::string multChar(char c1, char c2)
{
	std::string result = "";

	if (c1 == '0' || c2 == '0')
	{
		result = "0";
	}
	else
	{
		result = multChar1(charToString(c1), charToString(c2));
	}

	return result;
}

std::string mult1(char digOp1, std::string op2, char carry)
{
#ifdef TRACE_L_1
	std::cout << "        S - 1 mult1 : digOp1 = " << digOp1 << " op2 = " << op2 << " op2.size() = " << op2.size() << std::endl;
#endif // TRACE_L_1

	std::string result = "";

	if (op2.size() == 1)
	{
		result = addition(multChar(digOp1, op2[0]), charToString(carry));
	}
	else
	{
		char d2 = op2[0];
		op2.erase(op2.begin());

#ifdef TRACE_L_1
	std::cout << "        S - 2 mult1 : digOp1 = " << digOp1 << " d2 = " << d2 << " carry = " << carry << std::endl;
#endif // TRACE_L_1

		std::string addOfFirstDigToTerm = addition(multChar(digOp1, d2), charToString(carry));

#ifdef TRACE_L_1
	std::cout << "        S - 3 mult1 : digOp1 = " << digOp1 << " d2 = " << d2 << " carry = " << carry << " addOfFirstDigToTerm = " << addOfFirstDigToTerm << std::endl;
#endif // TRACE_L_1

		result = mult2(addOfFirstDigToTerm, digOp1, op2);
	}

#ifdef TRACE_L_1
	std::cout << "        S - 4 mult1 : digOp1 = " << digOp1 << " op2 = " << op2 << " result = " << result << std::endl;
#endif // TRACE_L_1

	return result;
}

std::string mult2(std::string multOf2Dig, char digOp1, std::string op2)
{
	std::string result = "";

	if (multOf2Dig.size() == 1)
		result = mult1(digOp1, op2, '0') + multOf2Dig[0];
	else
		result = mult1(digOp1, op2, multOf2Dig[0]) + multOf2Dig[1];

	return result;
}

std::string mult(std::string op1, std::string op2, std::string appendPlace)
{
#ifdef TRACE_L_1
	std::cout << " S-1 mult : op1 = " << op1 << " op2 = " << op2 << "  op1.size() = " << op1.size() << std::endl;
#endif // TRACE_L_1

	std::string result = "";
	char d1 = ' ';

	if (op1.size() == 1)
	{
		d1 = op1[0];
		result = mult1(d1, op2, '0') + appendPlace;
	}
	else
	{
		d1 = op1[0];
		op1.erase(op1.begin());
		
		std::string multCharToTerm = mult1(d1, op2, '0') + appendPlace;

#ifdef TRACE_L_1
	std::cout << " S-2 mult : " << d1 << " * " << op2 << " = " << multCharToTerm << std::endl;
#endif // TRACE_L_1

		result = addition(multCharToTerm, mult(op1, op2, appendPlace + "0"));
	}

#ifdef TRACE_L_1
	std::cout << " S-3 mult : d1 = " << d1 << " op2 = " << op2 << " result = " << result << std::endl;
#endif // TRACE_L_1

	return result;
}

std::string multiplication2(std::string op1, std::string op2)
{
	return mult(rev(op1), rev(op2), "");
}

std::string multiplication1(std::string op1, std::string op2)
{
	std::string result;

	if (op1.empty() && op2.empty())
	{
		result = "";
	}
	else if (op1.empty() && !op2.empty())
	{
		result = op2;
	}
	else if (!op1.empty() && op2.empty())
	{
		result = op1;
	}
	else // if (!op1.empty() && !op2.empty())
	{
		char d1 = op1[0];
		char d2 = op2[0];

		if (d1 == '-' && d2 == '-')
		{
			op1.erase(op1.begin());
			op2.erase(op2.begin());

			result = multiplication2(op1, op2);
		}
		else if (d1 == '-' && d2 == '+')
		{
			op1.erase(op1.begin());
			op2.erase(op2.begin());

			result = NEGATIVE + multiplication2(op1, op2);
		}
		else if (d1 == '-' && d2 != '+')
		{
			op1.erase(op1.begin());

			result = NEGATIVE + multiplication2(op1, op2);
		}
		else if (d1 == '+' && d2 == '-')
		{
			op1.erase(op1.begin());
			op2.erase(op2.begin());

			result = NEGATIVE + multiplication2(op1, op2);
		}
		else if (d1 != '+' && d2 == '-')
		{
			op2.erase(op2.begin());

			result = NEGATIVE + multiplication2(op1, op2);
		}
		else if (d1 == '+' && d2 == '+')
		{
			op1.erase(op1.begin());
			op2.erase(op2.begin());

			result = multiplication2(op1, op2);
		}
		else if (d1 == '+' && d2 != '+')
		{
			op1.erase(op1.begin());

			result = multiplication2(op1, op2);
		}
		else if (d1 != '+' && d2 == '+')
		{
			op2.erase(op2.begin());

			result = multiplication2(op1, op2);
		}
		else if (d1 != '+' && d2 != '+')
		{
			result = multiplication2(op1, op2);
		}
	}

	return result;
}

std::string multiplication(std::string op1, std::string op2)
{
	return remZ(multiplication1(op1, op2));
}

