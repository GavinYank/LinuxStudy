#include "common.h"

#define TEST_NUM 456

typedef struct 
{
	UINT32 a;
}Acc;

typedef struct _MeiMei
{
	UINT32 b;
	UINT8 c;
	Acc Song;
}MeiMei;

void CommonMacroTest(void)
{
	MeiMei stJiangMin;
	MeiMei* pstMin = NULL;
	
	const Acc* pSong = &stJiangMin.Song;

	pSong = pSong;
	stJiangMin.Song.a = TEST_NUM;
	
	printf("MB_OFFSET(MeiMei, b) = %ld\n", MB_OFFSET(MeiMei, b));
	printf("MB_OFFSET(MeiMei, c) = %ld\n", MB_OFFSET(MeiMei, c));
	printf("MB_OFFSET(MeiMei, Song) = %ld\n\n\n", MB_OFFSET(MeiMei, Song));

	pstMin = CONTAINER_OF(pSong, MeiMei, Song);
	printf("pstMin->Song.a = %d\n", pstMin->Song.a);

	printf("&stJiangMin = 0x%lx\n", (UINT)&stJiangMin);
	printf("CONTAINER_OF(pSong, MeiMei, Song) = 0x%lx\n", 
		(UINT)CONTAINER_OF(pSong, MeiMei, Song));

	assert(0 == MB_OFFSET(MeiMei, b));
	assert(4 == MB_OFFSET(MeiMei, c));
	assert(8 == MB_OFFSET(MeiMei, Song));
	assert(pstMin->Song.a == stJiangMin.Song.a);
}

