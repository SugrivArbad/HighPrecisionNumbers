/******************************************************************************************\
 * PROGRAMMER : Sugriv Arbad
 * 
 * ENVIROMENT : 
 * 1. OS : Windows
 * 2. Command Prompt : X64 Native Tools command prompt of VS2022
 * 
 * COMMANDS :
 * 1. cl.exe /EHsc HighPrecisionOperations.cpp Addition.cpp SubtractionPrevTenComp.cpp Multiplication.cpp
 * 2. HighPrecisionOperations.exe
\******************************************************************************************/

#include "..\Header\PrimitiveOperations.hpp"
#include <iostream>
#include <fstream>

#include <vector>
#include <random>

void testAddition()
{
	std::cout << std::endl << " testAddition START" << std::endl << std::endl;

	std::string result = "";
	std::string op1, op2;

	op1 = "-9999999999999999999999999999999999999999999999999";
	op2 = "11111111111111111111111111111111111111111118888888888888888888888888888888";

	std::string op3 = "1111111111111111111111111111111111999999999999999999999999999999999999999999999999999999";
	std::string op4 = "22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222";


	/* ---- ADDITION START ------------------ */

	result = addition(op1, op2);
	displayOperation(op1, op2, result, '+');

	result = addition(op3, op4);
	displayOperation(op3, op4, result, '+');

	/* ---- ADDITION END  ------------------- */




	/*--------- EXTRA OPERATIONS : START --------------------------------------------------------------------*/

	/*op1 = "+9999999999999999999999999999999999999999999999999";
	op2 = "+11111111111111111111111111111111111111111118888888888888888888888888888888";

	result = addition(op1, op2);
	displayOperation(op1, op2, result, '+');

	op1 = "+9999999999999999999999999999999999999999999999999";
	op2 = "11111111111111111111111111111111111111111118888888888888888888888888888888";

	result = addition(op1, op2);
	displayOperation(op1, op2, result, '+');

	op1 = "9999999999999999999999999999999999999999999999999";
	op2 = "+11111111111111111111111111111111111111111118888888888888888888888888888888";

	result = addition(op1, op2);
	displayOperation(op1, op2, result, '+');

	op1 = "9999999999999999999999999999999999999999999999999";
	op2 = "11111111111111111111111111111111111111111118888888888888888888888888888888";

	result = addition(op1, op2);
	displayOperation(op1, op2, result, '+');

	displayOperation("2", "01", addition("2", "01"), '+');*/

	/*--------- EXTRA OPERATIONS : END  ---------------------------------------------------------------------*/

	std::cout << std::endl << " testAddition END" << std::endl << std::endl;
}

void testSubraction()
{
	std::cout << std::endl << " testSubraction START" << std::endl << std::endl;

	std::string result = "";
	std::string op1, op2;

	op1 = "-9999999999999999999999999999999999999999999999999";
	op2 = "11111111111111111111111111111111111111111118888888888888888888888888888888";

	std::string op3 = "1111111111111111111111111111111111999999999999999999999999999999999999999999999999999999";
	std::string op4 = "22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222";


	/* ---- SUBTRACTION START ------------------- */

	result = subtraction(op4, op3);
	displayOperation(op4, op3, result, '-');

	std::string opE1 = "60", opE2 = "1";
	result = subtraction(opE1, opE2);
	displayOperation(opE1, opE2, result, '-');

	/* ---- SUBTRACTION END  ------------------- */

	std::cout << std::endl << " testSubraction END" << std::endl << std::endl;
}

void testMultiplication()
{
	std::cout << std::endl << " testMultiplication START" << std::endl << std::endl;

	std::string result = "";
	std::string op1, op2;

	op1 = "-9999999999999999999999999999999999999999999999999";
	op2 = "11111111111111111111111111111111111111111118888888888888888888888888888888";

	std::string op3 = "1111111111111111111111111111111111999999999999999999999999999999999999999999999999999999";
	std::string op4 = "22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222";



	/* ---- MULTIPLICATION START  ------------------- */

	std::string opM1 = "1200";
	std::string opM2 = "60";
	std::string resultMul1 = mult(opM1, opM2);
	displayOperation(opM1, opM2, resultMul1, '*');

	/* ---- MULTIPLICATION END  ------------------- */


#ifndef TRACE_L_1
	std::cout << std::endl << std::endl << " main end : op1.size() = " << op1.size() << " op2.size() = " << op2.size() << " op1.max_size() = " << op1.max_size() << std::endl << std::endl;

	std::cout << " BUT MAX string size allowed by cl.exe compiler of VS2022 is '16383'." << std::endl << std::endl;
#endif // TRACE_L_1

	std::cout << std::endl << " testMultiplication END" << std::endl << std::endl;
}


void testAllIntegers_V1()
{
	long long res;
	std::string strRes;

	for (long long i = INT_MIN; i < INT_MAX; i++)
	{
		for (long long j = INT_MIN; j < INT_MAX; j++)
		{
			long long res = i + j;
			std::string strRes = addition(std::to_string(i), std::to_string(j));
			if (std::to_string(res) != strRes)
			{
				std::cout << " ADDTION NOT MATCHED : " << i << " + " << j << " = " << res << std::endl;
				std::cout << "        YOUR OUTPUT: " << strRes << std::endl << std::endl;
			}
		}
	}
}

void testAllIntegersAddition()
{
	auto check = [](long long i, long long j) {
		std::ofstream fout;
		static int cnt = 1;
		
		long long expected = i + j;
		std::string result = addition(std::to_string(i), std::to_string(j));
		
		if (std::to_string(expected) != result)
		{
			std::cout << std::endl << cnt++ << "] ****** MISMATCH: " << i << " + "<< j
				<< " expected = " << expected
				<< " got = " << result << std::endl << std::endl;

#ifdef TRACE_L_2
			fout.open("testAllIntegersAddition.txt", std::ios::app);
			fout << std::endl << cnt++ << "] ****** MISMATCH: " << i << " + " << j
				<< " expected = " << expected
				<< " got = " << result << std::endl << std::endl;
			fout.close();
#endif // TRACE_L_2

			return false;
		}

#ifdef TRACE_L_2
		fout.open("testAllIntegersAddition.txt", std::ios::app);
		fout << cnt++ << "] MATCHED : " << i << " + " << j
			<< " expected = " << expected
			<< " got = " << result << "\n";
		fout.close();
#endif // TRACE_L_2

		return true;
		};

	int failures = 0;

	// 1. Boundary values
	std::vector<long long> boundaries = {
		INT_MIN, INT_MIN + 1LL, -1LL, 0LL, 1LL,
		INT_MAX - 1LL, INT_MAX,
		(long long)INT_MIN - 1, (long long)INT_MAX + 1   // beyond int range
	};

	for (long long i : boundaries)
		for (long long j : boundaries)
			if (!check(i, j)) failures++;

	// 2. Random sampling across full range
	std::mt19937_64 rng(42);
	std::uniform_int_distribution<long long> dist(INT_MIN, INT_MAX);
	for (int k = 0; k < 1'000'000; k++)
		if (!check(dist(rng), dist(rng))) failures++;

	// 3. Small values exhaustively (-1000 to 1000)
	for (long long i = -1000; i <= 1000; i++)
		for (long long j = -1000; j <= 1000; j++)
			if (!check(i, j)) failures++;

	std::cout << "Test complete. Failures: " << failures << "\n";
}

void testAllIntegersSubtraction()
{

	auto check = [](long long i, long long j) {
		std::ofstream fout;
		static int cnt = 1;

		long long expected = i - j;
		std::string result = subtraction(std::to_string(i), std::to_string(j));
		
		if (std::to_string(expected) != result)
		{
			std::cout << std::endl << cnt++ << "] ****** MISMATCH: " << i << " - " << j
				<< " expected = " << expected
				<< " got = " << result << std::endl << std::endl;

#ifdef TRACE_L_2
			fout.open("testAllIntegersSubtraction.txt", std::ios::app);
			fout << std::endl << cnt++ << "] ****** MISMATCH: " << i << " - " << j
				<< " expected = " << expected
				<< " got = " << result << std::endl << std::endl;
			fout.close();
#endif // TRACE_L_2

			return false;
		}

#ifndef TRACE_L_2
		fout.open("testAllIntegersSubtraction.txt", std::ios::app);
		fout << cnt++ << "] MATCHED : " << i << " - " << j
			<< " expected = " << expected
			<< " got = " << result << "\n";
		fout.close();
#endif // TRACE_L_2

		return true;
		};

	int failures = 0;

	// 1. Boundary values
	std::vector<long long> boundaries = {
		INT_MIN, INT_MIN + 1LL, -1LL, 0LL, 1LL,
		INT_MAX - 1LL, INT_MAX,
		(long long)INT_MIN - 1, (long long)INT_MAX + 1   // beyond int range
	};

	for (long long i : boundaries)
		for (long long j : boundaries)
			if (!check(i, j)) failures++;

	// 2. Random sampling across full range
	std::mt19937_64 rng(42);
	std::uniform_int_distribution<long long> dist(INT_MIN, INT_MAX);
	for (int k = 0; k < 1'000'000; k++)
		if (!check(dist(rng), dist(rng))) failures++;

	// 3. Small values exhaustively (-1000 to 1000)
	for (long long i = -1000; i <= 1000; i++)
		for (long long j = -1000; j <= 1000; j++)
			if (!check(i, j)) failures++;

	std::cout << "Test complete. Failures: " << failures << "\n";
}


void testVerification()
{
#ifndef TRACE_L_1
	std::cout << " testVerification : " << std::endl << std::endl;
#endif // TRACE_L_1

	std::string op1;
	std::string op2;
	std::string result = "";

	op1 = "1830096269";
	op2 = "-1960577484";

#ifndef TRACE_L_1
	std::cout << " testVerification : op1 = " << op1 << " op2 = " << op2 << std::endl << std::endl;
#endif // TRACE_L_1

	result = addition(op1, op2);

	displayOperation(op1, op2, result, '+');


	/*
MISMATCH: 1830096269 + -1960577484 expected = -130481215 got = 9869518785
MISMATCH : -174203477 + 858391973 expected = 684188496 got = -315811504
MISMATCH : -360866167 + 717705912 expected = 356839745 got = -643160255
MISMATCH : 1376607447 + -1828624809 expected = -452017362 got = 9547982638
*/

}

void testAddDigit();

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << std::endl << " USAGE : <ExecutableName> <1st Integer> <2nd Integer>" << std::endl << std::endl;
		return 0;
	}

	// your addition
	displayOperation(argv[1], argv[2], addition(argv[1], argv[2]), '+');
	// your subtraction
	displayOperation(argv[1], argv[2], subtraction(argv[1], argv[2]), '-');
	// your multiplication
	displayOperation(argv[1], argv[2], mult(argv[1], argv[2]), '*');

	std::cout << std::endl << std::endl << "===========================================================================================================" << std::endl << std::endl << std::endl << std::endl;

	//// to test addition
	//testAddition();

	//// to test addition
	//testSubraction();

	//// to test addition
	//testMultiplication();

	// big test addition
	//testAllIntegersAddition();

	// big test subtraction
	testAllIntegersSubtraction();


	// testVerification
	//testVerification();
}

/***************** TESTING **************************************/
void testAddDigit()
{
#ifdef TRACE_L_1
	std::cout << std::endl << " ******** testAddDigit start ***************************** " << std::endl;
#endif // TRACE_L_1

	/*std::string carryBase = "00";

	carryBase = addDigit('9', '8', '0');*/

#ifdef TRACE_L_1
	std::cout << " testAddDigit : carryBase = " << carryBase[0] << carryBase[1] << std::endl;
	std::cout << std::endl << " ******** testAddDigit end ***************************** " << std::endl << std::endl;
#endif // TRACE_L_1
}


/******************************************************************************************\
|********* TODO ***************************************************************************|
 * 1. #define DIGIT0 '0'  => for all '1' to '9'
 * 2. Add try catch blocks
 * 3. Add assertion
 * 4. Use framaC IDE
 * 5. Comparison of digits based on ASCII char
 * 6. Convert switch cases into maps
 * 7. Add signed integers for subtraction
\******************************************************************************************/





/******************************************************************************************\
|********* OUTPUT EXAMPLE : on Console (X64 Native Tools Command Prompt for VS2022 ********|
\******************************************************************************************/
/*


C:\Users\Sugriv\RTR7-2026\Session-10-08May2026\HighPrecisionNumbers\Source>cl.exe /EHsc HighPrecisionOperations.cpp Addition.cpp SubtractionPrevTenComp.cpp Multiplication.cpp
Microsoft (R) C/C++ Optimizing Compiler Version 19.43.34810 for x64
Copyright (C) Microsoft Corporation.  All rights reserved.

HighPrecisionOperations.cpp
Addition.cpp
SubtractionPrevTenComp.cpp
Multiplication.cpp
Generating Code...
Microsoft (R) Incremental Linker Version 14.43.34810.0
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:HighPrecisionOperations.exe
HighPrecisionOperations.obj
Addition.obj
SubtractionPrevTenComp.obj
Multiplication.obj

C:\Users\Sugriv\RTR7-2026\Session-10-08May2026\HighPrecisionNumbers\Source>HighPrecisionOperations.exe

*************** 1] ADDTION START *********************************************************************************


								-9999999999999999999999999999999999999999999999999
	+   11111111111111111111111111111111111111111118888888888888888888888888888888

   _______________________________________________________________________________

		11111111111111111111111101111111111111111118888888888888888888888888888889

*************** 1] ADDTION END **********************************************************************************




*************** 2] ADDTION START *********************************************************************************


				  1111111111111111111111111111111111999999999999999999999999999999999999999999999999999999
	+   22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222

   _______________________________________________________________________________________________________

		22222222223333333333333333333333333333333334222222222222222222222222222222222222222222222222222221

*************** 2] ADDTION END **********************************************************************************




*************** 3] SUBTRACITON START *********************************************************************************


		22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
	-             1111111111111111111111111111111111999999999999999999999999999999999999999999999999999999

   _______________________________________________________________________________________________________

		22222222221111111111111111111111111111111110222222222222222222222222222222222222222222222222222223

*************** 3] SUBTRACITON END **********************************************************************************




*************** 4] SUBTRACITON START *********************************************************************************


		60
	-    1

   _______

		59

*************** 4] SUBTRACITON END **********************************************************************************




*************** 5] MULTIPLICATION START *********************************************************************************


		1200
	*     60

   _________

		72000

*************** 5] MULTIPLICATION END **********************************************************************************




C:\Users\Sugriv\RTR7-2026\Session-10-08May2026\HighPrecisionNumbers\Source>

*/



