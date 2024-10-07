#include "BlackSmith.h"
#include "Player.h"
#include <BaseSystem/EngineDebug.h>
#include <conio.h>


void BlackSmith::InPlayer(class UPlayer& _Player/*, int& Result*/)
{
	if (nullptr == ParentZone)
	{
		MSGASSERT("부모존이 세팅되지 않았습니다");
		return;
	}

	_Player.SetGold(1000000);

	srand(time(nullptr));

	while (true)
	{
		CurSuccessRate(_Player);

		system("cls");
		_Player.StatusRender();
		std::cout << "현재 강화 단계 : " << _Player.GetEquipLevel() << "강" << std::endl;
		std::cout << "강화 성공 확률 : " << SuccessRate << "%" << std::endl;
		std::cout << "강화 실패 확률 : " << 100 - SuccessRate << "%" << std::endl;
		std::cout << "소비 골드 : " << cost << std::endl;
		std::cout << std::endl;
		std::cout << "1. 강화\n";
		std::cout << "2. 나간다\n";
		int Select = _getch();
		switch (Select)
		{
		case '1':
		{
			EquipEnhancement(_Player);
			break;
		}
		case '2':
			return;
		default:
			break;
		}
	}
}

void BlackSmith::EquipEnhancement(class UPlayer& _Player)
{
	if (15 == _Player.GetEquipLevel())
	{
		std::cout << "더 이상 강화하실 수 없습니다." << std::endl;
		_getch();
		return;
	}

	// 확률은 전부다 2분의 1
	int Result = rand() % 100;
	// 1돈이 깎여야 한다. 플레이어의 강화 단계 * 100
	// 내가 현재 5강에 도전하고 있다. 그러면 500원씩 깍여야 한다.

	int balance = _Player.GetGold() - cost;
	_Player.SetGold(balance);

	// 1~5까지는 실패가 실패확률은 있지만.
	// 다운되지는 않는다.
	if (Result >= (100 - SuccessRate))
	{
		std::cout << "강화에 성공하셨습니다." << std::endl;
		int EquipLevel = _Player.GetEquipLevel() + 1;
		_Player.SetEquipLevel(EquipLevel);
		int PlusAtt = _Player.GetEquipAtt() + 5;
		_Player.SetEquipAtt(PlusAtt);
	}
	else
	{
		std::cout << "강화에 실패하셨습니다." << std::endl;
		if (_Player.GetEquipLevel() >= 6)
		{
			std::cout << "장비 강화 등급이 하락했습니다." << std::endl;
			int EquipLevel = _Player.GetEquipLevel() - 1;
			_Player.SetEquipLevel(EquipLevel);
			int MinusAtt = _Player.GetEquipAtt() - 5;
			_Player.SetEquipAtt(MinusAtt);
		}
	}
	_getch();
	// 6~10까지는 실패하면 1씩 다운된다.
	// 10~15는 0으로 실패하면 0으로 떨어진다.
	// 15강 이상이면 강화를 못하게 해야해한다.
}

void BlackSmith::CurSuccessRate(class UPlayer& _Player)
{
	SuccessRate = 100 - (5 * _Player.GetEquipLevel());
	cost = 100 + (_Player.GetEquipLevel() * 100);
}


