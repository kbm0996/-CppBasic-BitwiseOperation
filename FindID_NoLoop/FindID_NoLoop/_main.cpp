#include <cstdio>
#include <Windows.h>

//#define CreateSessionID(ID, Index)	(((UINT64)Index << 48) | ID)
//#define GetSessionIndex(X) ((X >> 48) & 0xffff)						// limit 16^4 =  65,536
//#define GetSessionID(X) ( X & 0x0000ffffffffffff) 

#define CreateSessionID(ID, Index)	(UINT64)((Index << 44) | ID)			// limit 16^5 (0 ~ 1048575)
#define GetSessionIndex(SessionID) (UINT64)((SessionID >> 44) & 0xfffff)
#define GetSessionID(SessionID) (UINT64)(SessionID & 0x00000fffffffffff)

void main()
{
	UINT64 i = 0;
	UINT64 index = -1;
	sizeof(UINT64);

	while (1)
	{
		printf("\n\n\n");
		printf("Index: %d\n", index + 1);
		//printf("Index: ");
		//scanf_s("%Ilu", &index);
		printf("ID : ");
		scanf_s("%Ilu", &i);

		printf("\n - SessionID: ");
		printf("%p ", CreateSessionID(i, ++index));
		printf("\n - Index: ");
		printf("%p\n", GetSessionIndex(CreateSessionID(i, index)));

		printf("%llu", CreateSessionID(i, index));
		printf("%llu \n", GetSessionIndex(CreateSessionID(i, index)));

	}
}