#ifndef DATACONTAINER_H
#define DATACONTAINER_H

template <class T>
class dataContainer;


//=============================================================================
// Class: dataContainer
// Description: 
// TODO: 
//=============================================================================
template <class T>
class dataContainer {
	public:
		//Constructors
		dataContainer();
		dataContainer(int size);
		~dataContainer();

		//Mutators
		bool insert(T element, int position);
		bool clear();
		bool buildArray(int newSize);
		
		void bubbleSort();
		void selectionSort();
		void mergeSort(); //wrapper function
		void quickSort(); //wrapper function
		
		//Accessors
		T getDataElement(int position) const;
		int getElementsArraySize() const;
		int getAssignments() const;
		int getComparisons() const;
		
	private:
		void swapElements(int position1, int position2);		
		
		void mergeSort(T * arr, int l, int r);
		void merge(T * arr, int l, int m, int r);
		
		void quickSort(T * arr, int l, int r);
		int randomizedPartition(T * arr, int l, int r);
		int partition(T * arr, int l, int r);
		
		int assignments;
		int comparisons;
		int size;
		T * elements;
};

#include "dataContainer.cpp"

#endif
