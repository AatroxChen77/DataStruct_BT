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
 * @param child ���ӽڵ��±�
 * @param T �ú��ӽ�����ڵĶ�����
 * @return int ���ҵ�������˫�׽����±ꣻ���򣬷���0
 */
int GetPar(int child, SqBiTree T);

/**
 * @brief ��ȡĳ˫�׽������ӽ���±�
 *
 * @param par ˫�׽���±�
 * @param T ��˫�׽�����ڵĶ�����
 * @return �������ӽ����±ꣻ���򣬷���0
 */
int GetLchild(int par, SqBiTree T);

/**
 * @brief ��ȡĳ˫�׽����Һ��ӽ���±�
 *
 * @param par ˫�׽���±�
 * @param T ��˫�׽�����ڵĶ�����
 * @return int ���ҵ��������Һ��ӽ����±ꣻ���򣬷���0
 */
int GetRchild(int par, SqBiTree T);

/**
 * @brief ����˳���������ֵΪe�Ľ��
 *
 * @param T ������˳�������
 * @param e ����Ŀ��ֵ
 * @return int ���ҵ������ض�Ӧ�����±ꣻ���򣬷���0
 */
int SearchSBTNode(SqBiTree T, TElemType e);

/**
 * @brief ��ȡ�����������һ��Ԫ�ص��±�
 *
 * @param T ��ȡ�Ķ�����
 * @return int �������Ԫ�ص��±꣬��Ϊ�շ���0
 */
int getLastIndex(SqBiTree T);

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