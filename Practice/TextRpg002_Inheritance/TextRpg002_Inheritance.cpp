#include <iostream>
#include <windows.h>

const int NAMELEN = 10;



class StatusUnit
{
protected:
    char Name[NAMELEN] = "NONE";
    int Hp = 100;
    int MinAtt = 10;
    int MaxAtt = 20;
    int Speed = 10;
    int Charm = 0;
};


class FightUnit : public StatusUnit
{
public:

    // MinMax
    int GetDamage() const
    {
         //minAtt ~ MaxAtt 사이의 숫자가 리턴되는 함수를 만드세요.
        int a = rand();
        int b = rand() % 10;
        int Attack = (rand() % (MaxAtt - MinAtt)) + MinAtt;
        return Attack;
    }

    void DamageLogic(const FightUnit& _AttUnit)
    {
        // _AttUnit => 나를 공격하려는 상대
        Hp -= _AttUnit.GetDamage();
    }

    void DamageRender(const char* const _AttName, int _Att)
    {
        printf_s("%s 가 %s를 공격해서 %d의 데미지를 입혔습니다.\n", _AttName, Name, _Att);
    }

    const char* GetName() const
    {
        return Name;
    }

protected:


private:
};

// 컴포넌트 방식이라는 것과 차이가 거의 없다.
// 보통 상속구조와 컴포넌트 기반구조가 게임의 로직계를 지배하고 있다.
// 

class Player : public FightUnit
{
};

class Monster : public FightUnit
{

};


// 게임을 만들다보면
// 일반적인 로직클래스 Player
// 리소스 클래스 <= 
// 데이터 전담클래스가 <= 내부에 변수밖에 없다. 
// 맴버변수도 public을 사용합니다.

int main()
{
    __int64 Time = time(0);
    srand(Time);

    Player NewPlayer;
    Monster NewMonster;
    
    while (true)
    { 
        //NewMonster.DamageLogic(NewPlayer);
        int Result = NewPlayer.GetDamage();
        printf_s("GetDamage : %d\n", Result);
        Sleep(500);
    }

    // NewPlayer.
}

