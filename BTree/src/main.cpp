#include <SqBiTree.h>
#include <test.h>

int main()
{
	SqBiTree T;
	int choice = 0;

	printf("【个人信息】\n");
	printf(">学院:计算机学院\n>专业:计算机科学与技术\n");
	printf(">班级:21级伏羲班\n>姓名:陈以韬\n>学号:3121004647\n");
	printf(">完成时间:2022年11月2日\n");
	printf("\n【注意事项】\n");
	printf("1.使用顺序存储结构存储二叉树\n");
	printf("2.不允许重复元素存在\n");
	system("pause");
	system("cls");

	while (1)
	{

		ShowSBT(T);
		printf("\n【顺序存储二叉树测试系统】\n");
		printf("0.退出\n");
		printf("一、结构类操作:\n");
		printf("1.初始化二叉树\t\t2.扩建二叉树\t\t3.速建二叉树实例\n");
		printf("4.销毁二叉树\t\t5.插入新结点\t\t6.删除叶子结点\n");
		printf("7.修改结点\t\t8.分解二叉树\t\t9.替代子树\n");
		printf("10.删除指定子树\n");
		printf("二、查询类操作:\n");
		printf("11.查找结点\t\t12.求各度数结点个数\t13.求某深度结点个数\n");
		printf("14.遍历\t\t\t15.判断子孙关系\t\t16.查询最近共同祖先\n");
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
			printf("ERROR:请重新输入!\n");
			break;
		}

		system("pause");
		system("cls");
	}
}
