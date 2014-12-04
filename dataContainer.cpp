#include "dataContainer.h"
#include <cstdlib>
#include <iostream>

//=====================================
// = Constructors =
//=====================================

//=================================================================================================
// Class: dataContainer
// Function: Default Constructor
// Description: Instatiates a dataContainer object with a size of 0.
// TODO:
//=================================================================================================
template <class T>
dataContainer<T>::dataContainer() {
	elements = 0;
	size = 0;
	assignments = 0;
	comparisons = 0;
}
//=================================================================================================


//=================================================================================================
// Class: dataContainer
// Function: Overloaded Constructor
// Description: Instantiates a dataContainer object with a dynamically allocated templated array
//				 of a user defined size.
// TODO:
//=================================================================================================
template <class T>
dataContainer<T>::dataContainer(int size) {
	elements = new T [size];
	assignments = 0;
	comparisons = 0;
}
//=================================================================================================


//=================================================================================================
// Class: dataContainer
// Function: Destructor
// Description: Deallocates the dynamic array contained within the object.
// TODO:
//=================================================================================================
template <class T>
dataContainer<T>::~dataContainer() {
	if (size > 0)
		delete [] elements;
}
//=================================================================================================


//=====================================
// = Mutators =
//=====================================


//=================================================================================================
// Class: dataContainer
// Function: swapElements
// Description: Swaps the elements in position 1 and position 2.
// TODO:
//=================================================================================================
template <class T>
void dataContainer<T>::swapElements(int position1, int position2) {
	T temp = elements[position1];
	assignments++;
	elements[position1] = elements[position2];
	assignments++;
	elements[position2] = temp;	
	assignments++;
}
//=================================================================================================


//=================================================================================================
// Class: dataContainer
// Function: insert
// Description: Inserts an item into the elements array at the desired position. 
//				 Returns false if an attempt is made to insert an element outside of the range.
// TODO:
//=================================================================================================
template <class T>
bool dataContainer<T>::insert(T element, int position) {
	if (position >= size) return false;
	else {
		elements[position] = element;
		return true;
	}
}
//=================================================================================================


//=================================================================================================
// Class: dataContainer
// Function: clear
// Description: Deletes the elements array
// TODO:
//=================================================================================================
template <class T>
bool dataContainer<T>::clear() {
	if (size > 0)
		delete [] elements;
	size = 0;
}
//=================================================================================================


//=================================================================================================
// Class: dataContainer
// Function: buildArray
// Description: Builds a new array
// TODO:
//=================================================================================================
template <class T>
bool dataContainer<T>::buildArray(int newSize) {
	if (size > 0)
		return false;
	elements = new T [newSize];
	size = newSize;
	return true;
}
//=================================================================================================


//=================================================================================================
// Class: dataContainer
// Function: bubbleSort
// Description: Sorts the items in the elements array using a bubble sort.
// TODO:
//=================================================================================================
template <class T>
void dataContainer<T>::bubbleSort() {
	int i, j;
	bool swapped;
	assignments = 0;
	comparisons = 0;
	for (i = 0; i < size; i++) {
		swapped = false;
		assignments++;
		for (j = 0; j < size - i - 1; j++) {
			if (elements[j] > elements[j + 1]) {
				comparisons++;
				swapElements(j, j + 1);
				swapped = true;
				assignments++;
			}
		}
		if (swapped == false) {
			comparisons++;
			return;
		}
		 
	}
}
//=================================================================================================


//=================================================================================================
// Class: dataContainer
// Function: selectionSort
// Description: Sorts the items in the elements array using a selection sort.
// TODO:
//=================================================================================================
template <class T>
void dataContainer<T>::selectionSort() {
	int i, j, minIndex;
	assignments = 0;
	comparisons = 0;
	for (int i = 0; i < size - 1; i++) {
		minIndex = i;
		assignments++;
		for (int j = i + 1; j < size; j++) {
			if (elements[j] < elements[minIndex]) {
				comparisons++;
				minIndex = j;
				assignments++;
			}
		}
		swapElements(i, minIndex);
	}
}
//=================================================================================================


//=================================================================================================
// Class: dataContainer
// Function: mergeSort
// Description: 
// TODO:
//=================================================================================================
template <class T>
void dataContainer<T>::mergeSort() {
	assignments = 0;
	comparisons = 0;
	mergeSort(elements, 0, size - 1);
}
//=================================================================================================


//=================================================================================================
// Class: dataContainer
// Function: mergeSort
// Description: 
// TODO:
//=================================================================================================
template <class T>
void dataContainer<T>::mergeSort(T * arr, int l, int r) {
	if (l < r) {
		comparisons++;
		int m = (l + r) / 2;
		assignments++;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}
//=================================================================================================


//=================================================================================================
// Class: dataContainer
// Function: merge
// Description: 
// TODO:
//=================================================================================================
template <class T>
void dataContainer<T>::merge(T * arr, int l, int m, int r) {
	int i, j, k;
	int sizeL = m - l + 1;
	assignments++;
	int sizeR = r - m;
	assignments++;
	
	T * L = new T [sizeL];
	assignments++;
	T * R = new T [sizeR];
	assignments++;
	
	for (i = 0; i < sizeL; i++) {
		L[i] = arr[l + i];
		assignments++;
	}
	for (j = 0; j < sizeR; j++) {
		R[j] = arr[m + 1 + j];
		assignments++;
	}
	
	i = 0;
	j = 0;
	k = l;
	while ((i < sizeL) && (j < sizeR)) {
		if (L[i] <= R[j]) {
			comparisons++;
			arr[k] = L[i];
			assignments++;
			i++;
		}
		else {
			comparisons++;
			arr[k] = R[j];
			assignments++;
			j++;
		}
		k++;
	}
	while (i < sizeL) {
		arr[k] = L[i];
		assignments++;
		i++;
		k++;
	}	
	while (j < sizeR) {
		arr[k] = R[j];
		assignments++;
		j++;
		k++;
	}
	
	delete [] L;
	delete [] R;
}
//=================================================================================================


//=================================================================================================
// Class: dataContainer
// Function: quickSort
// Description: 
// TODO:
//=================================================================================================
template <class T>
void dataContainer<T>::quickSort() {
	assignments = 0;
	comparisons = 0;
	quickSort(elements, 0, size - 1);		
}
//=================================================================================================


//=================================================================================================
// Class: dataContainer
// Function: quickSort
// Description: 
// TODO:
//=================================================================================================
template <class T>
void dataContainer<T>::quickSort(T * arr, int l, int r) {
	if (l < r) {
		comparisons++;
		int pIndex = randomizedPartition(arr, l, r);
		assignments++;
		quickSort(arr, l, pIndex - 1);
		quickSort(arr, pIndex + 1, r);		
	}
}
//=================================================================================================


//=================================================================================================
// Class: dataContainer
// Function: randomizedPartition
// Description: 
// TODO:
//=================================================================================================
template <class T>
int dataContainer<T>::randomizedPartition(T * arr, int l, int r) {
	int pIndex = l + (rand() % (r - l));
	assignments++;
	swapElements(r, pIndex);
	return partition(arr, l, r);
}
//=================================================================================================


//=================================================================================================
// Class: dataContainer
// Function: partition
// Description: 
// TODO:
//=================================================================================================
template <class T>
int dataContainer<T>::partition(T * arr, int l, int r) {
	T pivot = arr[r];
	assignments++;
	int pIndex = l;
	for (int i = l; i < r; i++) {
		if (arr[i] <= pivot) {
			comparisons++;
			swapElements(i, pIndex);
			pIndex++;
		}
	}
	swapElements(pIndex, r);
	return pIndex;
}
//=================================================================================================


//=====================================
// = Accessors =
//=====================================

//=================================================================================================
// Class: dataContainer
// Function: getDataElement
// Description: Returns an element from the requested position in the elements array
// TODO:
//=================================================================================================
template <class T>
T dataContainer<T>::getDataElement(int position) const{
	return elements[position];
}
//=================================================================================================


//=================================================================================================
// Class: dataContainer
// Function: getElementsArraySize
// Description: Returns an integer representing the current size of the elements array
// TODO:
//=================================================================================================
template <class T>
int dataContainer<T>::getElementsArraySize() const{
	return size;
}
//=================================================================================================


//=================================================================================================
// Class: dataContainer
// Function: getAssignments
// Description: Returns the number of assignments performed by the last sorting method used.
// TODO:
//=================================================================================================
template <class T>
int dataContainer<T>::getAssignments() const{
	return assignments;
}
//=================================================================================================


//=================================================================================================
// Class: dataContainer
// Function: getComparisons
// Description: Returns the number of comparisons performed by the last sorting method used.
// TODO:
//=================================================================================================
template <class T>
int dataContainer<T>::getComparisons() const{
	return comparisons;
}
//=================================================================================================
