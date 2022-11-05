#include <test.h>

Status BuildSBT(SqBiTree &T)
{
    if (IsIlleagl_SBT(T))
        return ERROR;
    int num = T.maxSize - 3, i;
    if (num <= 0)
        num = T.maxSize;
    if (T.maxSize >= 52)
        num = 40;

    T.lastIndex = num;

    for (i = 1; i <= 26 && num > 0; i++, num--)
        T.elem[i] = (char)('a' + i - 1);
    while (num > 0)
    {
        T.elem[i] = (char)('A' + i - 27);
        i++;
        num--;
    }
    return OK;
}

Status EditSBT(SqBiTree &T)
{
    system("cls");
    int choice = 0;
    while (1)
    {
        ShowSBT(T);
        printf("\n���༭�滻�ö�����:��\n");
        printf("0.�˳�\n");
        printf("1.��ʼ��������\n");
        printf("2.����������\n");
        printf("3.�ٽ�������ʵ��\n");
        printf("4.���ٶ�����\n");
        printf("5.�����½��\n");
        printf("6.ɾ��Ҷ�ӽ��\n");
        printf("7.�޸Ľ��\n");
        printf("8.ɾ��ָ������\n");

        fflush(stdin);
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            return OK;
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
            Test_DeleteSubTree(T);
            break;
        default:
            printf("ERROR:����ѡ��!\n");
            break;
        }
        system("pause");
        system("cls");
    }
}

void Test_InitSBT(SqBiTree &T)
{
    printf("\n��˳��洢����������:��ʼ����\n");

    int MaxDepth_SBT = 0;
    printf(">>�����������������\n");
    scanf("%d", &MaxDepth_SBT);
    printf(">>��Ҫ����%d����λԪ�صĿռ�!\n", CountMaxNum(MaxDepth_SBT));
    if (InitSBT(T, MaxDepth_SBT) == OK)
    {
        printf("OK:��ʼ���ɹ�!\n");
    }
    else
        printf("ERROR:��ʼ��ʧ��!\n");
}

void Test_ExtendSBT(SqBiTree &T)
{
    printf("\n��˳��洢����������:������\n");

    int extension = 0;
    printf(">>��������������\n");
    scanf("%d", &extension);
    if (extension > 0)
        printf(">>��Ҫ������%d����λԪ�صĿռ�!\n", CountMaxNum(extension + GetSBTMaxSizeDepth(T)) - CountMaxNum(GetSBTMaxSizeDepth(T)));
    else
        printf("ERROR:extensionֵ�쳣!\n");
    if (ExtendSBT(T, extension) == OK)
    {
        printf("OK:����%d��ɹ�!\n", extension);
    }
    else
        printf("ERROR:����%d��ʧ��!\n", extension);
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
        printf("ERROR:��%c��%c�������%cʧ��!�Ƿ���Ԫ���ظ��򳬳������ò���\n", par, tag, e);
}

void Test_DeleteSBTLeaf(SqBiTree &T)
{
    printf("\n��˳��洢����������:ɾ��Ҷ�ӽ�㡿\n");

    TElemType leaf;
    printf(">>������Ҫɾ����Ҷ�ӽ���ֵ:\n");
    fflush(stdin);
    scanf("%c", &leaf);
    if (DeleteSBTLeaf(T, leaf) == OK)
        printf("OK:ɾ��Ҷ�ӽ��%c�ɹ�!\n", leaf);
    else
        printf("ERROR:ɾ��Ҷ�ӽ��%cʧ��!\n", leaf);
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

void Test_ReplaceSBT(SqBiTree &T)
{
    int choice = 0;
    SqBiTree re;
    char tag = '#';
    printf("\n��˳��洢����������:�滻������\n");
    printf(">>�༭�滻����\n");
    printf("0.ȡ��\n");
    printf("1.ʹ��Ĭ������\n");
    printf("2.�Զ���\n");
    fflush(stdin);
    scanf("%d", &choice);
    switch (choice)
    {
    case 0:
        return;
    case 1:
        InitSBT(re, 2);
        InsertSBTNode(re, 'X', '#', '#');
        InsertSBTNode(re, 'Y', 'X', 'L');
        InsertSBTNode(re, 'Z', 'X', 'R');
        break;
    case 2:
        //�༭����������������
        EditSBT(re);
        break;
    default:
        printf("ERROR:��������!\n");
        break;
    }

    //ѡ����
    printf(">>������Ҫ�滻�ķ���:'L'��'R':\n");
    fflush(stdin);
    scanf("%c", &tag);

    //�滻
    if (ReplaceSBT(T, tag, re) == OK)
    {
        printf("OK:�ɹ��滻ԭ��%c����!\n", tag);
        printf(">>ԭ����״:\n");
        ShowSBT(T);
        printf(">>ԭ%c����:\n", tag);
        ShowSBT(re);
    }
    else
        printf("ERROR:�滻ԭ��%c����ʧ��!\n", tag);
    DestroySBT(re);
}

void Test_DeleteSubTree(SqBiTree &T)
{
    printf("\n��˳��洢����������:ɾ��ָ��������\n");
    TElemType x;
    printf(">>������Ҫɾ���������ĸ����ĵ�ֵ:\n");
    fflush(stdin);
    scanf("%c", &x);
    int x_i = SearchSBTNode(T, x);
    if (!IsIllegal_SBTNode(T, x_i))
    {
        DeleteSubTree(T, x_i);
        printf("OK:ɾ����%cΪ�����������ɹ�!", x);
    }
    else
        printf("ERROR:ɾ����%cΪ����������ʧ��!", x);
}

void Test_SearchSBTNode(SqBiTree T)
{
    printf("\n��˳��洢����������:���ҽ�㡿\n");

    TElemType e;
    int i;
    printf(">>������Ҫ���ҵĽ��ĵ�ֵ:\n");
    fflush(stdin);
    scanf("%c", &e);
    i = SearchSBTNode(T, e);
    if (i != 0)
        printf("OK:����ֵΪ%c�Ľ��ɹ�,�±�Ϊ%d\n", e, i);
    else
        printf("ERROR:����ֵΪ%c�Ľ��ʧ��!\n", e);
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
        printf("\n��˳��洢����������:������\n");
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
            if (PreTraverse(T, 1, VisitNode) == OK)
                printf("\nOK:��������ɹ�!\n");
            else
                printf("ERROR:�������ʧ��!\n");
            break;
        case 2:
            if (MidTraverse(T, 1, VisitNode) == OK)
                printf("\nOK:��������ɹ�!\n");
            else
                printf("ERROR:�������ʧ��!\n");
            break;
        case 3:
            if (PostTraverse(T, 1, VisitNode) == OK)
                printf("\nOK:��������ɹ�!\n");
            else
                printf("ERROR:�������ʧ��!\n");
            break;
        case 4:
            if (LevelTraverse(T, VisitNode) == OK)
                printf("\nOK:��α����ɹ�!\n");
            else
                printf("ERROR:��α���ʧ��!\n");
            break;
        default:
            printf("ERROR:����������!\n");
            break;
        }
        system("pause");
        system("cls");
    }
}

void Test_Is_Desendant(SqBiTree T)
{
    TElemType child, par;
    printf("\n��˳��洢����������:��ѯ�����ϵ��\n");
    printf(">>���������ѯ������:\n");
    fflush(stdin);
    scanf("%c", &par);
    printf(">>���������ѯ������:\n");
    fflush(stdin);
    scanf("%c", &child);
    int u = SearchSBTNode(T, par), v = SearchSBTNode(T, child);
    if (Is_Desendant(T, u, v) == TRUE)
        printf("TURE:���%c�ǽ��%c������\n", par, child);
    else
        printf("FALSE/ERROR:���%c���ǽ��%c������,����ڷǷ�ֵ!\n", par, child);
}

void Test_FindCommonAncestor(SqBiTree T)
{
    TElemType a, b;
    printf("\n��˳��洢����������:��ѯ�����ͬ���ȡ�\n");
    printf(">>���������ѯԪ��1:\n");
    fflush(stdin);
    scanf("%c", &a);
    printf(">>���������ѯԪ��2:\n");
    fflush(stdin);
    scanf("%c", &b);

    int anceI = FindCommonAncestor(T, SearchSBTNode(T, a), SearchSBTNode(T, b));
    if (anceI != 0)
        printf("OK:���%c����%c����Ĺ�ͬ����Ϊ:%c,�±�Ϊ:%d\n", a, b, T.elem[anceI], anceI);
    else
        printf("ERROR:��ѯ���%c����%c����Ĺ�ͬ����ʧ��!���ܴ��ڷǷ�ֵ!\n", a, b);
}