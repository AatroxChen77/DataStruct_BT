#include <SqBiTree.h>

/**********************************************基本操作*******************************************************/
Status InitSBT(SqBiTree &T, int depth)
{
    //参数检查
    if (depth <= 0 || depth > MAXLEVEL)
        return ERROR;
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

Status ExtendSBT(SqBiTree &T, int extension)
{
    //参数检查
    if (IsIlleagl_SBT(T) || extension <= 0 || (extension + GetSBTMaxSizeDepth(T)) > MAXLEVEL)
        return ERROR;

    int maxNum = CountMaxNum(GetSBTMaxSizeDepth(T) + extension);
    TElemType *temp = (TElemType *)realloc(T.elem, (maxNum + 1) * sizeof(TElemType));
    if (NULL == temp)
        return OVERFLOW;
    T.elem = temp;
    for (int i = T.maxSize + 1; i <= maxNum; i++)
        //扩建部分赋空
        T.elem[i] = '#';
    T.maxSize = maxNum;
    return OK;
}

Status InsertSBTNode(SqBiTree &T, TElemType e, TElemType par, char tag)
{
    //参数检查
    if (IsIlleagl_SBT(T) || e == '#' || 0 != SearchSBTNode(T, e) || tag != 'L' && tag != 'R' && tag != '#')
        //树非法|树中已有值为e的结点|tag值非法
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

    if (p < 1 || p > T.maxSize || T.elem[p] != '#') // p越界或p处已有结点
        return ERROR;
    else
    {
        T.elem[p] = e;
        if (p > T.lastIndex)
            T.lastIndex = p;
    }

    return OK;
}

Status DeleteSBTLeaf(SqBiTree &T, TElemType leaf)
{
    //参数检查
    if (IsIlleagl_SBT(T))
        return ERROR;
    int leafIndex = SearchSBTNode(T, leaf);
    if (IsIllegal_SBTNode(T, leafIndex) || GetRchild(T, leafIndex) != 0 || GetLchild(T, leafIndex) != 0)
        return ERROR;
    T.elem[leafIndex] = '#';
    if (leafIndex == T.lastIndex)
        T.lastIndex = getLastIndex(T);
    return OK;
}

Status DestroySBT(SqBiTree &T)
{
    //参数检查
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
    //参数检查
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
    //参数检查
    int depthT = GetSBTDepth(T);
    if (depthT <= 1)
        return ERROR;
    InitSBT(L, depthT - 1);
    InitSBT(R, depthT - 1);
    if (IsIlleagl_SBT(T) || IsIlleagl_SBT(R) || IsIlleagl_SBT(L))
    {
        DestroySBT(L);
        DestroySBT(R);
        return ERROR;
    }

    for (int i = 1, num = 0; i < GetSBTDepth(T); i++)
    {
        num = pow(2, i); //每一层的节点数量
        memcpy(L.elem + num / 2, T.elem + num, num / 2 * sizeof(TElemType));
        memcpy(R.elem + num / 2, T.elem + num + num / 2, num / 2 * sizeof(TElemType));
    }
    //重新计算lastIndex
    T.lastIndex = 1; //分解剩下根
    L.lastIndex = getLastIndex(L);
    R.lastIndex = getLastIndex(R);
    return OK;
}

Status isInSubTree(SqBiTree T, char tag, int p)
{
    if (IsIlleagl_SBT(T) || IsIllegal_SBTNode(T, p) || tag != 'L' && tag != 'R')
        //不在T中
        return FALSE;
    int dep = (int)(floor(log2(p)) + 1); // p所在层次
    int R_line = pow(2, dep - 1) / 2 + pow(2, dep - 1);
    if (tag == 'L' && p < R_line || tag == 'R' && p >= R_line)
        return TRUE;
    else
        return FALSE;
}

Status ReplaceSBT(SqBiTree &T, char tag, SqBiTree &re)
{
    //参数检查
    if (IsIlleagl_SBT(T) || T.lastIndex == 0 || IsIlleagl_SBT(re) || re.lastIndex == 0 || tag != 'L' && tag != 'R' && tag != '#')
        //原树或替换用树异常|tag值非法
        return ERROR;

    for (int i = 1, p = 0; i <= re.lastIndex; i++)
    { //重复性检查
        p = SearchSBTNode(T, re.elem[i]);
        //重复性判断范围：除了被替换子树以外的其他元素
        if (p != 0 && !isInSubTree(T, tag, p))
            return ERROR;
    }

    int dep_re = GetSBTMaxSizeDepth(re);
    int ext = dep_re - (GetSBTMaxSizeDepth(T) - 1);
    if (ext > 0)
    { //替换后树深度超出原树最大可用深度,扩建
        if (ExtendSBT(T, ext) == ERROR)
            return ERROR;
    }
    else if (ext < 0)
    { // re原深度不足返回被替换子树
        if (ExtendSBT(re, -ext) == ERROR)
            return ERROR;
    }

    // re和T的被替换子树可用大小一致,逐一交换即可

    int dep_i = 0, j = 0;
    for (int i = 1; i <= re.maxSize; i++)
    {
        dep_i = (int)(floor(log2(i)) + 1);
        j = i + pow(2, dep_i - 1);
        if (tag == 'R')
        { //替换=右子树
            j += pow(2, dep_i - 1);
        }
        swap(re.elem[i], T.elem[j]);
    }
    T.lastIndex = getLastIndex(T);
    re.lastIndex = getLastIndex(re);

    return OK;
}

Status DeleteSubTree(SqBiTree &T, int x)
{
    //参数检查
    if (IsIlleagl_SBT(T) || IsIllegal_SBTNode(T, x))
        return ERROR;
    //递归函数
    DeleteSubTree_recur(T, x);
    //重新计算最后结点的下标
    T.lastIndex = getLastIndex(T);
    return OK;
}

Status DeleteSubTree_recur(SqBiTree &T, int x)
{
    //参数检查
    if (IsIllegal_SBTNode(T, x))
        return OK;
    //删除当前根节点
    T.elem[x] = '#';
    //获取左右子树的根下标
    int l = 2 * x, r = 2 * x + 1;
    //删除左右子树
    DeleteSubTree_recur(T, l);
    DeleteSubTree_recur(T, r);
    return OK;
}

/**********************************************信息获取*******************************************************/

int CountMaxNum(int maxdepth) // 1 2 4 8
{
    //参数检查
    if (maxdepth < 1)
        return 0;
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
    if (IsIlleagl_SBT(T))
        return ERROR;
    if (IsIllegal_SBTNode(T, u) || IsIllegal_SBTNode(T, v) || v <= u)
        return FALSE; //范围不合理
    while (v > u)
    {
        v = GetPar(T, v);
        if (v == u)
            return TRUE;
    }
    return FALSE;
}

int GetPar(SqBiTree T, int child)
{
    if (IsIllegal_SBTNode(T, child) || IsIllegal_SBTNode(T, child / 2))
        return 0;
    else
        return child / 2;
}

int GetLchild(SqBiTree T, int par)
{
    if (IsIllegal_SBTNode(T, par) || 2 * par > T.lastIndex || IsIllegal_SBTNode(T, 2 * par))
        return 0;
    else
        return 2 * par;
}

int GetRchild(SqBiTree T, int par)
{
    if (IsIllegal_SBTNode(T, par) || (2 * par + 1) > T.lastIndex || IsIllegal_SBTNode(T, 2 * par + 1))
        return 0;
    else
        return 2 * par + 1;
}

int SearchSBTNode(SqBiTree T, TElemType e)
{
    if (IsIlleagl_SBT(T) || e == '#')
        return 0;
    for (int i = 1; i <= T.lastIndex; i++)
    {
        if (e == T.elem[i])
            return i;
    }
    return 0;
}

int getLastIndex(SqBiTree T)
{
    if (IsIlleagl_SBT(T))
        return 0;
    for (int i = T.maxSize; i > 0; i--)
    { //从数组后往前遍历，第一个不为空的就是最后元素
        if (T.elem[i] != '#')
            return i;
    }
    return 0; //若都为空，即二叉树为空，返回0
}

int getDegreeZero(SqBiTree T)
{
    if (IsIlleagl_SBT(T))
        return 0;
    int num = 0;
    for (int i = 1; i <= T.lastIndex; i++)
    {
        //叶子结点即没有左右子树的结点，此时其左右孩子的下标应返回0
        if (GetLchild(T, i) == 0 && GetRchild(T, i) == 0)
            num++;
    }
    return num;
}

int getDegreeOne(SqBiTree T)
{
    if (IsIlleagl_SBT(T))
        return 0;
    int num = 0;
    int l = 0, r = 0;
    for (int i = 1; i <= T.lastIndex; i++)
    {
        l = GetLchild(T, i);
        r = GetRchild(T, i);
        //度数为1的节点即有且仅有一个子树
        if (l == 0 && r != 0 || r == 0 && l != 0)
            num++;
    }
    return num;
}

int getDegreeTwo(SqBiTree T)
{
    if (IsIlleagl_SBT(T))
        return 0;
    int num = 0;
    int l = 0, r = 0;
    for (int i = 1; i <= T.lastIndex; i++)
    {
        l = GetLchild(T, i);
        r = GetRchild(T, i);
        //度数为1的节点即有且仅有一个子树
        if (l != 0 && r != 0)
            num++;
    }
    return num;
}

int CountDepthNum(SqBiTree T, int depth)
{
    //参数检查
    if (IsIlleagl_SBT(T) || depth < 1)
        return 0;
    int begin = pow(2, depth - 1), end = pow(2, depth) - 1, sum = 0;
    for (int i = begin; i <= end; i++)
    {
        if (!IsIllegal_SBTNode(T, i))
            sum++;
    }
    return sum;
}

Status PreTraverse(SqBiTree T, int root, Status (*visit)(SqBiTree T, int p))
{
    //参数检查
    if (IsIlleagl_SBT(T) || T.lastIndex < 1 || IsIllegal_SBTNode(T, root) || NULL == visit)
        return ERROR;
    int lChild = GetLchild(T, root);
    int rChild = GetRchild(T, root);
    visit(T, root);
    PreTraverse(T, lChild, visit);
    PreTraverse(T, rChild, visit);
    return OK;
}

Status MidTraverse(SqBiTree T, int root, Status (*visit)(SqBiTree T, int p))
{
    //参数检查
    if (IsIlleagl_SBT(T) || T.lastIndex < 1 || IsIllegal_SBTNode(T, root) || NULL == visit)
        return ERROR;
    int lChild = GetLchild(T, root);
    int rChild = GetRchild(T, root);
    MidTraverse(T, lChild, visit);
    visit(T, root);
    MidTraverse(T, rChild, visit);
    return OK;
}

Status PostTraverse(SqBiTree T, int root, Status (*visit)(SqBiTree T, int p))
{
    //参数检查
    if (IsIlleagl_SBT(T) || T.lastIndex < 1 || IsIllegal_SBTNode(T, root) || NULL == visit)
        return ERROR;
    int lChild = GetLchild(T, root);
    int rChild = GetRchild(T, root);
    PostTraverse(T, lChild, visit);
    PostTraverse(T, rChild, visit);
    visit(T, root);
    return OK;
}

Status LevelTraverse(SqBiTree T, Status (*visit)(SqBiTree T, int p))
{
    //参数检查
    if (IsIlleagl_SBT(T) || T.lastIndex < 1 || NULL == visit)
        return ERROR;
    for (int i = 1; i <= T.lastIndex; i++)
    {
        if (!IsIllegal_SBTNode(T, i))
            visit(T, i);
    }
    return OK;
}

Status VisitNode(SqBiTree T, int p)
{
    //参数检查
    if (IsIlleagl_SBT(T) || IsIllegal_SBTNode(T, p))
        return ERROR;
    printf("%c|", T.elem[p]);
    return OK;
}

int FindCommonAncestor(SqBiTree T, int a, int b)
{
    //参数检查
    if (a == b || IsIlleagl_SBT(T) || IsIllegal_SBTNode(T, a) || IsIllegal_SBTNode(T, b))
        return 0;
    if (Is_Desendant(T, a, b) || Is_Desendant(T, b, a))
        //二者存在子孙关系
        return 0;
    //二者均合法，必存在共同祖先，任取其一求其双亲判断是否为另一结点的双亲，直到根节点或是为止
    while (!IsIllegal_SBTNode(T, a))
    {
        a = GetPar(T, a);
        if (Is_Desendant(T, a, b))
            return a;
    }
    return 0;
}

/**********************************************打印*******************************************************/

int GetSBTDepth(SqBiTree T)
{
    if (IsIlleagl_SBT(T))
        return 0;
    return floor(log2(T.lastIndex)) + 1;
}

int GetSBTMaxSizeDepth(SqBiTree T)
{
    if (IsIlleagl_SBT(T))
        return 0;
    return floor(log2(T.maxSize)) + 1;
}

void ShowSBT(SqBiTree T)
{
    if (T.lastIndex == 0 || IsIlleagl_SBT(T))
    {
        printf(">>二叉树空或异常!\n");
    }
    else
    {
        int depth = GetSBTDepth(T);
        int pos_x = pow(2, depth - 2) / 4 * 12 - 1; //根位置
        int oriYpos = wherey();                     //光标y原始位置
        gotoxy(pos_x, wherey());
        PirntSBT(T, 1, depth);
        gotoxy(0, oriYpos + depth * 2); //光标回到行首
    }

    printf(">>目前可用最大层数:%d\n", GetSBTMaxSizeDepth(T));
}

void PirntSBT(SqBiTree T, int p, int depth)
{
    if (IsIllegal_SBTNode(T, p) || depth <= 0)
        return; //结束条件

    int distance = pow(2, depth - 2) * 12 / 4 - pow(2, depth - 3) * 12 / 4;
    if (1 == distance)
        distance = 2;

    int pos_x = wherex();                                 //当前根x位置
    int pos_y = wherey();                                 //当前根y位置
    int lpos = pos_x - distance, rpos = pos_x + distance; //左/右子树根位置

    printf("%c", T.elem[p]); //调用pirntBiTree之前已经定好了根的位置，即wherex()

    int lchild = GetLchild(T, p);
    int rchild = GetRchild(T, p);

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

/**********************************************其他*******************************************************/
void swap(TElemType &a, TElemType &b)
{
    TElemType temp = a;
    a = b;
    b = temp;
}
