#include "Header.h"

LARGE_INTEGER frequency;

microTime getMicroTime()
{
	microTime Output;

	LARGE_INTEGER Now;
	QueryPerformanceCounter(&Now);

	Output = Now.QuadPart * 1000000 / frequency.QuadPart;

	return Output;
}