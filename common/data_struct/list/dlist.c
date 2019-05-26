
#include "common.h"



SIZE_T GetDListMbs(const DLHead* pstDLHead)
{
	ASSERT(NULL != pstDLHead);
	
	return (pstDLHead->u32Mbs);
}

static INLINE void ReleaseDLNode(DLNode* pstDLNode)
{
	pstDLNode->pNext = NULL;
	pstDLNode->pPrev = NULL;
}

void InitDLHead(DLHead* pstDLHead)
{
	ASSERT(NULL != pstDLHead);

	pstDLHead->u32Mbs = 0;
	pstDLHead->stHeadTail.pNext = &pstDLHead->stHeadTail;
	pstDLHead->stHeadTail.pPrev = &pstDLHead->stHeadTail;
}

static INLINE void _AddDLNode_(DLNode* pFront, 
										DLNode* pNewNode, 
										DLNode* pBehind)
{
	pFront->pNext = pNewNode;	//pFront --> pNewNode
	pNewNode->pPrev = pFront;	//pFront <-- pNewNode

	pNewNode->pNext = pBehind;	//pNewNode --> pBehind
	pBehind->pPrev = pNewNode;	//pNewNode <-- pBehind
}

eBOOL AddDLNode(DLHead* pstDLHead, DLNode* pNewNode)
{
	ASSERT(NULL != pstDLHead);
	ASSERT(NULL != pNewNode);

	_AddDLNode_(&pstDLHead->stHeadTail, pNewNode, pstDLHead->stHeadTail.pNext);

	pstDLHead->u32Mbs++;

	return (eTrue);
}

eBOOL AddDLNode2Tail(DLHead* pstDLHead, DLNode* pNewNode)
{
	ASSERT(NULL != pstDLHead);
	ASSERT(NULL != pNewNode);

	_AddDLNode_(pstDLHead->stHeadTail.pPrev,
				pNewNode, 
				&pstDLHead->stHeadTail);

	pstDLHead->u32Mbs++;

	return (eTrue);
}

static INLINE void _DelDLNode_(DLNode* pFront, 
										DLNode* pDelNode, 
										DLNode* pBehind)
{
	pFront->pNext = pBehind;
	pBehind->pPrev = pFront;

	pDelNode->pNext = NULL;
	pDelNode->pPrev = NULL;
}

eBOOL DelDLNode(DLHead* pstDLHead, DLNode* pDelNode)
{
	ASSERT(NULL != pstDLHead);
	ASSERT(NULL != pDelNode);

	_DelDLNode_(pDelNode->pPrev, pDelNode, pDelNode->pNext);
	
	pstDLHead->u32Mbs--;

	return (eTrue);
}


SIZE_T ForeachDList(const DLHead* pstDLHead, pfDLNodeHandler pfFunc, void* pCtx)
{
	const DLNode* const pTheEnd = &pstDLHead->stHeadTail;
	DLNode* pTmp;
	SIZE_T sAccessCnt = 0;

	ASSERT(NULL != pstDLHead);
	ASSERT(NULL != pfFunc);

	for(pTmp=pstDLHead->stHeadTail.pNext; pTmp!=pTheEnd; pTmp=pTmp->pNext, sAccessCnt++)
	{
		if(eFalse == pfFunc(pTmp, pCtx))
		{
			break;
		}
	}

	return (sAccessCnt);
}


typedef struct _MatchDNode
{
	const DLNode* pNode;
	eBOOL bMatchOrNot;
}MatchDNode;

eBOOL IsMatchDNode(const DLNode* pNode, void* pCtx)
{
	MatchDNode* pstRet = pCtx;
	eBOOL bRet = eTrue;

	if(pstRet->pNode == pNode)
	{
		pstRet->bMatchOrNot = eTrue;//match
		bRet = eFalse;//match the node, then break Foreaching
	}
	
	return (bRet); //just keep Foreaching or not, doesnot mean match or not
}

eBOOL IsTheDNodeExist(const DLHead* pstDLHead, const DLNode* pTheNode)
{
	MatchDNode stRet;
		
	ASSERT(NULL != pstDLHead);
	ASSERT(NULL != pTheNode);

	stRet.bMatchOrNot = eFalse;
	stRet.pNode = pTheNode;

	ForeachDList(pstDLHead, IsMatchDNode, &stRet);

	return (stRet.bMatchOrNot);	
}

typedef struct _SwTimer
{
	DLNode stListNode;
	UINT32 u32Event;
}SwTimer;

#define MAX_POLLING_TIMER 10
static SwTimer gstaPollingTimer[MAX_POLLING_TIMER];
static DLHead gSwTimerHead;

static void InitPollingTimer(void)
{
	SIZE_T i = 0;
	
	for(i=0; i<ARRAY_MBS(gstaPollingTimer); i++)
	{
		gstaPollingTimer[i].u32Event = i + 10000;
	}
}


eBOOL PrintTimerEvent(const DLNode* pNode, void* pCtx)
{
	SwTimer* pTimer = NULL;
	
	ASSERT(NULL != pNode);
	
	pTimer = CONTAINER_OF(pNode, SwTimer, stListNode);
	pCtx = pCtx;
	pTimer->u32Event += 10000000;

	printf("Event = %d\n", pTimer->u32Event);
	
	return (eTrue);
}


void DListMain(void)
{
	//SIZE_T i = 0;
	typeof(ARRAY_MBS(gstaPollingTimer)) i = 0;

	InitPollingTimer();
	
	InitDLHead(&gSwTimerHead);

	for(i=0; i<ARRAY_MBS(gstaPollingTimer); i++)
	{
		AddDLNode(&gSwTimerHead, &gstaPollingTimer[i].stListNode);
	}

	ForeachDList(&gSwTimerHead, PrintTimerEvent, NULL);	
	printf("123\n\n");

	for(i=0; i<ARRAY_MBS(gstaPollingTimer); i++)
	{
		DelDLNode(&gSwTimerHead, &gstaPollingTimer[i].stListNode);
	}

	ForeachDList(&gSwTimerHead, PrintTimerEvent, NULL);	
	printf("456\n\n");

	for(i=0; i<ARRAY_MBS(gstaPollingTimer); i++)
	{
		if(1 == (i&0x01))
		{
			AddDLNode(&gSwTimerHead, &gstaPollingTimer[i].stListNode);
		}
		else
		{
			AddDLNode2Tail(&gSwTimerHead, &gstaPollingTimer[i].stListNode);
		}
	}

	if(IsTheDNodeExist(&gSwTimerHead, &gstaPollingTimer[6].stListNode))
	{
		printf("match\n");
	}
	else
	{
		printf("donot match\n");
		AddDLNode2Tail(&gSwTimerHead, &gstaPollingTimer[6].stListNode);
	}

	ForeachDList(&gSwTimerHead, PrintTimerEvent, NULL);	
	printf("789\n\n");
}

