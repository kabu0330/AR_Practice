#include "Player.h"
#include <iostream>

// #CPP������ #include�� �ƹ��� �����ص� ��ȯ������ ���� ���ص� �ȴ�.
// �׷��� ������ �ִ�. ���尡 ���� �ɸ���.
// obj���ϸ��� #include�� 


// �ɹ��Լ� ���� ����
UPlayer::UPlayer()
{
	// std::cout << "�÷��̾� ������" << std::endl;
}

void UPlayer::PrintAtt()
{
    printf_s("���ݷ� : %d ~ %d + %d\n", MinAtt, MaxAtt, EquipAtt);
}


// �ɹ��Լ��� �����Ҵ�� �̷��� �׳� �����Լ���.
// ��Ȯ�� �̸��� �������� �Ѵ�.
// � Ŭ������ ���Ѱ��� �������� �Ѵ�.
void UPlayer::Equip(class Item* Weapon)
{

}
