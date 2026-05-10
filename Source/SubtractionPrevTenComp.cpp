#include "..\Header\Common.hpp"

char tensComplement(char digit)
{
	char complement = '0';

	switch (digit)
	{
	case '0':
		complement = 'T';
		break;

	case '1':
		complement = '9';
		break;

	case '2':
		complement = '8';
		break;

	case '3':
		complement = '7';
		break;

	case '4':
		complement = '6';
		break;

	case '5':
		complement = '5';
		break;

	case '6':
		complement = '4';
		break;

	case '7':
		complement = '3';
		break;

	case '8':
		complement = '2';
		break;

	case '9':
		complement = '1';
		break;
	}

	return complement;
}

std::string subRem(std::string op, char borrow)
{
	std::string result = "";

	if (borrow == '1')
	{
		char d1 = prev(op[0]);
		op.erase(op.begin());

		if (d1 == 'N') // op[0] = '0'
		{
			result = charToString(prev(tensComplement('0'))) + subRem(op, '1');
		}
		else
		{
			result = charToString(d1) + op;
		}
	}
	else
	{
		result = op;
	}

	return result;
}

std::string subDigit(char d1, char d2, char borrow)
{
	std::string borrowBase = "";

#ifdef TRACE_L_1
	std::cout << "  subDigit : d1 = " << d1 << " d2 = " << tensComplement(d2) << "  borrow = " << borrow << std::endl;
#endif TRACE_L_1

	if (borrow == '1')
		d1 = prev(d1);

	if (d1 == 'N')
	{
		borrowBase = charToString('0') + prev(tensComplement(d2));
	}
	else
	{
		if (isGreaterDigit(d2, d1)) // d2 > d1
		{
			borrowBase = addDigit(d1, tensComplement(d2), '1');

#ifdef TRACE_L_1
			std::cout << "  subDigit : after addDigit :  d1 = " << d1 << " d2 = " << tensComplement(d2) << "  borrowBase = " << borrowBase[0] << borrowBase[1] << std::endl;
#endif TRACE_L_1
		}
		else // d2 <= d1
		{
			if (d2 == '0')
				borrowBase = charToString('0') + charToString(d1);
			else
				borrowBase = subDigit(prev(d1), prev(d2), '0');
		}
	}

	return borrowBase;
}

std::string sub1(std::string op1, std::string op2, char borrow)
{
	std::string result = "";

	if (op1.empty() && op2.empty())
	{
		result = borrow;
	}
	else if (op1.empty() && !op2.empty())
	{
		// assumption : op1 and op2 are just scalar and (op1 > op2) -> not possible condition
	}
	else if (!op1.empty() && op2.empty())
	{
		result = subRem(op1, borrow);
	}
	else // if (!op1.empty() && !op2.empty())
	{
		char d1 = op1[0];
		char d2 = op2[0];

		op1.erase(op1.begin());
		op2.erase(op2.begin());

#ifdef TRACE_L_1
		std::cout << " sub1 : d1 = " << d1 << " d2 = " << d2 << " borrow = " << borrow << std::endl;
#endif TRACE_L_1

		std::string borrowBase = subDigit(d1, d2, borrow);

#ifdef TRACE_L_1
		std::cout << " sub1 : borrowBase = " << borrowBase[0] << borrowBase[1] << std::endl;
#endif TRACE_L_1

		result = borrowBase[1] + sub1(op1, op2, borrowBase[0]);
	}

	return result;
}

// assumption : op1 and op2 are just scalar and op1 > op2
std::string sub(std::string op1, std::string op2)
{
	std::string subtraction = "";

	subtraction = rev(sub1(rev(op1), rev(op2), '0'));

	return subtraction;
}
