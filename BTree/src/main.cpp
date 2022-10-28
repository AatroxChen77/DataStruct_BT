#include <SqBiTree.h>
#include <test.h>

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
		printf("6.分解二叉树\n");
		printf("7.求各度数结点信息\n");
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
		case 6:
			Test_BreakBiTree(T);
			break;
		case 7:
			Test_getDegreeN(T);
			break;
		default:
			printf("ERROR:请重新输入!\n");
			break;
		}

		system("pause");
		system("cls");
	}
}
