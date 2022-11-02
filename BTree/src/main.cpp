#include <SqBiTree.h>
#include <test.h>

int main()
{
	SqBiTree T;
	int choice = 0;

	printf("��������Ϣ��\n");
	printf(">ѧԺ:�����ѧԺ\n>רҵ:�������ѧ�뼼��\n");
	printf(">�༶:21�����˰�\n>����:�����\n>ѧ��:3121004647\n");
	printf(">���ʱ��:2022��11��2��\n");
	printf("\n��ע�����\n");
	printf("1.ʹ��˳��洢�ṹ�洢������\n");
	printf("2.�������ظ�Ԫ�ش���\n");
	system("pause");
	system("cls");

	while (1)
	{

		ShowSBT(T);
		printf("\n��˳��洢����������ϵͳ��\n");
		printf("0.�˳�\n");
		printf("һ���ṹ�����:\n");
		printf("1.��ʼ��������\t\t2.����������\t\t3.�ٽ�������ʵ��\n");
		printf("4.���ٶ�����\t\t5.�����½��\t\t6.ɾ��Ҷ�ӽ��\n");
		printf("7.�޸Ľ��\t\t8.�ֽ������\t\t9.�������\n");
		printf("10.ɾ��ָ������\n");
		printf("������ѯ�����:\n");
		printf("11.���ҽ��\t\t12.�������������\t13.��ĳ��Ƚ�����\n");
		printf("14.����\t\t\t15.�ж������ϵ\t\t16.��ѯ�����ͬ����\n");
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
			Test_DeleteSBTLeaf(T);
			break;
		case 7:
			Test_ModifySBTNode(T);
			break;
		case 8:
			Test_BreakBiTree(T);
			break;
		case 9:
			Test_ReplaceSBT(T);
			break;
		case 10:
			Test_DeleteSubTree(T);
			break;
		case 11:
			Test_SearchSBTNode(T);
			break;
		case 12:
			Test_getDegreeN(T);
			break;
		case 13:
			Test_CountDepthNum(T);
			break;
		case 14:
			Test_Traverse(T);
			break;
		case 15:
			Test_Is_Desendant(T);
			break;
		case 16:
			Test_FindCommonAncestor(T);
			break;
		default:
			printf("ERROR:����������!\n");
			break;
		}

		system("pause");
		system("cls");
	}
}
