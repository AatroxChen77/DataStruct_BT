#include <SqBiTree.h>
#include <test.h>

int main()
{
	SqBiTree T;
	int choice = 0;

	while (1)
	{

		ShowSBT(T);
		printf("\n��˳��洢����������ϵͳ��\n");
		printf("0.�˳�\n");
		printf("1.��ʼ��������\n");
		printf("2.����������\n");
		printf("3.�ٽ�������ʵ��\n");
		printf("4.���ٶ�����\n");
		printf("5.�����½��\n");
		printf("6.�޸Ľ��\n");
		printf("7.�ֽ������\n");
		printf("8.�������\n");
		printf("9.���ҽ��\n");
		printf("10.�������������\n");
		printf("11.��ĳ��Ƚ�����\n");
		printf("12.����\n");
		printf("13.���������ͬ����\n");
		printf(">>��������Ӧ���������:\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 0:
			DestroySBT(T);
			exit(0);
			break;
		case 1:
			Test_InitSBT(T);
			break;
		case 2:
			Test_ExtendSBT(T);
			break;
		case 3:
			if (BuildSBT(T) == OK)
				printf("OK:�ɹ�����\n");
			else
				printf("ERROR:��ʼ��ʧ��!\n");
			break;
		case 4:
			Test_DestroySBT(T);
			break;
		case 5:
			Test_InsertSBTNode(T);
			break;
		case 6:
			Test_ModifySBTNode(T);
			break;
		case 7:
			Test_BreakBiTree(T);
			break;
		case 8:
			// Test_ReplaceSBT(T);
			break;
		case 9:
			Test_SearchSBTNode(T);
			break;
		case 10:
			Test_getDegreeN(T);
			break;
		case 11:
			Test_CountDepthNum(T);
			break;
		case 12:
			Test_Traverse(T);
			break;
		case 13:
			// Test_Find(T);
			break;
		default:
			printf("ERROR:����������!\n");
			break;
		}

		system("pause");
		system("cls");
	}
}
