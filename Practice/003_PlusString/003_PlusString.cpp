#include <iostream>

int CharCount(const char* _Value)
{
    int Count = 0;

    // 배열의 개수를 세는 방법
    while (_Value[Count])
    {
        Count++;
    }

    return Count;
}


void PlusString(char* _Buffer, int _BufferSize, const char* const _Value0, const char* const _Value1)
{
    int Value0Count = CharCount(_Value0);
    int Value1Count = CharCount(_Value1);

    for (int i = 0; i < Value0Count; i++)
    {
        _Buffer[i] = _Value0[i];
    }
    for (int i = 0; i < Value1Count; i++)
    {
        _Buffer[i + Value0Count] = _Value1[i];
    }
 
    return;
}

int main()
{
    //char A[5] = "ABCD";
    //int Num = CharCount(A);

    char Arr[100] = {};

    PlusString(Arr, 100, "AAAA", "BBBB");

    Arr;

    char Arr1[100] = {};
    PlusString(Arr1, 100, "ABCD", "EFG");

    Arr1;

    std::cout << "Hello World!\n";
}
