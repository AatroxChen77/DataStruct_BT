#include <common.h>
#include <console.h>

#ifndef __SQBITREE_HEAD__
#define __SQBITREE_HEAD__

/**
 * @brief 二叉树顺序存储结构定义
 *
 */
typedef char TElemType;
typedef struct
{
    TElemType *elem; // 0号单元闲置
    int lastIndex;   //最后一个结点的下标
    int maxSize;
} SqBiTree;

/**********************************************基本操作*******************************************************/

/**
 * @brief 创造一颗空二叉树
 *
 * @param T 放置创建的顺序二叉树
 * @param depth 顺序二叉树最大深度（用于计算数组大小）
 * @return 初始化结果信息
 */
Status InitSqBiTree(SqBiTree &T, int depth);

/**
 * @brief 在二叉树下标p处插入值为e的结点
 *
 * @param T 要插入的二叉树
 * @param e 结点的值
 * @param par 插入位置的双亲结点的值
 * @param tag 双亲的左或右或无双亲:'L':左、'R':右、根节点:'#'
 * @return Status 插入结果信息
 */
Status InsertSBTNode(SqBiTree &T, TElemType e, TElemType par, char tag);

/**
 * @brief 销毁二叉树
 *
 * @param T 要销毁的二叉树
 * @return Status 销毁结果信息
 */
Status DestroySBT(SqBiTree &T);

/**
 * @brief 修改二叉树中结点的值
 *
 * @param T 修改结点所在二叉树
 * @param ori 原结点的值
 * @param e 修改后结点的值
 * @return Status
 */
Status ModifySBTNode(SqBiTree &T, TElemType ori, TElemType e);

/**
 * @brief 将一颗二叉树分解成根、左子树和右子树3部分
 *
 * @param T 原二叉树
 * @param L 分解后的左子树
 * @param R 分解后的右子树
 * @return Status 分解结果信息
 */
Status BreakBiTree(SqBiTree &T, SqBiTree &L, SqBiTree &R);

/**
 * @brief 替换熟悉怒二叉树的某子树,并返回原子树
 *
 * @param T 被执行替换操作的二叉树
 * @param tag 替换的方向 'L':左、'R':右
 * @param re 替换用树,返回原子树
 * @return Status 替换结果信息
 */
Status ReplaceSBT(SqBiTree &T, char tag, SqBiTree &re);

/**********************************************信息获取*******************************************************/

/**
 * @brief 计算k层满二叉树的结点总数
 *
 * @param maxdepth 最大层数
 * @return int k层满二叉树的结点总数
 */
int CountMaxNum(int maxdepth);

/**
 * @brief 判断顺序二叉树是否非法
 *
 * @param T 要判非法的顺序二叉树
 * @return Status 判非法结果信息
 */
Status IsIlleagl_SBT(SqBiTree T);

/**
 * @brief 判断顺序二叉树p下标是否非法
 *
 * @param T 要判空的结点所在的顺序二叉树
 * @param p 要判空的结点下标
 * @return Status 判空结果信息
 */
Status IsIllegal_SBTNode(SqBiTree T, int p);

/**
 * @brief 判断v结点是否为u结点的子孙
 *
 * @param T 包含需判断关系两结点的二叉树
 * @param u 待判断祖先
 * @param v 待判断子孙
 * @return Status 判断结果信息
 */
Status Is_Desendant(SqBiTree T, int u, int v);

/**
 * @brief 获取某孩子结点的双亲结点下标
 *
 * @param T 该孩子结点所在的二叉树
 * @param child 孩子节点下标
 * @return int 若找到，返回双亲结点的下标；否则，返回0
 */
int GetPar(SqBiTree T, int child);

/**
 * @brief 获取某双亲结点的左孩子结点下标
 *
 * @param T 该双亲结点所在的二叉树
 * @param par 双亲结点下标
 * @return 返回左孩子结点的下标；否则，返回0
 */
int GetLchild(SqBiTree T, int par);

/**
 * @brief 获取某双亲结点的右孩子结点下标
 *
 * @param T 该双亲结点所在的二叉树
 * @param par 双亲结点下标
 * @return int 若找到，返回右孩子结点的下标；否则，返回0
 */
int GetRchild(SqBiTree T, int par);

/**
 * @brief 搜索顺序二叉树中值为e的结点
 *
 * @param T 搜索的顺序二叉树
 * @param e 搜索目标值
 * @return int 若找到，返回对应结点的下标；否则，返回0
 */
int SearchSBTNode(SqBiTree T, TElemType e);

/**
 * @brief 不使用T.lastIndex获取二叉树中最后一个元素的下标
 *
 * @param T 获取的二叉树
 * @return int 返回最后元素的下标，若为空返回0
 */
int getLastIndex(SqBiTree T);

/**
 * @brief 计算度数为0(叶子结点)的结点的个数
 *
 * @param T 目标二叉树
 * @return int 叶子结点的个数
 */
int getDegreeZero(SqBiTree T);

/**
 * @brief 计算度数为1的结点的个数
 *
 * @param T 目标二叉树
 * @return int 度数为1的结点的个数
 */
int getDegreeOne(SqBiTree T);

/**
 * @brief 计算度数为2的结点的个数
 *
 * @param T 目标二叉树
 * @return int 度数为2的结点的个数
 */
int getDegreeTwo(SqBiTree T);

/**
 * @brief 获取二叉树某深度的结点个数
 *
 * @param T 目标二叉树
 * @param depth 指定的深度
 * @return int 某深度的结点个数
 */
int CountDepthNum(SqBiTree T, int depth);

/**
 * @brief 先序遍历二叉树
 *
 * @param T 目标二叉树
 * @param root 当前递归层次的根结点下标
 * @param visit 访问函数
 */
void PreTraverse(SqBiTree T, int root, Status (*visit)(SqBiTree T, int p));

/**
 * @brief 中序遍历二叉树
 *
 * @param T 目标二叉树
 * @param root 当前递归层次的根结点下标
 * @param visit 访问函数
 */
void MidTraverse(SqBiTree T, int root, Status (*visit)(SqBiTree T, int p));

/**
 * @brief 后序遍历二叉树
 *
 * @param T 目标二叉树
 * @param root 当前递归层次的根结点下标
 * @param visit 访问函数
 */
void PostTraverse(SqBiTree T, int root, Status (*visit)(SqBiTree T, int p));

/**
 * @brief 层次遍历二叉树
 *
 * @param T 目标二叉树
 * @param visit 访问函数
 */
void LevelTraverse(SqBiTree T, Status (*visit)(SqBiTree T, int p));

/**
 * @brief 遍历用访问函数
 *
 * @param T 目标二叉树
 * @param p 当前访问结点的下标
 * @return Status
 */
Status VisitNode(SqBiTree T, int p);

/**********************************************打印*******************************************************/

/**
 * @brief 计算顺序二叉树深度
 *
 * @param T 要计算深度的二叉树
 * @return int 深度
 */
int GetSBTDepth(SqBiTree T);

/**
 * @brief 展示二叉树
 *
 * @param T 要展示的二叉树
 */
void ShowSBT(SqBiTree T);

/**
 * @brief 递归打印二叉树
 *
 * @param T 要打印的二叉树
 * @param p 递归当前子树的根下标
 * @param depth 剩余打印层次
 */
void PirntSBT(SqBiTree T, int p, int depth); //递归打印二叉树

#endif