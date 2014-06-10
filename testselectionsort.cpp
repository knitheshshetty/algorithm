#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::cin;

int main()
{
	vector<int> inputStore;
	int elementCnt{0}, val{0};

	cin >> elementCnt;
	for (int i=0; i<elementCnt; ++i)
	{
		cin >> val;
		inputStore.push_back(val);
	}	

	[&inputStore]()
	{
		int maxIndex{0}, storeSize=inputStore.size();
		for (int i=0; i<(storeSize - 1); ++i)
		{
			maxIndex=i;
			for (int j=i+1; j < storeSize; ++j)
			{
				if (inputStore[maxIndex] < inputStore[j])
				{
					maxIndex = j;
				}
			}

			if (maxIndex != i)
			{
				std::swap(inputStore[i], inputStore[maxIndex]);
			}
		}
	}();
		
	for (auto i : inputStore)
	{
		std::cout << i << std::endl;
	}	
}
