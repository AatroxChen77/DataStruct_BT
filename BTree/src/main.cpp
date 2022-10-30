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
		printf("2.速建二叉树实例\n");
		printf("3.销毁二叉树\n");
		printf("4.插入新结点\n");
		printf("5.修改结点\n");
		printf("6.分解二叉树\n");
		printf("7.查找结点\n");
		printf("8.求各度数结点个数\n");
		printf("9.求某深度结点个数\n");
		printf("10.遍历\n");
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
			if (BuildSBT(T) == OK)
				printf("OK:成功创建\n");
			else
				printf("ERROR:初始化失败!\n");
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
			Test_SearchSBTNode(T);
			break;
		case 8:
			Test_getDegreeN(T);
			break;
		case 9:
			Test_CountDepthNum(T);
			break;
		case 10:
			Test_Traverse(T);
			break;
		default:
			printf("ERROR:请重新输入!\n");
			break;
		}

		system("pause");
		system("cls");
	}
}
