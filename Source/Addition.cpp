#include "..\Header\Common.hpp"
#include <map>

/***************************************************\
|*** COMMON FUNCTIONS START ************************|
\***************************************************/

std::string charToString(char c)
{
	return std::string(1, c);
}

std::string next(char c)
{
	std::string result;
	result[0] = '0';

	switch (c)
	{
	case '0':
		result[1] = '1';
		break;

	case '1':
		result[1] = '2';
		break;

	case '2':
		result[1] = '3';
		break;

	case '3':
		result[1] = '4';
		break;

	case '4':
		result[1] = '5';
		break;

	case '5':
		result[1] = '6';
		break;

	case '6':
		result[1] = '7';
		break;

	case '7':
		result[1] = '8';
		break;

	case '8':
		result[1] = '9';
		break;

	case '9':
		result[0] = '1';
		result[1] = '0';
		break;

	default:
		result = '?';
		std::cerr << "ERROR : next() : WRONG INPUT \'" << c << "\' SO RETURNING" << std::endl;
	}

	return result;
}

char prev(char c)
{
	char result = '0';

	switch (c)
	{
	case '0': // this special case used for subtraction
		// std::cerr << "ERROR : NO Prev('0') exists" << std::endl;
		result = 'N';
		break;

	case '1':
		result = '0';
		break;

	case '2':
		result = '1';
		break;

	case '3':
		result = '2';
		break;

	case '4':
		result = '3';
		break;

	case '5':
		result = '4';
		break;

	case '6':
		result = '5';
		break;

	case '7':
		result = '6';
		break;

	case '8':
		result = '7';
		break;

	case '9':
		result = '8';
		break;

	case 'T':
		result = '9';
		break;

	default :
		result = '?';
		std::cerr << "ERROR : prev() : WRONG INPUT \'" << c << "\' SO RETURNING" << std::endl;
	}

	return result;
}

std::string rev(std::string str)
{
	std::reverse(str.begin(), str.end());
	return str;
}

std::string remZ(std::string opZ)
{
	try
	{
#ifdef TRACE_L_1
		std::cout << " remZ 1 : opZ = " << opZ << std::endl;
#endif // TRACE_L_1

		if (opZ.empty())
		{
			throw std::runtime_error("result is empty");
		}

		std::string sign = "";
		if (opZ[0] == '+' || opZ[0] == '-')
		{
			sign = opZ[0];
			opZ.erase(opZ.begin());
		}

#ifdef TRACE_L_1
		std::cout << " remZ 2 : opZ = " << opZ << std::endl;
#endif // TRACE_L_1

		while (!opZ.empty() && opZ[0] == '0')
			opZ.erase(opZ.begin());

#ifdef TRACE_L_1
		std::cout << " remZ 3 : opZ = " << opZ << std::endl;
#endif // TRACE_L_1

		if (opZ == "")
			opZ = "0";
		else
			opZ = sign + opZ;

#ifdef TRACE_L_1
		std::cout << " remZ 4 : opZ = " << opZ << std::endl;
#endif // TRACE_L_1
	}
	catch (std::exception& ex)
	{
		std::cout << "EXCEPTION : remZ : Addition.cpp : " << ex.what() << std::endl;
	}

	return opZ;
}

std::string addDigit(char c1, char c2, char carryForward)
{
	std::string carryBase = "00";

#ifdef TRACE_L_1
	std::cout << "	addDigit : c1 = " << c1 << " c2 = " << c2 << " carryForward = " << carryForward << std::endl;
#endif // TRACE_L_1

	if (c2 == '0')
	{
		carryBase[1] = c1;
		carryBase[0] = carryForward;

#ifdef TRACE_L_1
		std::cout << "	     addDigit : cond1 : c1 = " << c1 << " c2 = " << c2 << " carryForward = " << carryForward << " carryBase = " << carryBase[0] << carryBase[1] << std::endl;
#endif // TRACE_L_1
	}
	else
	{
		carryBase = next(c1);
		carryForward = (carryForward != '1') ? carryBase[0] : carryForward;

		c1 = carryBase[1];
		c2 = prev(c2);

#ifdef TRACE_L_1
		std::cout << "	     addDigit : cond2 :  c1 = " << c1 << " c2 = " << c2 << " carryForward = " << carryForward << " carryBase = " << carryBase[0] << carryBase[1] << std::endl;
#endif // TRACE_L_1

		carryBase = addDigit(c1, c2, carryForward);
	}

	return carryBase;
}

// Digit comparison start
bool isGreaterThan0(char digit)
{
	bool isGreater = false;

	switch (digit)
	{
	case '0':
		isGreater = false;
		break;

	case '1':
		isGreater = false;
		break;

	case '2':
		isGreater = false;
		break;

	case '3':
		isGreater = false;
		break;

	case '4':
		isGreater = false;
		break;

	case '5':
		isGreater = false;
		break;

	case '6':
		isGreater = false;
		break;

	case '7':
		isGreater = false;
		break;

	case '8':
		isGreater = false;
		break;

	case '9':
		isGreater = false;
		break;
	}

	return isGreater;
}

bool isGreaterThan1(char digit)
{
	bool isGreater = false;

	switch (digit)
	{
	case '0':
		isGreater = true;
		break;

	case '1':
		isGreater = false;
		break;

	case '2':
		isGreater = false;
		break;

	case '3':
		isGreater = false;
		break;

	case '4':
		isGreater = false;
		break;

	case '5':
		isGreater = false;
		break;

	case '6':
		isGreater = false;
		break;

	case '7':
		isGreater = false;
		break;

	case '8':
		isGreater = false;
		break;

	case '9':
		isGreater = false;
		break;
	}

	return isGreater;
}

bool isGreaterThan2(char digit)
{
	bool isGreater = false;

	switch (digit)
	{
	case '0':
		isGreater = true;
		break;

	case '1':
		isGreater = true;
		break;

	case '2':
		isGreater = false;
		break;

	case '3':
		isGreater = false;
		break;

	case '4':
		isGreater = false;
		break;

	case '5':
		isGreater = false;
		break;

	case '6':
		isGreater = false;
		break;

	case '7':
		isGreater = false;
		break;

	case '8':
		isGreater = false;
		break;

	case '9':
		isGreater = false;
		break;
	}

	return isGreater;
}

bool isGreaterThan3(char digit)
{
	bool isGreater = false;

	switch (digit)
	{
	case '0':
		isGreater = true;
		break;

	case '1':
		isGreater = true;
		break;

	case '2':
		isGreater = true;
		break;

	case '3':
		isGreater = false;
		break;

	case '4':
		isGreater = false;
		break;

	case '5':
		isGreater = false;
		break;

	case '6':
		isGreater = false;
		break;

	case '7':
		isGreater = false;
		break;

	case '8':
		isGreater = false;
		break;

	case '9':
		isGreater = false;
		break;
	}

	return isGreater;
}

bool isGreaterThan4(char digit)
{
	bool isGreater = false;

	switch (digit)
	{
	case '0':
		isGreater = true;
		break;

	case '1':
		isGreater = true;
		break;

	case '2':
		isGreater = true;
		break;

	case '3':
		isGreater = true;
		break;

	case '4':
		isGreater = false;
		break;

	case '5':
		isGreater = false;
		break;

	case '6':
		isGreater = false;
		break;

	case '7':
		isGreater = false;
		break;

	case '8':
		isGreater = false;
		break;

	case '9':
		isGreater = false;
		break;
	}

	return isGreater;
}

bool isGreaterThan5(char digit)
{
	bool isGreater = false;

	switch (digit)
	{
	case '0':
		isGreater = true;
		break;

	case '1':
		isGreater = true;
		break;

	case '2':
		isGreater = true;
		break;

	case '3':
		isGreater = true;
		break;

	case '4':
		isGreater = true;
		break;

	case '5':
		isGreater = false;
		break;

	case '6':
		isGreater = false;
		break;

	case '7':
		isGreater = false;
		break;

	case '8':
		isGreater = false;
		break;

	case '9':
		isGreater = false;
		break;
	}

	return isGreater;
}

bool isGreaterThan6(char digit)
{
	bool isGreater = false;

	switch (digit)
	{
	case '0':
		isGreater = true;
		break;

	case '1':
		isGreater = true;
		break;

	case '2':
		isGreater = true;
		break;

	case '3':
		isGreater = true;
		break;

	case '4':
		isGreater = true;
		break;

	case '5':
		isGreater = true;
		break;

	case '6':
		isGreater = false;
		break;

	case '7':
		isGreater = false;
		break;

	case '8':
		isGreater = false;
		break;

	case '9':
		isGreater = false;
		break;
	}

	return isGreater;
}

bool isGreaterThan7(char digit)
{
	bool isGreater = false;

	switch (digit)
	{
	case '0':
		isGreater = true;
		break;

	case '1':
		isGreater = true;
		break;

	case '2':
		isGreater = true;
		break;

	case '3':
		isGreater = true;
		break;

	case '4':
		isGreater = true;
		break;

	case '5':
		isGreater = true;
		break;

	case '6':
		isGreater = true;
		break;

	case '7':
		isGreater = false;
		break;

	case '8':
		isGreater = false;
		break;

	case '9':
		isGreater = false;
		break;
	}

	return isGreater;
}

bool isGreaterThan8(char digit)
{
	bool isGreater = false;

	switch (digit)
	{
	case '0':
		isGreater = true;
		break;

	case '1':
		isGreater = true;
		break;

	case '2':
		isGreater = true;
		break;

	case '3':
		isGreater = true;
		break;

	case '4':
		isGreater = true;
		break;

	case '5':
		isGreater = true;
		break;

	case '6':
		isGreater = true;
		break;

	case '7':
		isGreater = true;
		break;

	case '8':
		isGreater = false;
		break;

	case '9':
		isGreater = false;
		break;
	}

	return isGreater;
}

bool isGreaterThan9(char digit)
{
	bool isGreater = false;

	switch (digit)
	{
	case '0':
		isGreater = true;
		break;

	case '1':
		isGreater = true;
		break;

	case '2':
		isGreater = true;
		break;

	case '3':
		isGreater = true;
		break;

	case '4':
		isGreater = true;
		break;

	case '5':
		isGreater = true;
		break;

	case '6':
		isGreater = true;
		break;

	case '7':
		isGreater = true;
		break;

	case '8':
		isGreater = true;
		break;

	case '9':
		isGreater = false;
		break;
	}

	return isGreater;
}

bool isGreaterDigit(char d1, char d2)
{
	bool isGreater = false;

	switch (d1)
	{
	case '0':
		isGreater = isGreaterThan0(d2);
		break;

	case '1':
		isGreater = isGreaterThan1(d2);
		break;

	case '2':
		isGreater = isGreaterThan2(d2);
		break;

	case '3':
		isGreater = isGreaterThan3(d2);
		break;

	case '4':
		isGreater = isGreaterThan4(d2);
		break;

	case '5':
		isGreater = isGreaterThan5(d2);
		break;

	case '6':
		isGreater = isGreaterThan6(d2);
		break;

	case '7':
		isGreater = isGreaterThan7(d2);
		break;

	case '8':
		isGreater = isGreaterThan8(d2);
		break;

	case '9':
		isGreater = isGreaterThan9(d2);
		break;
	}

	return isGreater;
}

bool isGreaterThan(std::string op1, std::string op2)
{
	bool isGreater = false;

	if (op1.length() > op2.length())
	{
		isGreater = true;
	}
	else if (op1.length() < op2.length())
	{
		isGreater = false;
	}
	else // if (op1.length() == op2.length())
	{
		if (op1.empty() && op2.empty())
		{
			isGreater = false;
		}
		else
		{
			char d1 = op1[0];
			char d2 = op2[0];

			if (isGreaterDigit(d1, d2))
			{
				isGreater = true;
			}
			else
			{
				if (isGreaterDigit(d2, d1))
				{
					isGreater = false;
				}
				else
				{
					op1.erase(op1.begin());
					op2.erase(op2.begin());

					isGreater = isGreaterThan(op1, op2);
				}
			}
		}
	}

	return isGreater;
}

/***************************************************\
|*** COMMON FUNCTIONS END **************************|
\***************************************************/





/***************************************************\
|*** ADDITION START ********************************|
\***************************************************/

std::string addRem(std::string op, char carry)
{
	std::string result = "";
	std::string carryBase = "00";
	char dig = op[0];

	if (carry == '1')
	{
		carryBase = next(dig);
		op.erase(op.begin());

		result = charToString(carryBase[1]);
		if (op.empty())
			result += carryBase[0];
		else
			result += addRem(op, carryBase[0]);
	}
	else
	{
		result = op;
	}

	return result;
}

std::string add1(std::string op1, std::string op2, char carry)
{
	std::string carryBase = "00";
	std::string result;

#ifdef TRACE_L_1
	std::cout << " add1 : op1 = " << op1 << " op2 = " << op2 << " carry = " << carry << " op1.empty() = " << op1.empty() << " op2.empty() = " << op2.empty() << std::endl;
#endif // TRACE_L_1

	if (op1.empty() && op2.empty())
	{
		result = charToString(carry);
	}
	else if (op1.empty() && !op2.empty())
	{
		result = addRem(op2, carry);
	}
	else if (!op1.empty() && op2.empty())
	{
		result = addRem(op1, carry);
	}
	else // if (!op1.empty() && !op2.empty())
	{
		char d1 = op1[0];
		char d2 = op2[0];

		op1.erase(op1.begin());
		op2.erase(op2.begin());

		char newCarry = carry;

		if (carry == '1')
		{
			carryBase = next(d1);
			newCarry = carryBase[0];
			d1 = carryBase[1];
		}

#ifdef TRACE_L_1
		std::cout << " add1 : cond4" << std::endl;
#endif // TRACE_L_1

		carryBase = addDigit(d1, d2, newCarry);

		carryBase[0] = (newCarry == '1' || carryBase[0] == '1') ? '1' : '0';

		result = charToString(carryBase[1]) + add1(op1, op2, carryBase[0]);
	}

	return result;
}

std::string add(std::string op1, std::string op2)
{
	std::string addition = rev(add1(rev(op1), rev(op2), '0'));

#ifdef TRACE_L_1
	std::cout << "   add : addition = " << addition << std::endl;
#endif // TRACE_L_1

	return addition;
}

// assumption : before passing to this function : (op1 < 0 xor op2 < 0) -> ((op1 > 0 && op2 < 0) || (op1 < 0 && op2 > 0)) 
// means op1 is negative xor op2 is negative implies both at a time cannot be negative or positive
// means 3rd parameter isFirstNegative = [true implies op1 < 0 and false implies op2 < 0]
// here op1 and op2 are scalar values means no positive/negative i.e it is externally indicated by 3rd paramter
// subDecision : helper function for +ve/-ve numbers
std::string subDecision(std::string op1, std::string op2, bool isFirstNegative)
{
	std::string result;

	// before passing to this function
	// if (|op1| >  |op2| && op1 < 0) = -sub(op1, op2)
	// if (|op1| >  |op2| && op2 < 0) = +sub(op1, op2)
	// if (|op1| <= |op2| && op1 < 0) = +sub(op2, op1)
	// if (|op1| <= |op2| && op2 < 0) = -sub(op2, op1)

	if (isGreaterThan(op1, op2))
	{
		result = (isFirstNegative ? NEGATIVE : "") + sub(op1, op2);
	}
	else
	{
		result = (isFirstNegative ? "" : NEGATIVE) + sub(op2, op1);
	}

	return result;
}

std::string addition1(std::string op1, std::string op2)
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

			result = NEGATIVE + add(op1, op2);
		}
		else if (d1 == '-' && d2 == '+')
		{
			op1.erase(op1.begin());
			op2.erase(op2.begin());

			// here 3rd parameter true means op1 is negative
			result = subDecision(op1, op2, true);
		}
		else if (d1 == '-' && d2 != '+')
		{
			op1.erase(op1.begin());

			// here 3rd parameter true means op1 is negative
			result = subDecision(op1, op2, true);
		}
		else if (d1 == '+' && d2 == '-')
		{
			op1.erase(op1.begin());
			op2.erase(op2.begin());

			// here 3rd paramater false menas op2 is negative
			result = subDecision(op1, op2, false);
		}
		else if (d1 != '+' && d2 == '-')
		{
			op2.erase(op2.begin());

			// here 3rd parameter false means op2 is negative
			result = subDecision(op1, op2, false);
		}
		else if (d1 == '+' && d2 == '+')
		{
			op1.erase(op1.begin());
			op2.erase(op2.begin());

			result = add(op1, op2);
		}
		else if (d1 == '+' && d2 != '+')
		{
			op1.erase(op1.begin());

			result = add(op1, op2);
		}
		else if (d1 != '+' && d2 == '+')
		{
			op2.erase(op2.begin());

			result = add(op1, op2);
		}
		else if (d1 != '+' && d2 != '+')
		{
			result = add(op1, op2);
		}
	}

	return result;
}

std::string addition(std::string op1, std::string op2)
{
	return remZ(addition1(op1, op2));
}


void displayOperation(std::string op1, std::string op2, std::string result, char oper)
{
	size_t op1Size = op1.size();
	size_t op2Size = op2.size();
	static int opCnt = 1;

	std::map<char, std::string> mapOperatorName = {
		{'+', "ADDTION"},
		{'-', "SUBTRACITON"},
		{'*', "MULTIPLICATION"},
		{'/', "DIVISION"}
	};

	std::cout << std::endl << "*************** " << opCnt << "] " << mapOperatorName[oper] << " START *********************************************************************************" << std::endl << std::endl << std::endl;

	long long int diff = op2Size - op1Size;
	if (diff > 0)
	{
		for (long long int ind = 0; ind < diff; ind++)
			std::cout << " ";
	}

	std::cout << "        " << op1 << std::endl;
	std::cout << "    " << oper << "   ";

	if (diff < 0)
	{
		for (long long int ind = 0; ind < -diff; ind++)
			std::cout << " ";
	}

	std::cout << op2 << std::endl;

	std::cout << "   _____" << "_____";

	diff = (diff > 0) ? op2Size : op1Size;

	for (long long int ind = 0; ind < diff; ind++)
		std::cout << "_";

	std::cout << std::endl << std::endl << "        " << result << std::endl;
	std::cout << std::endl << "*************** " << opCnt << "] " << mapOperatorName[oper] << " END **********************************************************************************" <<  std::endl << std::endl << std::endl << std::endl;

	opCnt++;
}

/***************************************************\
|*** ADDITION END **********************************|
\***************************************************/
