#include <test.h>

Status BuildSBT(SqBiTree &T) // TODO:调整元素计算公式，使之只含字母
{
    if (IsIlleagl_SBT(T))
        return ERROR;
    int num = T.maxSize - 3, i;
    T.lastIndex = num;

    for (i = 1; i <= 26 && num > 0; i++, num--)
        T.elem[i] = (char)('a' + i - 1);
    for (; num > 0; i++, num--)
        T.elem[i] = (char)('A' + i - 27);

    return OK;
}

void Test_InitSqBiTree(SqBiTree &T)
{
    printf("\n【顺序存储二叉树测试:初始化】\n");

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
    printf("\n【顺序存储二叉树测试:销毁】\n");

    if (DestroySBT(T) == OK)
        printf("OK:销毁成功!\n");
    else
        printf("ERROR:销毁失败!请勿重复销毁.\n");
}

void Test_InsertSBTNode(SqBiTree &T)
{
    printf("\n【顺序存储二叉树测试:插入结点】\n");

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
    printf("\n【顺序存储二叉树测试:修改结点】\n");

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

void Test_BreakBiTree(SqBiTree &T)
{
    printf("\n【顺序存储二叉树测试:分解】\n");

    SqBiTree L, R;
    if (BreakBiTree(T, L, R) == OK)
    {
        printf("OK:分解成功!:\n");
        printf("根如下:\n");
        ShowSBT(T);
        printf("左子树如下:\n");
        ShowSBT(L);
        printf("右子树如下:\n");
        ShowSBT(R);
        DestroySBT(L);
        DestroySBT(R);
    }
    else
    {
        printf("ERROR:分解失败!\n");
    }
}

void Test_SearchSBTNode(SqBiTree T)
{
    printf("\n【顺序存储二叉树测试:查找结点】\n");

    TElemType e;
    int i;
    printf(">>请输入要查找的结点的的值:\n");
    fflush(stdin);
    scanf("%c", &e);
    i = SearchSBTNode(T, e);
    if (i != 0)
        printf("OK:查找值为%c的结点成功,下标为%d\n", e, i);
    else
        printf("ERROR:查找值为%c的结点失败!\n", e);
}

void Test_getDegreeN(SqBiTree T)
{
    printf("\n【顺序存储二叉树测试:获取各读度数结点个数】\n");

    printf("该二叉树度数为0的结点有:%d个\n", getDegreeZero(T));
    printf("该二叉树度数为1的结点有:%d个\n", getDegreeOne(T));
    printf("该二叉树度数为2的结点有:%d个\n", getDegreeTwo(T));
    printf("该二叉树总结点数有:%d个\n", T.lastIndex);
}

void Test_CountDepthNum(SqBiTree T)
{
    printf("\n【顺序存储二叉树测试:查询某深度结点个数】\n");

    int depth = 0;
    printf(">>请输入要查询的深度:\n");
    fflush(stdin);
    scanf("%d", &depth);
    printf("该二叉树在深度%d的结点个数为:%d个\n", depth, CountDepthNum(T, depth));
}

void Test_Traverse(SqBiTree T)
{

    system("cls");
    int choice = 0;
    while (1)
    {

        ShowSBT(T);
        printf("\n【顺序存储二叉树测试:初始化】\n");
        printf("0.返回\n");
        printf("1.先序遍历\n");
        printf("2.中序遍历\n");
        printf("3.后序遍历\n");
        printf("4.层次遍历\n");
        printf(">>请输入相应操作的序号:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            return;
            break;
        case 1:
            PreTraverse(T, 1, VisitNode);
            printf("\n");
            break;
        case 2:
            MidTraverse(T, 1, VisitNode);
            printf("\n");
            break;
        case 3:
            PostTraverse(T, 1, VisitNode);
            printf("\n");
            break;
        case 4:
            LevelTraverse(T, VisitNode);
            printf("\n");
            break;
        default:
            printf("ERROR:请重新输入!\n");
            break;
        }
        system("pause");
        system("cls");
    }
}