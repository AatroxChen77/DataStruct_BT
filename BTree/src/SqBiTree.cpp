#include <SqBiTree.h>

/**********************************************��������*******************************************************/
Status InitSqBiTree(SqBiTree &T, int depth)
{
    if (!IsIlleagl_SBT(T))
        DestroySBT(T);
    int maxNum = CountMaxNum(depth);
    T.elem = (TElemType *)malloc((maxNum + 1) * sizeof(TElemType));
    if (NULL == T.elem)
        return OVERFLOW;
    for (int i = 1; i <= maxNum; i++)
        T.elem[i] = '#';
    T.maxSize = maxNum;
    T.lastIndex = 0;
    return OK;
}

Status InsertSBTNode(SqBiTree &T, TElemType e, TElemType par, char tag)
{

    if (IsIlleagl_SBT(T) || 0 != SearchSBTNode(T, e) || tag != 'L' && tag != 'R' && tag != '#') //���Ƿ�||��������ֵΪe�Ľ��
        return ERROR;
    int p = 0, parIndex = 0;
    if (tag != '#')
    {
        parIndex = SearchSBTNode(T, par);
        if (parIndex == 0)
            return ERROR;
        if (tag == 'R')
            p = 2 * parIndex + 1;
        else
            p = 2 * parIndex;
    }
    else
        p = 1;

    if (p < 1 || p > T.maxSize || T.elem[p] != '#') // pԽ���p�����н��
        return ERROR;
    else
    {
        T.elem[p] = e;
        if (p > T.lastIndex)
            T.lastIndex = p;
    }

    return OK;
}

Status DestroySBT(SqBiTree &T)
{
    if (IsIlleagl_SBT(T))
        return ERROR;

    free(T.elem);
    T.elem = NULL;
    T.lastIndex = 0;
    T.maxSize = 0;

    return OK;
}

Status ModifySBTNode(SqBiTree &T, TElemType ori, TElemType e)
{
    if (IsIlleagl_SBT(T) || e == '#' || SearchSBTNode(T, e) != 0)
        return ERROR;
    int p = SearchSBTNode(T, ori);
    if (IsIllegal_SBTNode(T, p))
        return ERROR;
    else
        T.elem[p] = e;

    return OK;
}

Status BreakBiTree(SqBiTree &T, SqBiTree &L, SqBiTree &R)
{
}

/**********************************************��Ϣ��ȡ*******************************************************/

int CountMaxNum(int maxdepth) // 1 2 4 8
{
    int sum = 0;
    for (int i = 0; i < maxdepth; i++)
    {
        sum += pow(2, i);
    }
    return sum;
}

Status IsIlleagl_SBT(SqBiTree T)
{
    if (NULL == T.elem || T.maxSize <= 0 || T.lastIndex < 0 || T.lastIndex > T.maxSize)
        return TRUE;
    else
        return FALSE;
}

Status IsIllegal_SBTNode(SqBiTree T, int p)
{
    if (p < 1 || p > T.lastIndex || T.elem[p] == '#')
        return TRUE;
    else
        return FALSE;
}

Status Is_Desendant(SqBiTree T, int u, int v)
{
    if (IsIllegal_SBTNode(T, u) || IsIllegal_SBTNode(T, v) || v <= u)
        return FALSE; //��Χ������
    while (v > u)
    {
        v /= 2;
        if (v == u)
            return TRUE;
    }
    return FALSE;
}

int GetPar(int child, SqBiTree T)
{
    if (IsIllegal_SBTNode(T, child) || IsIllegal_SBTNode(T, child / 2))
        return 0;
    else
        return child / 2;
}

int GetLchild(int par, SqBiTree T)
{
    if (IsIllegal_SBTNode(T, par) || 2 * par > T.lastIndex || IsIllegal_SBTNode(T, 2 * par))
        return 0;
    else
        return 2 * par;
}

int GetRchild(int par, SqBiTree T)
{
    if (IsIllegal_SBTNode(T, par) || (2 * par + 1) > T.lastIndex || IsIllegal_SBTNode(T, 2 * par + 1))
        return 0;
    else
        return 2 * par + 1;
}

int SearchSBTNode(SqBiTree T, TElemType e)
{
    if (IsIlleagl_SBT(T))
        return 0;
    for (int i = 1; i <= T.lastIndex; i++)
    {
        if (e == T.elem[i])
            return i;
    }
    return 0;
}

/**********************************************��ӡ*******************************************************/

int GetSBTDepth(SqBiTree T)
{
    if (NULL == T.elem || T.lastIndex <= 0)
        return 0;
    return floor(log2(T.lastIndex)) + 1;
}

void ShowSBT(SqBiTree T)
{
    if (T.lastIndex == 0 || IsIlleagl_SBT(T))
    {
        printf("ERROR:��ӡʧ��!\n");
        return;
    }
    printf("OK:��������״����:\n");
    int depth = GetSBTDepth(T);
    int pos_x = pow(2, depth - 2) / 4 * 12 - 1; //��λ��
    int oriYpos = wherey();                     //���yԭʼλ��
    gotoxy(pos_x, wherey());
    PirntSBT(T, 1, depth);
    gotoxy(0, oriYpos + depth * 2); //���ص�����
}

void PirntSBT(SqBiTree T, int p, int depth)
{
    if (IsIllegal_SBTNode(T, p) || depth <= 0)
        return; //��������

    int distance = pow(2, depth - 2) * 12 / 4 - pow(2, depth - 3) * 12 / 4;
    if (1 == distance)
        distance = 2;

    int pos_x = wherex();                                 //��ǰ��xλ��
    int pos_y = wherey();                                 //��ǰ��yλ��
    int lpos = pos_x - distance, rpos = pos_x + distance; //��/��������λ��

    printf("%c", T.elem[p]); //����pirntBiTree֮ǰ�Ѿ������˸���λ�ã���wherex()

    int lchild = GetLchild(p, T);
    int rchild = GetRchild(p, T);

    if (!IsIllegal_SBTNode(T, lchild))
    {
        gotoxy(floor(double(pos_x + lpos) / 2), pos_y + 1);
        printf("/");
        gotoxy(lpos, pos_y + 2);
        PirntSBT(T, lchild, depth - 1);
    }

    if (!IsIllegal_SBTNode(T, rchild))
    {
        gotoxy(ceil(double(pos_x + rpos) / 2), pos_y + 1); // wherey()-2*farRightDepth+1
        printf("\\");
        gotoxy(rpos, pos_y + 2);
        PirntSBT(T, rchild, depth - 1);
    }
}
