#include <SqBiTree.h>

void Test_InitSqBiTree(SqBiTree &T);
void Test_DestroySBT(SqBiTree &T);
void Test_InsertSBTNode(SqBiTree &T);
void Test_ModifySBTNode(SqBiTree &T);
Status BuildSBT(SqBiTree &T);

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
		printf("6.ɾ�����\n");
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
		default:
			printf("ERROR:����������!\n");
			break;
		}

		system("pause");
		system("cls");
	}
}

Status BuildSBT(SqBiTree &T)
{
	if (IsIlleagl_SBT(T))
		return ERROR;
	int num = T.maxSize - 3;
	for (int i = 1; i <= num; i++)
	{
		T.elem[i] = (char)('A' + i - 1);
	}
	T.lastIndex = num;
	printf("OK:�ɹ�����");
	return OK;
}

void Test_InitSqBiTree(SqBiTree &T)
{
	int MaxDepth_SBT = 0;
	printf(">>�����������������\n");
	scanf("%d", &MaxDepth_SBT);
	printf(">>��Ҫ����%d����λԪ�صĿռ�!\n", CountMaxNum(MaxDepth_SBT));
	if (InitSqBiTree(T, MaxDepth_SBT) == OK)
	{
		printf("OK:��ʼ���ɹ�!\n");
		ShowSBT(T);
	}
	else
		printf("ERROR:��ʼ��ʧ��!\n");
}

void Test_DestroySBT(SqBiTree &T)
{
	if (DestroySBT(T) == OK)
		printf("OK:���ٳɹ�!\n");
	else
		printf("ERROR:����ʧ��!�����ظ�����.\n");
}

void Test_InsertSBTNode(SqBiTree &T)
{
	TElemType e, par;
	char tag = '#';
	printf(">>������Ҫ������½���ֵ:\n");
	fflush(stdin);
	scanf("%c", &e);
	printf(">>������Ҫ����λ�õ�˫�׽���ֵ(��Ϊ�����������'#'):\n");
	fflush(stdin);
	scanf("%c", &par);
	printf(">>������Ҫ��%c�²���ķ���:'L'��'R'(��Ϊ�����������'#'):\n", par);
	fflush(stdin);
	scanf("%c", &tag);
	if (InsertSBTNode(T, e, par, tag) == OK)
		printf("OK:��%c��%c�������%c�ɹ�!\n", par, tag, e);
	else
		printf("ERROR:��%c��%c�������%cʧ��!�Ƿ���Ԫ�����ظ�\n", par, tag, e);
}

void Test_ModifySBTNode(SqBiTree &T)
{
	TElemType ori, e;
	printf(">>������Ҫ�޸ĵĽ��ĵ�ֵ:\n");
	fflush(stdin);
	scanf("%c", &ori);
	printf(">>�������޸ĺ����ֵ:\n");
	fflush(stdin);
	scanf("%c", &e);
	if (ModifySBTNode(T, ori, e) == OK)
		printf("OK:��ֵΪ%c�Ľ���ֵ�޸�Ϊ%c�ɹ�!\n", ori, e);
	else
		printf("ERROR:��ֵΪ%c�Ľ���ֵ�޸�Ϊ%cʧ��!\n", ori, e);
}