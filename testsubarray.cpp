#include <iostream>
#include <vector>

typedef struct result
{
	int beginPos;
	int endPos;
	int sum;	
	result():beginPos(0), endPos(0), sum(0)
	{}
	result(int beginPos_, int endPos_, int sum_): beginPos(beginPos_), endPos(endPos_), sum(sum_)
	{}
}RESULT;

RESULT MaxCrossSubArray(const std::vector<int>& inputStore, const int beginPos, const int midPos, const int lastPos)
{
	int firstHalfMaxSum(0), sum(0), startPos(midPos);
	for (int i=midPos; i >= beginPos; --i)
	{
		if ((i - 1) >= beginPos)
		{
			sum += (inputStore[i] - inputStore[i - 1]);
		}
		else
			sum += 0;

		if (sum >= firstHalfMaxSum)
		{
			firstHalfMaxSum = sum;
			startPos = ((i - 1) >= beginPos )? i-1 : i;
		}
	}
	
	sum=0;
	int lastHalfMaxSum(0), endPos(midPos);
	for (int i=midPos; i <= lastPos; ++i)
	{
		if ((i + 1) <= lastPos)
		{
			sum += (inputStore[i + 1] - inputStore[i]);
			
			if (sum >= lastHalfMaxSum)
			{
				lastHalfMaxSum = sum;
				endPos = ((i + 1) <= lastPos)? i + 1 : i;
			}
		}
	}
	
	return RESULT(startPos, endPos, firstHalfMaxSum + lastHalfMaxSum);
}

RESULT MaxSubArray(const std::vector<int>& inputStore, const int beginPos, const int lastPos)
{
	RESULT result;
	if (beginPos == lastPos)	
	{
		 result = RESULT(beginPos, lastPos, 0);
	}	
	else
	{
		int midPos = (beginPos + lastPos) / 2;
		RESULT firstHalf = MaxSubArray(inputStore, beginPos, midPos);
		RESULT lastHalf = MaxSubArray(inputStore, midPos +1, lastPos);
		RESULT crossOver = MaxCrossSubArray(inputStore, beginPos, midPos, lastPos);
		
		if ((firstHalf.sum >= lastHalf.sum) && (firstHalf.sum >= crossOver.sum))
		{
			result = firstHalf;
		}
		else if ((lastHalf.sum >= firstHalf.sum) && (lastHalf.sum >= crossOver.sum))
		{
			result = lastHalf;
		}
		else 
		{
			result = crossOver;
		}	
	}	
	
	return result;
} 

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

	RESULT result = MaxSubArray(inputStore, 0, inputStore.size() - 1);
	std::cout << "sum " << result.sum << " start pos " << result.beginPos << " end pos " << result.endPos  << std::endl;
}

