#include "pch.h"
#include <iostream>     // std::cout
#include <algorithm>    // std::find
#include <functional>  

class Stampdispenser {
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
	void StampDispenser(int myint[], int value);
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
	int n;
	int arr[7];
};

int Stampdispenser::CalcNumStampsToFillRequest(int request) {
	int totstamps = 0;
	int newrequest = request; // Updated request after filter higher stamp values
	for (int i = 0; i < n; i++) {
		if (newrequest / arr[i] == 0){
		}
		else{
			std::cout << " - " << newrequest / arr[i] << ", " << arr[i] << " valued stamps." << '\n';
			totstamps = totstamps + newrequest / arr[i]; //Updates total stamp number
			newrequest = newrequest % arr[i]; //Updates request down the list of values
			if (newrequest == 0) { // Exits loop when there is no remainder
				i = n;
			}
		}
	}
	return totstamps;
}

void Stampdispenser::StampDispenser(int myint[],int value) {
	int *p;
	n = value;
	p = std::find(myint, myint + n, 1); // Searches for value of 1 in array
	if (p != myint + n) {}
	else {
		std::cout << "Element not found in myints\n"; // Exits program if there is not a 1
		exit(1);
	}
	
	std::sort(myint, myint + n, std::greater<int>()); // Orders the array in descending order
	for (int i = 0; i < n; i++) {
		arr[i] = myint[i];
	}

}

int main() {
	int stampDenominations[] = { 90, 30, 24, 10, 6, 2, 1 };
	int n = (sizeof(stampDenominations) / sizeof(*stampDenominations)); // Counts size of the array
	int i; // Integer cin response
	char response[50]; // Character response to exit program
	Stampdispenser sd;
	sd.StampDispenser(stampDenominations,n);
	while (int m = 0 < 1) { // Loop that incorporates the dialogue
		std::cout << "Please enter an integer stamp value: ";
		std::cin >> i;
		if (i <= 0) {
			std::cout << "Not a valid request." << '\n';
		}
		else {
			std::cout << "Number of stamps needed: " << sd.CalcNumStampsToFillRequest(i) << '\n';
			std::cout << "Repeat?(Y/N): ";
			std::cin >> response;
			if (strncmp(response, "N", 1) == 0) { exit(1); }
		}
	}
	
	return 0;
}
