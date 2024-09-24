#include <iostream>

int NumberCount(int _Value)
{
	int Result = 0;
	while (_Value)
	{
		_Value /= 10;
		Result += 1;
	}
	return Result;
}

const int IntMaxCount = 10;
const int ParameterInter = 8;

void NumberToString(char* Buffer, int BufferSize, int _Value)
{
	int Count = NumberCount(_Value);

	int MulValue = 1;
	for (int i = 0; i < Count - 1; i++)
	{
		MulValue *= 10;

	}

	for (int i = 0; i < Count; i++)
	{
		int CurValue = _Value / MulValue;
		Buffer[i] = '0' + CurValue;
		_Value -= CurValue * MulValue;
		MulValue /= 10;
	}

	//int MulVal = 10;
	//Arr[0] = _Value % MulVal;
	//_Value /= 10;
	//Arr[1] = _Value % MulVal;
	//_Value /= 10;
	//Arr[2] = _Value % MulVal;


	//Arr[0] = _Value / MulValue % 10; // 123 / 100 = 1.23 = 1
	//MulValue /= 10;
	//Arr[1] = _Value / MulValue % 10; // 123 / 10 = 12.3 % 10 = 2
	//MulValue /= 10;
	//Arr[2] = _Value / MulValue % 120; // 123 / 120 = 3
	////Arr[0] = _Value / MulValue; // 123 / 100 = 1.23 = 1
	////MulValue /= 10; 
	////Arr[1] = _Value / MulValue % 10; // 123 / 10 = 12 % 10 = 2
	////MulValue /= 10;
	////Arr[2] = _Value / MulValue % 120; // 123 / 1 = 123 % 120 = 3

	

	//char Ch = Value + '0';

	int CurValue = _Value / 10;


	return;
}

// 함수의 인자는 무조건 8바이트씩 떨어져 있다.
int MyPrintf(const char* const _Ptr, ...)
{
	__int64 FAdd = reinterpret_cast<__int64>(&_Ptr);

	int ChCount = 0;

	while (_Ptr[ChCount])
	{
		char Ch = _Ptr[ChCount];

		if (Ch == '%')
		{
			Ch = _Ptr[ChCount + 1];

			switch (Ch)
			{
			case 'd':
			{
				int* Ptr = reinterpret_cast<int*>(FAdd += ParameterInter);
				int ConvertValue = *Ptr;
				char Arr[IntMaxCount] = {};
				NumberToString(Arr, IntMaxCount, ConvertValue);

				MyPrintf("100");
				ChCount += 2;
				break;
			}
			default:
				break;
			}
			// 함수내부에서 자기자신을 다시 호출하는 방식을 사용해볼겁니다.
			// 이걸 재귀함수라고 부릅니다.
		}

		putchar(_Ptr[ChCount]);
		ChCount += 1;
	}

	return ChCount;
}

void ReFunction()
{
	// 잘 종료를 해줘야 한다.
	if (true)
	{
		return;
	}

	ReFunction();
}

int main()
{
	// int Value = '1';

	// ReFunction();

	// 숫자를 출력하는 기능을 포맷팅이라는 것으로 만들어 놨습니다.

	// %d는 정수 출력할께요
	// printf_s("%d, %d", nullptr);
	// printf_s("Number : %d\n", 12321);

	// \n 엔터 줄바꿈 처리를 해라.
	MyPrintf("Number : %d\n", 123);
	// MyPrintf("Number : %d\n", 333);
	// "Number : 100\n"

	// '\n';

	int Value = 123;

	char Arr[IntMaxCount] = {};
	// 100이라는 숫자부터 시작해야한다는것은 어떻게 알수 있을까?
	int NumberCountValue = NumberCount(Value);

	int MulValue = 1;

	for (int i = 0; i < NumberCountValue - 1; i++)
	{
		MulValue *= 10;
	}

	Arr[0] = Value / MulValue;
	// MulValue -= 1000;

	Arr[1] = Value / MulValue;
	// MulValue -= 100;

	Arr[2] = Value / MulValue;
	// MulValue -= 10;
}