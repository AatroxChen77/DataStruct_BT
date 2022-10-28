#include <SqBiTree.h>
#include <test.h>

int main()
{
	SqBiTree T;

	while (1)
	{
		int choice = 0;
		ShowSBT(T);
		printf("\n��˳��洢����������ϵͳ��\n");
		printf("0.�˳�\n");
		printf("1.��ʼ��������\n");
		printf("2.���ٴ�������������\n");
		printf("3.���ٶ�����\n");
		printf("4.�����½��\n");
		printf("5.�޸Ľ��\n");
		printf("6.�ֽ������\n");
		printf("7.������������Ϣ\n");
		printf(">>��������Ӧ���������:\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 0:
			DestroySBT(T);
			exit(0);
			break;
		case 1:
			Test_InitSqBiTree(T);
			break;
		case 2:
			BuildSBT(T);
			break;
		case 3:
			Test_DestroySBT(T);
			break;
		case 4:
			Test_InsertSBTNode(T);
			break;
		case 5:
			Test_ModifySBTNode(T);
			break;
		case 6:
			Test_BreakBiTree(T);
			break;
		case 7:
			Test_getDegreeN(T);
			break;
		default:
			printf("ERROR:����������!\n");
			break;
		}

		system("pause");
		system("cls");
	}
}
