#include <iostream>

// 음수 안함
// 0 이외의 양수의 자릿수를 세자.
int NumberCount(int _Value)
{
    // /(나누기를 최대한) 연산을 사용하세요.
    int Result = 0;

    while (true)
    {
        _Value /= 10;
        Result += 1;

        if (0 == _Value)
        {
            return Result;
        }
    }

}


// 해도 되고 안해도 됩니다.
// 내 기준으로 지금
// _Value 를 넣어주면 Buffer에 
// 숫자를 문자열로 만드는 함수.
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

	return;
}

int main()
{

    // 5
    int Result0 = NumberCount(12358);
    // 4
    int Result1 = NumberCount(5258);
    // 7
    int Result2 = NumberCount(5258111);
    // 3
    int Result3 = NumberCount(120);

    // 0은 영

    char Buffer[100] = { 0 };

    NumberToString(Buffer, 100, 3712);
    char Buffer1[100] = { 0 };
    NumberToString(Buffer1, 100, 12345);
    char Buffer2[100] = { 0 };
    NumberToString(Buffer2, 100, 506070);
    char Buffer3[100] = { 0 };
    NumberToString(Buffer3, 100, 123);


    Buffer;

    int a = 0;
}
