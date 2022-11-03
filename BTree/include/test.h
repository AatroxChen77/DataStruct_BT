#include <SqBiTree.h>

#ifndef __TEST_HEAD__
#define __TEST_HEAD__

/**
 * @brief 快速创建一个二叉树实例
 *
 * @param T 用于存储创建的实例
 * @return Status 创建结果信息
 */
Status BuildSBT(SqBiTree &T);

/**
 * @brief 编辑一颗二叉树
 *
 * @param T 编辑目标二叉树
 * @return Status 编辑结果信息
 */
Status EditSBT(SqBiTree &T);

/**
 * @brief 各主要功能的测试函数
 *
 * @param T 操作二叉树
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