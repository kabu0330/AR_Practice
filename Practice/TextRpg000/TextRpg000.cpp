#include <iostream>
#include <conio.h>

// 전역변수
const int LINECOUNT = 50;
const int NAMELEN = 10;

int PlayerAtt = 0;
int PlayerHp = 0;
char PlayerName[NAMELEN] = "NONE";

int MonsterAtt = 10;
int MonsterHp = 100;
char MonsterName[NAMELEN] = "NONE";

char Input = ' ';


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



// 클래스의 필요성
// 함수는 다양한 상황에서 쓸수있게 만들수록 좋다.
// 함수는 작은 기능을 많이 만들고 
// 함수는 한번에 1가지 일을 할수록 좋다.
void Damage(const char* const _AttName, const char* const _DefName, int& _DefHp, int _Att)
{
    // 랜더링
    printf_s("%s 가 %s를 공격해서 %d의 데미지를 입혔습니다.\n", _AttName, _DefName, _Att);

}

void HpStatus(int _Att, int& _DefHp)
{
    // 게임 로직
    // 피격자 Hp - 공격자 Att
    _DefHp -= _Att;
}

void PrintStatus()
{
    system("cls");

    PlayerStatusRender();
    MonsterStatusRender();
}

void PrintPlayerAtt()
{
    HpStatus(PlayerAtt, MonsterHp);    
    system("cls");
    PrintStatus();
    Damage(PlayerName, MonsterName, MonsterHp, PlayerAtt);
}

void PrintMonsterAtt()
{
    HpStatus(MonsterAtt, PlayerHp);
    system("cls");
    PrintStatus();
    Damage(MonsterName, PlayerName, PlayerHp, MonsterAtt);
}




int main()
{
    // char Test0[100] = "Player";
    /*char Test1[50] = Test0;
    Test1 = Test0*/;

    CreatePlayer("TestPlayer", 10, 100);
    CreateMonster("Orc", 10, 50);
    

    //PlayerStatusRender();
    //MonsterStatusRender();

    //CreateMonster("Goblin", 15, 70);
    //MonsterStatusRender();

    //CreateMonster("Black Fairy", 20, 60); // 11자리 마지막 'y' 문자 생략
    //MonsterStatusRender();

    while (true)
    {
        PrintStatus();
        Input = _getch();
        PrintPlayerAtt();
        Input = _getch();
        PrintMonsterAtt();
        Input = _getch();

        //PrintStatus();
        //Damage(MonsterName, PlayerName, PlayerHp, MonsterAtt);
        //HpStatus(MonsterAtt, PlayerHp);
        //Input = _getch();

    }

    return 0;
}
