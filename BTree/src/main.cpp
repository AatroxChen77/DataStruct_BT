#include <SqBiTree.h>
#include <test.h>

int main()
{
	SqBiTree T;
	int choice = 0;

	while (1)
	{

		ShowSBT(T);
		printf("\n【顺序存储二叉树测试系统】\n");
		printf("0.退出\n");
		printf("1.初始化二叉树\n");
		printf("2.扩建二叉树\n");
		printf("3.速建二叉树实例\n");
		printf("4.销毁二叉树\n");
		printf("5.插入新结点\n");
		printf("6.修改结点\n");
		printf("7.分解二叉树\n");
		printf("8.替代子树\n");
		printf("9.查找结点\n");
		printf("10.求各度数结点个数\n");
		printf("11.求某深度结点个数\n");
		printf("12.遍历\n");
		printf("13.查找最近共同祖先\n");
		printf(">>请输入相应操作的序号:\n");
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
				printf("OK:成功创建\n");
			else
				printf("ERROR:初始化失败!\n");
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
			printf("ERROR:请重新输入!\n");
			break;
		}

		system("pause");
		system("cls");
	}
}
