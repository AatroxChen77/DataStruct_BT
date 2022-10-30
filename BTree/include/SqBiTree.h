#include <common.h>
#include <console.h>

#ifndef __SQBITREE_HEAD__
#define __SQBITREE_HEAD__

/**
 * @brief ������˳��洢�ṹ����
 *
 */
typedef char TElemType;
typedef struct
{
    TElemType *elem; // 0�ŵ�Ԫ����
    int lastIndex;   //���һ�������±�
    int maxSize;
} SqBiTree;

/**********************************************��������*******************************************************/

/**
 * @brief ����һ�ſն�����
 *
 * @param T ���ô�����˳�������
 * @param depth ˳������������ȣ����ڼ��������С��
 * @return ��ʼ�������Ϣ
 */
Status InitSqBiTree(SqBiTree &T, int depth);

/**
 * @brief �ڶ������±�p������ֵΪe�Ľ��
 *
 * @param T Ҫ����Ķ�����
 * @param e ����ֵ
 * @param par ����λ�õ�˫�׽���ֵ
 * @param tag ˫�׵�����һ���˫��:'L':��'R':�ҡ����ڵ�:'#'
 * @return Status ��������Ϣ
 */
Status InsertSBTNode(SqBiTree &T, TElemType e, TElemType par, char tag);

/**
 * @brief ���ٶ�����
 *
 * @param T Ҫ���ٵĶ�����
 * @return Status ���ٽ����Ϣ
 */
Status DestroySBT(SqBiTree &T);

/**
 * @brief �޸Ķ������н���ֵ
 *
 * @param T �޸Ľ�����ڶ�����
 * @param ori ԭ����ֵ
 * @param e �޸ĺ����ֵ
 * @return Status
 */
Status ModifySBTNode(SqBiTree &T, TElemType ori, TElemType e);

/**
 * @brief ��һ�Ŷ������ֽ�ɸ�����������������3����
 *
 * @param T ԭ������
 * @param L �ֽ���������
 * @param R �ֽ���������
 * @return Status �ֽ�����Ϣ
 */
Status BreakBiTree(SqBiTree &T, SqBiTree &L, SqBiTree &R);

/**
 * @brief �滻��Ϥŭ��������ĳ����,������ԭ����
 *
 * @param T ��ִ���滻�����Ķ�����
 * @param tag �滻�ķ��� 'L':��'R':��
 * @param re �滻����,����ԭ����
 * @return Status �滻�����Ϣ
 */
Status ReplaceSBT(SqBiTree &T, char tag, SqBiTree &re);

/**********************************************��Ϣ��ȡ*******************************************************/

/**
 * @brief ����k�����������Ľ������
 *
 * @param maxdepth ������
 * @return int k�����������Ľ������
 */
int CountMaxNum(int maxdepth);

/**
 * @brief �ж�˳��������Ƿ�Ƿ�
 *
 * @param T Ҫ�зǷ���˳�������
 * @return Status �зǷ������Ϣ
 */
Status IsIlleagl_SBT(SqBiTree T);

/**
 * @brief �ж�˳�������p�±��Ƿ�Ƿ�
 *
 * @param T Ҫ�пյĽ�����ڵ�˳�������
 * @param p Ҫ�пյĽ���±�
 * @return Status �пս����Ϣ
 */
Status IsIllegal_SBTNode(SqBiTree T, int p);

/**
 * @brief �ж�v����Ƿ�Ϊu��������
 *
 * @param T �������жϹ�ϵ�����Ķ�����
 * @param u ���ж�����
 * @param v ���ж�����
 * @return Status �жϽ����Ϣ
 */
Status Is_Desendant(SqBiTree T, int u, int v);

/**
 * @brief ��ȡĳ���ӽ���˫�׽���±�
 *
 * @param T �ú��ӽ�����ڵĶ�����
 * @param child ���ӽڵ��±�
 * @return int ���ҵ�������˫�׽����±ꣻ���򣬷���0
 */
int GetPar(SqBiTree T, int child);

/**
 * @brief ��ȡĳ˫�׽������ӽ���±�
 *
 * @param T ��˫�׽�����ڵĶ�����
 * @param par ˫�׽���±�
 * @return �������ӽ����±ꣻ���򣬷���0
 */
int GetLchild(SqBiTree T, int par);

/**
 * @brief ��ȡĳ˫�׽����Һ��ӽ���±�
 *
 * @param T ��˫�׽�����ڵĶ�����
 * @param par ˫�׽���±�
 * @return int ���ҵ��������Һ��ӽ����±ꣻ���򣬷���0
 */
int GetRchild(SqBiTree T, int par);

/**
 * @brief ����˳���������ֵΪe�Ľ��
 *
 * @param T ������˳�������
 * @param e ����Ŀ��ֵ
 * @return int ���ҵ������ض�Ӧ�����±ꣻ���򣬷���0
 */
int SearchSBTNode(SqBiTree T, TElemType e);

/**
 * @brief ��ʹ��T.lastIndex��ȡ�����������һ��Ԫ�ص��±�
 *
 * @param T ��ȡ�Ķ�����
 * @return int �������Ԫ�ص��±꣬��Ϊ�շ���0
 */
int getLastIndex(SqBiTree T);

/**
 * @brief �������Ϊ0(Ҷ�ӽ��)�Ľ��ĸ���
 *
 * @param T Ŀ�������
 * @return int Ҷ�ӽ��ĸ���
 */
int getDegreeZero(SqBiTree T);

/**
 * @brief �������Ϊ1�Ľ��ĸ���
 *
 * @param T Ŀ�������
 * @return int ����Ϊ1�Ľ��ĸ���
 */
int getDegreeOne(SqBiTree T);

/**
 * @brief �������Ϊ2�Ľ��ĸ���
 *
 * @param T Ŀ�������
 * @return int ����Ϊ2�Ľ��ĸ���
 */
int getDegreeTwo(SqBiTree T);

/**
 * @brief ��ȡ������ĳ��ȵĽ�����
 *
 * @param T Ŀ�������
 * @param depth ָ�������
 * @return int ĳ��ȵĽ�����
 */
int CountDepthNum(SqBiTree T, int depth);

/**
 * @brief �������������
 *
 * @param T Ŀ�������
 * @param root ��ǰ�ݹ��εĸ�����±�
 * @param visit ���ʺ���
 */
void PreTraverse(SqBiTree T, int root, Status (*visit)(SqBiTree T, int p));

/**
 * @brief �������������
 *
 * @param T Ŀ�������
 * @param root ��ǰ�ݹ��εĸ�����±�
 * @param visit ���ʺ���
 */
void MidTraverse(SqBiTree T, int root, Status (*visit)(SqBiTree T, int p));

/**
 * @brief �������������
 *
 * @param T Ŀ�������
 * @param root ��ǰ�ݹ��εĸ�����±�
 * @param visit ���ʺ���
 */
void PostTraverse(SqBiTree T, int root, Status (*visit)(SqBiTree T, int p));

/**
 * @brief ��α���������
 *
 * @param T Ŀ�������
 * @param visit ���ʺ���
 */
void LevelTraverse(SqBiTree T, Status (*visit)(SqBiTree T, int p));

/**
 * @brief �����÷��ʺ���
 *
 * @param T Ŀ�������
 * @param p ��ǰ���ʽ����±�
 * @return Status
 */
Status VisitNode(SqBiTree T, int p);

/**********************************************��ӡ*******************************************************/

/**
 * @brief ����˳����������
 *
 * @param T Ҫ������ȵĶ�����
 * @return int ���
 */
int GetSBTDepth(SqBiTree T);

/**
 * @brief չʾ������
 *
 * @param T Ҫչʾ�Ķ�����
 */
void ShowSBT(SqBiTree T);

/**
 * @brief �ݹ��ӡ������
 *
 * @param T Ҫ��ӡ�Ķ�����
 * @param p �ݹ鵱ǰ�����ĸ��±�
 * @param depth ʣ���ӡ���
 */
void PirntSBT(SqBiTree T, int p, int depth); //�ݹ��ӡ������

#endif