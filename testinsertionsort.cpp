#include <iostream>
#include <vector>
#include <utility>

class InsertionSort
{
	public:
		void operator()(std::vector<int>& inputStore)
		{
			int key{0}, j{0};
			for (int i = 1; i < inputStore.size(); ++i)
			{
				key = std::move(inputStore[i]);
				j = i - 1;
				while ((j>=0) && (inputStore[j] < key))
				{
					inputStore[j + 1] = std::move(inputStore[j]);
					--j;
				}	
				inputStore[j + 1] = std::move(key);
			}
		}
};

int main()
{
	std::vector<int> inputStore;
	int elementCnt{0}, val{0};
	std::cout << "Enter the number of elements to sorted " <<  std::endl;
	std::cin >> elementCnt;

	for (int i = 0; i < elementCnt ; ++i)
	{
		std::cin >> val;
		inputStore.push_back(val);
	}

	InsertionSort sortAlgo;
	sortAlgo(inputStore);
	for (int i=0 ; i<inputStore.size(); ++i)
	{
		std::cout << inputStore[i] << std::endl;
	}

}

