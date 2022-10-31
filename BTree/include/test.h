#include <SqBiTree.h>

#ifndef __TEST_HEAD__
#define __TEST_HEAD__

Status BuildSBT(SqBiTree &T);
Status EditSBT(SqBiTree &T);
void Test_InitSBT(SqBiTree &T);
void Test_ExtendSBT(SqBiTree &T);
void Test_DestroySBT(SqBiTree &T);
void Test_InsertSBTNode(SqBiTree &T);
void Test_DeleteSBTLeaf(SqBiTree &T);
void Test_ModifySBTNode(SqBiTree &T);
void Test_BreakBiTree(SqBiTree &T);
void Test_ReplaceSBT(SqBiTree &T);

void Test_SearchSBTNode(SqBiTree T);
void Test_getDegreeN(SqBiTree T);
void Test_CountDepthNum(SqBiTree T);
void Test_Traverse(SqBiTree T);
void Test_Is_Desendant(SqBiTree T);

#endif