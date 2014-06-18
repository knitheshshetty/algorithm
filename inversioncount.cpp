#include <iostream>
#include <vector>

//problem statement
//give an algorithm that determines the number of inversions in any permutation on n elements


typedef std::vector<int> INPUT_STORE;
	
int merge(INPUT_STORE& inputStore,  const int startIndex, const int midIndex, const int endIndex)
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
	int i{0}, j{0}, counter{0};
	for (int k=startIndex; k<=endIndex; ++k)	
	{
		if ((i < firstStoreSize) && (j < secondStoreSize)) 
		{
			if (firstStore[i] <= secondStore[j])
			{
				inputStore[k] = firstStore[i++];
			}
			else
			{
				counter += (firstStoreSize - i);
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

	return counter;
}

int mergeSort(INPUT_STORE& inputStore, const int startIndex, const int endIndex)
{
	int counter{0};
	if (startIndex < endIndex)
	{
		int midIndex = (startIndex + endIndex)/2;
		counter += mergeSort(inputStore, startIndex, midIndex);
		counter += mergeSort(inputStore, midIndex + 1, endIndex);
		counter += merge(inputStore, startIndex, midIndex, endIndex);
	}
	
	return counter;
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
		
	
	int inputStoreSize = inputStore.size();
	int inversionCounter = mergeSort(inputStore, 0, inputStoreSize - 1);
	for (auto val : inputStore)
	{
		std::cout << val << std::endl;
	}

	std::cout << "inversion counter  " << inversionCounter << std::endl;
}

