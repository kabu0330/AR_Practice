#include <iostream>
#include <assert.h>
#include <Windows.h>

int main()
{
    LPCSTR;
    // window제공
    // 프로그램 파괴 

    // OutputDebugStringA("Error) 이름의 길이 너무 깁니다.");

    MessageBoxA(nullptr, "이름의 길이가 너무 깁니다", "치명적 에러", MB_OK);
    assert(false);

    int a; // 데이터 영역 100번지 ~ 103번지
    int* Ptr;
}