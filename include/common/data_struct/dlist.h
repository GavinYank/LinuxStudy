#ifndef __DLIST_H__
#define __DLIST_H__


typedef struct _DoubleListNode
{
	struct _DoubleListNode* pNext;
	struct _DoubleListNode* pPrev;
}DLNode;


typedef struct _DoubleListHead
{
	DLNode stHeadTail;//use it connect dlist's head and tail
	SIZE_T u32Mbs;//the members of a double list, doesnot include stHeadTail
}DLHead;

typedef eBOOL pfDLNodeHandler(const DLNode* pNode, void* pCtx);






#ifdef __cplusplus
extern "C" 
{
#endif

extern void DListMain(void);

#ifdef __cplusplus
}
#endif

#endif
