#include "BlackSmith.h"
#include "Player.h"
#include <BaseSystem/EngineDebug.h>
#include <conio.h>


void BlackSmith::InPlayer(class UPlayer& _Player/*, int& Result*/)
{
	if (nullptr == ParentZone)
	{
		MSGASSERT("�θ����� ���õ��� �ʾҽ��ϴ�");
		return;
	}

	_Player.SetGold(1000000);

	srand(time(nullptr));

	while (true)
	{
		CurSuccessRate(_Player);

		system("cls");
		_Player.StatusRender();
		std::cout << "���� ��ȭ �ܰ� : " << _Player.GetEquipLevel() << "��" << std::endl;
		std::cout << "��ȭ ���� Ȯ�� : " << SuccessRate << "%" << std::endl;
		std::cout << "��ȭ ���� Ȯ�� : " << 100 - SuccessRate << "%" << std::endl;
		std::cout << "�Һ� ��� : " << cost << std::endl;
		std::cout << std::endl;
		std::cout << "1. ��ȭ\n";
		std::cout << "2. ������\n";
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
		std::cout << "�� �̻� ��ȭ�Ͻ� �� �����ϴ�." << std::endl;
		_getch();
		return;
	}

	// Ȯ���� ���δ� 2���� 1
	int Result = rand() % 100;
	// 1���� �𿩾� �Ѵ�. �÷��̾��� ��ȭ �ܰ� * 100
	// ���� ���� 5���� �����ϰ� �ִ�. �׷��� 500���� �￩�� �Ѵ�.

	int balance = _Player.GetGold() - cost;
	_Player.SetGold(balance);

	// 1~5������ ���а� ����Ȯ���� ������.
	// �ٿ������ �ʴ´�.
	if (Result >= (100 - SuccessRate))
	{
		std::cout << "��ȭ�� �����ϼ̽��ϴ�." << std::endl;
		int EquipLevel = _Player.GetEquipLevel() + 1;
		_Player.SetEquipLevel(EquipLevel);
		int PlusAtt = _Player.GetEquipAtt() + 5;
		_Player.SetEquipAtt(PlusAtt);
	}
	else
	{
		std::cout << "��ȭ�� �����ϼ̽��ϴ�." << std::endl;
		if (_Player.GetEquipLevel() >= 6)
		{
			std::cout << "��� ��ȭ ����� �϶��߽��ϴ�." << std::endl;
			int EquipLevel = _Player.GetEquipLevel() - 1;
			_Player.SetEquipLevel(EquipLevel);
			int MinusAtt = _Player.GetEquipAtt() - 5;
			_Player.SetEquipAtt(MinusAtt);
		}
	}
	_getch();
	// 6~10������ �����ϸ� 1�� �ٿ�ȴ�.
	// 10~15�� 0���� �����ϸ� 0���� ��������.
	// 15�� �̻��̸� ��ȭ�� ���ϰ� �ؾ����Ѵ�.
}

void BlackSmith::CurSuccessRate(class UPlayer& _Player)
{
	SuccessRate = 100 - (5 * _Player.GetEquipLevel());
	cost = 100 + (_Player.GetEquipLevel() * 100);
}


