//============================================================
//
//  title  : �f�[�^�\�� [main.cpp]
//  Author : ���c �z��
//   Date  : 2021/10/04
//  Update : 2021/10/06
//
//============================================================
#include "list.h"
#include "queue.h"


//============================================================
//�@�֐�
//============================================================
//------------------------------------------------------------
//�@���C���֐�
//------------------------------------------------------------
int main(void)
{
	// �v�f��ǉ�
	Queue::Enqueue(0, "Tanaka");
	Queue::Enqueue(1, "Satou");
	Queue::Enqueue(2, "Kobayashi");
	Queue::Enqueue(3, "Kishida");
	Queue::Enqueue(4, "Shimamura");
	Queue::Enqueue(5, "Suga");
	// �f�[�^���ꗗ�\��
	Queue::Disp();
	// ���s�p
	std::cout << "" << endl;


	// �P���
	// �v�f�����o��
	Queue::Dequeue();
	std::cout << "" << endl;
	// �f�[�^���ēx�ꗗ�\��
	Queue::Disp();
	// ���s�p
	std::cout << "" << endl;


	// �Q���
	// �v�f�����o��
	Queue::Dequeue();
	std::cout << "" << endl;
	// �f�[�^���ēx�ꗗ�\��
	Queue::Disp();
}
