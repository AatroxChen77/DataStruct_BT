#include <test.h>

Status BuildSBT(SqBiTree &T) // TODO:����Ԫ�ؼ��㹫ʽ��ʹֻ֮����ĸ
{
    if (IsIlleagl_SBT(T))
        return ERROR;
    int num = T.maxSize - 3;
    TElemType e;
    for (int i = 1; i <= num; i++)
    {
        e = (char)('a' + i - 1);
        T.elem[i] = e;
    }
    T.lastIndex = num;
    return OK;
}

void Test_InitSqBiTree(SqBiTree &T)
{
    printf("\n��˳��洢����������:��ʼ����\n");

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
    printf("\n��˳��洢����������:���١�\n");

    if (DestroySBT(T) == OK)
        printf("OK:���ٳɹ�!\n");
    else
        printf("ERROR:����ʧ��!�����ظ�����.\n");
}

void Test_InsertSBTNode(SqBiTree &T)
{
    printf("\n��˳��洢����������:�����㡿\n");

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
    printf("\n��˳��洢����������:�޸Ľ�㡿\n");

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

void Test_BreakBiTree(SqBiTree &T)
{
    printf("\n��˳��洢����������:�ֽ⡿\n");

    SqBiTree L, R;
    if (BreakBiTree(T, L, R) == OK)
    {
        printf("OK:�ֽ�ɹ�!:\n");
        printf("������:\n");
        ShowSBT(T);
        printf("����������:\n");
        ShowSBT(L);
        printf("����������:\n");
        ShowSBT(R);
        DestroySBT(L);
        DestroySBT(R);
    }
    else
    {
        printf("ERROR:�ֽ�ʧ��!\n");
    }
}

void Test_getDegreeN(SqBiTree T)
{
    printf("\n��˳��洢����������:��ȡ����������������\n");

    printf("�ö���������Ϊ0�Ľ����:%d��\n", getDegreeZero(T));
    printf("�ö���������Ϊ1�Ľ����:%d��\n", getDegreeOne(T));
    printf("�ö���������Ϊ2�Ľ����:%d��\n", getDegreeTwo(T));
    printf("�ö������ܽ������:%d��\n", T.lastIndex);
}

void Test_CountDepthNum(SqBiTree T)
{
    printf("\n��˳��洢����������:��ѯĳ��Ƚ�������\n");

    int depth = 0;
    printf(">>������Ҫ��ѯ�����:\n");
    fflush(stdin);
    scanf("%d", &depth);
    printf("�ö����������%d�Ľ�����Ϊ:%d��\n", depth, CountDepthNum(T, depth));
}

void Test_Traverse(SqBiTree T)
{

    system("cls");
    int choice = 0;
    while (1)
    {

        ShowSBT(T);
        printf("\n��˳��洢����������:��ʼ����\n");
        printf("0.����\n");
        printf("1.�������\n");
        printf("2.�������\n");
        printf("3.�������\n");
        printf("4.��α���\n");
        printf(">>��������Ӧ���������:\n");
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
            printf("ERROR:����������!\n");
            break;
        }
        system("pause");
        system("cls");
    }
}