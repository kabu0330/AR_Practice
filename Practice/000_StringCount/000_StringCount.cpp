#include <iostream>

int StringCount(const char* const _Str)
{
    int Count = 0;

    while (_Str[Count])
    {
        if (0 == _Str[Count])
        {
            break;
        }
        Count++;
    }
    return Count;
}

int StringCount1(const char* const _Str)
{
    int Count = 0;

    while (_Str[Count])
    {
        if ('\0' == _Str[Count])
        {
            break;
        }
        Count++;
    }
    return Count;
}

int StringCount0(const char* const _Str)
{
    int Count = 0;

    while (_Str[Count])
    {
        Count++;
    }
    return Count;
}


int main()
{
    // [B][B][B][B][0]

    int Result = StringCount("AAAA");
    int Result0 = StringCount0("AAAA");


    //int Count = strlen("BBBB");


    'A'; // 멀티 바이트
    "A"; // 멀티바이트 - 문자열
    L"A"; // 와이드 바이트 : 유니코드 != 인코딩
    // 문자를 표현하는 표준
    // 유니코드의 인코딩 방식은 UTF-8, UTF-16
    int a = 0;
}