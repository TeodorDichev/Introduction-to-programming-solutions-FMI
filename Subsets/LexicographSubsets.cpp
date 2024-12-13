//#include <iostream>
//
//size_t powerTwo(size_t n)
//{
//	return (n <= 31) ? (1 << n) : 0;
//}
//
//void innerLoop(const int arr[], size_t size, size_t i)
//{
//	std::cout << "{ ";
//
//	for (size_t j = 0; j < size; j++)
//	{
//		if ((i & powerTwo(j)) != 0)
//		{
//			std::cout << arr[j] << " ";
//		}
//	}
//
//	std::cout << "}" << std::endl;
//}
//
//void generateSubsets(const int arr[], size_t size)
//{
//	size_t allElements = powerTwo(size);
//
//	for (size_t i = 0; i < allElements; i++)
//	{
//		innerLoop(arr, size, i);
//	}
//}
//
//int main()
//{
//	int arr[3]{ 1, 2, 3 };
//
//	generateSubsets(arr, 3);
//
//	return 0;
//}