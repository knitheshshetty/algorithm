#include <iostream>
#include <vector>

//problem statement
//give an algorithm that determines the number of inversions in any permutation on n elements


typedef std::vector<int> INPUT_STORE;
	
void merge(INPUT_STORE& inputStore, int& counter, const int startIndex, const int midIndex, const int endIndex)
{
	INPUT_STORE firstStore;
	for (int i=startIndex; i<=midIndex; ++i)
	{
		firstStore.push_back(inputStore[i]);	
	}

	INPUT_STORE secondStore;
	for(int i=midIndex+1; i<=endIndex; ++i)
	{
		secondStore.push_back(inputStore[i]);
	}

	int firstStoreSize = firstStore.size(), secondStoreSize = secondStore.size();
	for(int i = 0, j = 0; i < firstStoreSize && j < secondStoreSize;)
	{
		if (firstStore[i] > secondStore[j])
		{
			counter += (firstStoreSize - i);
			++j;
		}
		else
		{
			++i;
		}
	}
	
	int i{0}, j{0};
	for (int k=startIndex; k<=endIndex; ++k)	
	{
		if ((i < firstStoreSize) && (j < secondStoreSize)) 
		{
			if (firstStore[i] < secondStore[j])
			{
				inputStore[k] = firstStore[i++];
			}
			else
			{
				inputStore[k] = secondStore[j++];
			}
		}
		else if (i < firstStoreSize)
		{
			inputStore[k] = firstStore[i++];
		}
		else if (j < secondStoreSize)
		{
			inputStore[k] = secondStore[j++];
		}		
	}
}

void mergeSort(INPUT_STORE& inputStore, int& counter, const int startIndex, const int endIndex)
{
	if (startIndex < endIndex)
	{
		int midIndex = (startIndex + endIndex)/2;
		mergeSort(inputStore, counter, startIndex, midIndex);
		mergeSort(inputStore, counter, midIndex + 1, endIndex);
		merge(inputStore, counter, startIndex, midIndex, endIndex);
	}
}

int main()
{
	INPUT_STORE inputStore;
	int elementCnt{0}, inputVal{0};

	std::cout << "Please enter the number of elements" << std::endl;
	std::cin >>  elementCnt;	

	for (int i = 0; i < elementCnt; ++i)
	{
		std::cin >> inputVal;
		inputStore.push_back(inputVal);
	}
		
	
	int inputStoreSize = inputStore.size(), inversionCounter{0};
	mergeSort(inputStore, inversionCounter, 0, inputStoreSize - 1);
	for (auto val : inputStore)
	{
		std::cout << val << std::endl;
	}

	std::cout << "inversion counter  " << inversionCounter << std::endl;
}

