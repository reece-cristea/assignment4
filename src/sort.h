//
//  sort.h
//  
//  Functions for bubble sort, selection sort, and insertion sort.
//  You SHOULD modify this file.
//
//  Copyright 2019 David Kopec
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation files
//  (the "Software"), to deal in the Software without restriction,
//  including without limitation the rights to use, copy, modify, merge,
//  publish, distribute, sublicense, and/or sell copies of the Software,
//  and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice
//  shall be included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
//  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.

#ifndef sort_hpp
#define sort_hpp

#include <algorithm> // for swap()

using namespace std;

namespace csi281 {
    
    // Performs an in-place ascending sort of *array* of size *length*
    // using the bubble sort algorithm
    template <typename T>
    void bubbleSort(T array[], const int length) {
		//init temp variable to swap variables in the array
		T temp;
		//start first cycle through array
		for (int i = 0; i < (length - 1); i++)
		{
			//go through each element in array
			for (int j = 0; j < (length - i - 1); j++)
			{
				//compare if element is bigger than the one after it, if so swap them to sort
				if (array[j] > array[j + 1])
				{
					temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
				}
			}
		}
    }
    
    // Performs an in-place ascending sort of *array* of size *length*
    // using the selection sort algorithm
    template <typename T>
    void selectionSort(T array[], const int length) {
		//initiate temp for swapping and the smallest elements index
		T temp;
		int minIndex;
		//start 1st cycle through array
		for (int i = 0; i < (length - 1); i++)
		{
			//set minIndex to first index
			minIndex = i;
			//compare elements
			for (int j = i + 1; j < length; j++)
			{
				//if an element is smaller than the minimum make the element the new minimum
				if (array[j] < array[minIndex])
				{
					minIndex = j;
				}
			}
			temp = array[i];
			array[i] = array[minIndex];
			array[minIndex] = temp;
		}
    }
    
    // Performs an in-place ascending sort of *array* of size *length*
    // using the insertion sort algorithm
    template <typename T>
    void insertionSort(T array[], const int length) {
		//initiate key element and j to compare key to its predcessors
		T key;
		int j;
		//start iteration through array
		for (int i = 1; i < length; i++)
		{
			//set the key element to the element proceeding the one at hand
			key = array[i];
			j = i - 1;
			//compare key element to its predecessors and put key in its sorted place
			while (j >= 0 && array[j] > key)
			{
				array[j + 1] = array[j];
				j -= 1;
			}
			//set next element to key
			array[j + 1] = key;
		}
    }
}


#endif /* sort_hpp */
