#include <iostream>

// 전역변수
const int LINECOUNT = 50;
const int NAMELEN = 10;

int PlayerAtt = 0;
int PlayerHp = 0;
char PlayerName[NAMELEN] = "NONE";

int MonsterAtt = 10;
int MonsterHp = 100;
char MonsterName[NAMELEN] = "NONE";


// 배열과 배열 간 대입 불가
// 문자열 복사 함수
void StrCopy(char* _Arr, int _BufferSize, const char* const _Name)
{
    for (int i = 0; i < _BufferSize; i += 1)
    {
        _Arr[i] = 0;
    }

    // C스타일 글자 개수 세어주는 함수
    int Size = strlen(_Name);
    // _Arr[0] = _Name[0];
    // strcpy_s()
    for (int i = 0; i < Size; i++)
    {
        _Arr[i] = _Name[i];
    }

    if (Size > _BufferSize)
    {
        _Arr[_BufferSize] = 0;
    }
}

// 행동
void CreatePlayer(const char* const _Ptr, int _Att, int _Hp)
{
    // char[100] = 300번지
    StrCopy(PlayerName, NAMELEN, _Ptr);
    PlayerAtt = _Att;
    PlayerHp = _Hp;
}

// 모든 문법은 코드를 덜치기 위해서 발전해왔습니다.
void CreateMonster(const char* const _Ptr, int _Att, int _Hp)
{
    StrCopy(MonsterName, NAMELEN, _Ptr);
    MonsterAtt = _Att;
    MonsterHp = _Hp;
}

void StatusRender(const char* _Name, int _Att, int _HP)
{
    // _Name 문자열의 개수를 셀 변수 StrCount
    int StrCount = 0;
    StrCount = printf_s("%s Status ", _Name);
    int HyphenDrawCount = LINECOUNT - StrCount;
    for (int i = 0; i < HyphenDrawCount; i += 1)
    {       
        printf_s("-");
    }
    printf_s("\n");
    
    printf_s("공격력 : %d\n", _Att);
    printf_s("체력 : %d\n", _HP);

    for (int i = 0; i < LINECOUNT; i += 1)
    {
        printf_s("-");
    }
    printf_s("\n");
}

void PlayerStatusRender()
{
    StatusRender(PlayerName, PlayerAtt, PlayerHp);
}

void MonsterStatusRender()
{
    StatusRender(MonsterName, MonsterAtt, MonsterHp);
}

int main()
{
    // char Test0[100] = "Player";
    /*char Test1[50] = Test0;
    Test1 = Test0*/;

    CreatePlayer("TestPlayer12345", 10, 100);
    CreateMonster("Orc123456789", 10, 50);
    

    PlayerStatusRender();
    MonsterStatusRender();

    CreateMonster("Goblin", 15, 70);
    MonsterStatusRender();

    CreateMonster("Black Fairy", 20, 60); // 11자리 마지막 'y' 문자 생략
    MonsterStatusRender();


    // printf_s("싸운다");
    // 나는 이걸 플레이어라고 생각할 겁니다.

    return 0;
}
