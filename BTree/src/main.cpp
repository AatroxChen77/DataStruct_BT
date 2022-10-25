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
		printf("\n【顺序存储二叉树测试系统】\n");
		printf("0.退出\n");
		printf("1.初始化二叉树\n");
		printf("2.快速创建二叉树例子\n");
		printf("3.销毁二叉树\n");
		printf("4.插入新结点\n");
		printf("5.修改结点\n");
		printf("6.删除结点\n");
		printf(">>请输入相应操作的序号:\n");
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
			printf("ERROR:请重新输入!\n");
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
	printf("OK:成功创建");
	return OK;
}

void Test_InitSqBiTree(SqBiTree &T)
{
	int MaxDepth_SBT = 0;
	printf(">>请输入二叉树最大层数\n");
	scanf("%d", &MaxDepth_SBT);
	printf(">>需要申请%d个单位元素的空间!\n", CountMaxNum(MaxDepth_SBT));
	if (InitSqBiTree(T, MaxDepth_SBT) == OK)
	{
		printf("OK:初始化成功!\n");
		ShowSBT(T);
	}
	else
		printf("ERROR:初始化失败!\n");
}

void Test_DestroySBT(SqBiTree &T)
{
	if (DestroySBT(T) == OK)
		printf("OK:销毁成功!\n");
	else
		printf("ERROR:销毁失败!请勿重复销毁.\n");
}

void Test_InsertSBTNode(SqBiTree &T)
{
	TElemType e, par;
	char tag = '#';
	printf(">>请输入要插入的新结点的值:\n");
	fflush(stdin);
	scanf("%c", &e);
	printf(">>请输入要插入位置的双亲结点的值(若为根结点请输入'#'):\n");
	fflush(stdin);
	scanf("%c", &par);
	printf(">>请输入要在%c下插入的方向:'L'或'R'(若为根结点请输入'#'):\n", par);
	fflush(stdin);
	scanf("%c", &tag);
	if (InsertSBTNode(T, e, par, tag) == OK)
		printf("OK:在%c下%c方向插入%c成功!\n", par, tag, e);
	else
		printf("ERROR:在%c下%c方向插入%c失败!非法或元素已重复\n", par, tag, e);
}

void Test_ModifySBTNode(SqBiTree &T)
{
	TElemType ori, e;
	printf(">>请输入要修改的结点的的值:\n");
	fflush(stdin);
	scanf("%c", &ori);
	printf(">>请输入修改后结点的值:\n");
	fflush(stdin);
	scanf("%c", &e);
	if (ModifySBTNode(T, ori, e) == OK)
		printf("OK:把值为%c的结点的值修改为%c成功!\n", ori, e);
	else
		printf("ERROR:把值为%c的结点的值修改为%c失败!\n", ori, e);
}