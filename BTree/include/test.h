#include <SqBiTree.h>

#ifndef __TEST_HEAD__
#define __TEST_HEAD__

/**
 * @brief ���ٴ���һ��������ʵ��
 *
 * @param T ���ڴ洢������ʵ��
 * @return Status ���������Ϣ
 */
Status BuildSBT(SqBiTree &T);

/**
 * @brief �༭һ�Ŷ�����
 *
 * @param T �༭Ŀ�������
 * @return Status �༭�����Ϣ
 */
Status EditSBT(SqBiTree &T);

/**
 * @brief ����Ҫ���ܵĲ��Ժ���
 *
 * @param T ����������
 */
void Test_InitSBT(SqBiTree &T);
void Test_ExtendSBT(SqBiTree &T);
void Test_DestroySBT(SqBiTree &T);
void Test_InsertSBTNode(SqBiTree &T);
void Test_DeleteSBTLeaf(SqBiTree &T);
void Test_ModifySBTNode(SqBiTree &T);
void Test_BreakBiTree(SqBiTree &T);
void Test_ReplaceSBT(SqBiTree &T);
void Test_DeleteSubTree(SqBiTree &T);
void Test_SearchSBTNode(SqBiTree T);
void Test_getDegreeN(SqBiTree T);
void Test_CountDepthNum(SqBiTree T);
void Test_Traverse(SqBiTree T);
void Test_Is_Desendant(SqBiTree T);
void Test_FindCommonAncestor(SqBiTree T);

#endif