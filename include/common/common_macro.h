
#ifndef __COMMON_MACRO_H__
#define __COMMON_MACRO_H__

#define CPP_BEGIN \
#ifdef __cplusplus\
extern "C" \
{\
#endif

#define CPP_END \
#ifdef __cplusplus\
}\
#endif

////////////////////Array//////////////////////////////////
#define ARRAY_MBS(Array) (sizeof(Array)/sizeof(Array[0]))


////////////////////Struct begin//////////////////////////////////
#define TYPE_TO_OBJ(Type) (*(Type*)0)
#define MB_ADDR(Object, Member) ((SIZE_T)&((Object).Member))

#define MB_OFFSET_OBJ(Object, Member) \
	((SIZE_T)(MB_ADDR(Object, Member) - ((SIZE_T)&(Object))))
#define MB_OFFSET(Type, Member) MB_OFFSET_OBJ(TYPE_TO_OBJ(Type), Member)

#define CONTAINER_OF(MbAddr, Type, Member)\
	({\
		const __typeof__(TYPE_TO_OBJ(Type).Member)* pTmp = MbAddr;\
		(Type*)((CHPT)pTmp - MB_OFFSET(Type, Member));\
	})
////////////////////Struct end//////////////////////////////////

////////////////////compiler related begin////////////////////
#define INLINE inline
////////////////////compiler related end////////////////////

#define DEBUG_MODE
#ifdef DEBUG_MODE
	#define ASSERT(Exp) assert(Exp)
#else
	#define ASSERT(Exp) ((void)0)
#endif

extern void CommonMacroTest(void);

#endif

