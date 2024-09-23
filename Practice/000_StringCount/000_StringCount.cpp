#include <iostream>

int StringCount(const char* const _Str)
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


int main()
{
    // [B][B][B][B][0]

    int Result = StringCount("AAAA");

    //int Count = strlen("BBBB");

    int a = 0;
}