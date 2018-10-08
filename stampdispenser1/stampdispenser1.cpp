// stampdispenser1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>		// std::cout
#include <algorithm>    // std::find
#include <functional>  
#include <stdlib.h>
#include <assert.h>

/// <summary>
/// Facilitates dispensing stamps for a postage stamp machine.
/// </summary>
class StampDispenser
{
private:
	int finalstampD;
	size_t sizestampD;
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="StampDispenser"/> class that will be 
	/// able to dispense the given types of stamps.
	/// </summary>
	/// <param name="stampDenominations">
	/// The values of the types of stamps that the machine has.  
	/// Should be sorted in descending order and contain at least a 1.
	/// </param>
	/// <param name="numStampDenominations">
	/// The number of types of stamps in the stampDenominations array. 
	/// </param>
	/// ******************************************************************************
	/// stampD is stampDenominations, numstampD is numStampDenominations 
	/// change of variable names
	/// ******************************************************************************
	StampDispenser(int stampD[], size_t numstampD);

	/// <summary>
	/// Returns the minimum number of stamps that the machine can dispense to
	/// fill the given request.
	/// </summary>
	/// <param name="request">
	/// The total value of the stamps to be dispensed.
	/// </param>
	/// <returns>
	/// The minimum number of stamps needed to fill the given request.
	/// </returns>
	int CalcNumStampsToFillRequest(int request);
};

StampDispenser::StampDispenser(int stampD[], size_t numstampD) {
	/// input array must contain a stamp with cost 1. 
	int* p;
	p = std::find(stampD, stampD + numstampD, 1);
	if (p != stampD + numstampD)
		std::cout << "Element found: " << *p << '\n';
	else
		std::cout << "Array does not contain 1." << '\n';
		exit(1);



}

StampDispenser::CalcNumStampsToFillRequest(int request) {





}

int main()
{
	////int stampDenominations[] = {90, 30, 24, 10, 6, 2, 1};
	////StampDispenser stampDispenser(stampDenominations, 7);
	////assert(stampDispenser.CalcNumStampsToFillRequest(18) == 3);

	return 0;
}






// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
