#include "dataContainer.h"
#include <iostream>
#include <cstdlib>
#include <string>

//=====================================
// = Driver Prototypes =
//=====================================

//=================================================================================================
// Function: UI
// Description: User Interface
//=================================================================================================
template <class T>
void UI(dataContainer<T> & container);
//=================================================================================================

//=================================================================================================
// Function: printArray
// Description: 
//=================================================================================================
template <class T>
void printArray(const dataContainer<T> & container);
//=================================================================================================

//=================================================================================================
// Function: fillRandom
// Description: 
//=================================================================================================
template <class T>
void fillRandom(dataContainer<T> & container);
//=================================================================================================

//=================================================================================================
// Function: fillOrdered
// Description: 
//=================================================================================================
template <class T>
void fillOrdered(dataContainer<T> & container);
//=================================================================================================

//=================================================================================================
// Function: fillReverseOrder
// Description: 
//=================================================================================================
template <class T>
void fillReverseOrder(dataContainer<T> & container);
//=================================================================================================

//=================================================================================================
// Function: printMatrix
// Description: 
//=================================================================================================
template <class T>
void printMatrix(const dataContainer<T> & container);
//=================================================================================================

//=================================================================================================
// Function: countDigits
// Description: 
//=================================================================================================
int countDigits(int number);
//=================================================================================================


//=====================================
// = Driver =
//=====================================

//=================================================================================================
int main() {
	dataContainer<int> myContainer;
	UI(myContainer);	
	
	return 0;
}
//=================================================================================================


//=====================================
// = Driver Definitions =
//=====================================

//=================================================================================================
// Function: UI
//=================================================================================================
template <class T>
void UI(dataContainer<T> & container) {
	int choice;
	bool success;
	do {
		std::cout << "                              " << std::endl;
		std::cout << "+====+=======================+" << std::endl;
		std::cout << "|[1] |Build Container        |" << std::endl;
		std::cout << "+====+=======================|" << std::endl;
		std::cout << "|[2] |Clear Container        |" << std::endl;
		std::cout << "+====+=======================+" << std::endl;
		std::cout << "|[3] |Fill Container Random  |" << std::endl;
		std::cout << "+====+=======================+" << std::endl;
		std::cout << "|[4] |Fill Container Ordered |" << std::endl;
		std::cout << "+====+=======================+" << std::endl;
		std::cout << "|[5] |Fill Container Reverse |" << std::endl;
		std::cout << "+====+=======================+" << std::endl;
		std::cout << "|[6] |View Container         |" << std::endl;
		std::cout << "+====+=======================+" << std::endl;
		std::cout << "|[7] |View Assigns/Compares  |" << std::endl;
		std::cout << "+====+=======================+" << std::endl;
		std::cout << "|[8] |Bubble Sort            |" << std::endl;
		std::cout << "+====+=======================+" << std::endl;
		std::cout << "|[9] |Selection Sort         |" << std::endl;
		std::cout << "+====+=======================+" << std::endl;
		std::cout << "|[10]|Merge Sort             |" << std::endl;
		std::cout << "+====+=======================+" << std::endl;	
		std::cout << "|[11]|Quick Sort             |" << std::endl;
		std::cout << "+====+=======================+" << std::endl;
		std::cout << "|[0] |Exit                   |" << std::endl;
		std::cout << "+====+=======================+" << std::endl;
		std::cout << "                              " << std::endl;
		
		std::cout << ">> ";
		std::cin >> choice;
		std::cout << std::endl;		
				
		switch (choice) {
			case 1:
				std::cout << std::endl;
				int size;
				std::cout << "Size: ";
				std::cin >> size;
				success = container.buildArray(size);
				if (success) {
					std::cout << std::endl;
					std::cout << "Built New Container." << std::endl;
					std::cout << std::endl;
				}
				else {
					std::cout << std::endl;
					std::cout << "Please Clear The Container." << std::endl;
					std::cout << std::endl;
				}
				std::cout << std::endl;
				break;
			case 2:
				std::cout << std::endl;
				container.clear();
				std::cout << "Cleared Container." << std:: endl;
				std::cout << std::endl;
				break;
			case 3:
				std::cout << std::endl;
				fillRandom(container);
				std::cout << "Filled Container With Random Integers." << std::endl;
				std::cout << std::endl;
				break;
			case 4:
				std::cout << std::endl;
				fillOrdered(container);
				std::cout << "Filled Container With Ordered Integers." << std::endl;
				std::cout << std::endl;
				break;
			case 5:
				std::cout << std::endl;
				fillReverseOrder(container);
				std::cout << "Filled Container With Reverse Ordered Integers." << std::endl;
				std::cout << std::endl;
				break;
			case 6:
				std::cout << std::endl;
				printArray(container);
				std::cout << std::endl;
				break;
			case 7:
				std::cout << std::endl;
				printMatrix(container);
				std::cout << std::endl;
				break;
			case 8:
				std::cout << std::endl;
				std::cout << "Sorting Container With Bubble Sort." << std::endl;
				container.bubbleSort();
				std::cout << std::endl;
				break;
			case 9:
				std::cout << std::endl;
				std::cout << "Sorting Container With Selection Sort." << std::endl;
				container.selectionSort();
				std::cout << std::endl;
				break;	
			case 10:
				std::cout << std::endl;
				std::cout << "Sorting Container With Merge Sort." << std::endl;
				container.mergeSort();
				std::cout << std::endl;
				break;	
			case 11:
				std::cout << std::endl;
				std::cout << "Sorting Container With Quick Sort." << std::endl;
				container.quickSort();
				std::cout << std::endl;
				break;					
		}
	} while (choice != 0);
}
//=================================================================================================

//=================================================================================================
// Function: printArray
//=================================================================================================
template <class T>
void printArray(const dataContainer<T> & container) {
	for (int i = 0; i < container.getElementsArraySize(); i++) {
		std::cout << container.getDataElement(i) << "  ";
		if ((i != 0) && (i % 10) == 0)
			std::cout << std::endl;
	}
	std::cout << std::endl;
}
//=================================================================================================

//=================================================================================================
// Function: fillRandom
//=================================================================================================
template <class T>
void fillRandom(dataContainer<T> & container) {
	for (int i = 0; i < container.getElementsArraySize(); i++) {
		container.insert(rand(), i);
	}
}
//=================================================================================================

//=================================================================================================
// Function: fillOrdered
//=================================================================================================
template <class T>
void fillOrdered(dataContainer<T> & container) {
	for (int i = 0; i < container.getElementsArraySize(); i++) {
		container.insert(i + 1, i);
	}
}
//=================================================================================================

//=================================================================================================
// Function: fillReverseOrder
//=================================================================================================
template <class T>
void fillReverseOrder(dataContainer<T> & container) {
	int reverse = container.getElementsArraySize();
	for (int i = 0; i < container.getElementsArraySize(); i++) {
		container.insert(reverse--, i);
	}
}
//=================================================================================================

//=================================================================================================
// Function: printMatrix
//=================================================================================================
template <class T>
void printMatrix(const dataContainer<T> & container) {
	int valueColumnWidth;
	std::string equalSign = "=";
	std::string aSpace = " ";
	std::string cSpace = " ";
	int assignmentsDigits = countDigits(container.getAssignments());
	int comparisonsDigits = countDigits(container.getComparisons());
	if (assignmentsDigits > comparisonsDigits)
		valueColumnWidth = assignmentsDigits;
	else
		valueColumnWidth = comparisonsDigits;
	for (int i = 0; i < valueColumnWidth; i++)
		equalSign = equalSign + "=";
	for (int i = 0; i < equalSign.length() - assignmentsDigits - 1; i++)
		aSpace = aSpace + " ";
	for (int i = 0; i < equalSign.length() - comparisonsDigits - 1; i++)
		cSpace = cSpace + " ";
	
	
	std::cout << "+===========+" << equalSign                            << "+" << std::endl;
	std::cout << "|Assignments|" << container.getAssignments() << aSpace << "|" << std::endl;
	std::cout << "+===========+" << equalSign                            << "+" << std::endl;
	std::cout << "|Comparisons|" << container.getComparisons() << cSpace << "|" << std::endl;
	std::cout << "+===========+" << equalSign                            << "+" << std::endl;
}
//=================================================================================================

//=================================================================================================
// Function: countDigits
//=================================================================================================
int countDigits(int number){
	int digits = 0;
	if (number <= 0) digits = 1;
	while (number) {
		number /= 10;
		digits++;
	}
	return digits;
}
//=================================================================================================
