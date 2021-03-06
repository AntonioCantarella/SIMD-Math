#include "Performance.h"
#include "VectorTest.h"
#include "VectorizedArrayTest.h"
#include "NonVectorizedArrayTest.h"
#include "SSEVectorTest.h"
#include "NonSSEVectorTest.h"
#include "NonSSEMatrixTest.h"
#include "SSEMatrixTest.h"

int main()
{
	//Performance<NonVectorizedArrayTest>::Test(20'000);
	//Performance<VectorizedArrayTest>::Test(20'000);
	//Performance<VectorTest>::Test(2'000'000);
	//Performance<SseVectorTest>::Test(2'000);
	//Performance<NonSSEVectorTest>::Test(2'000);
	Performance<SseMatrixTest>::Test(2'000);
	Performance<NonSSEMatrixTest>::Test(2'000);
	std::cin.get();
}
