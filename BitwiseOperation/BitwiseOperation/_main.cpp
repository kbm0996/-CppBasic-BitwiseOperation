#include <cstdio>

void main()
{
	unsigned short shBit = 0;
	int iCnt = sizeof(shBit) * 8;	// 1 Byte = 8 Bits
	int iIdx;
	int iFlag;

	while (1)
	{
		///////////////////////////////////////////////////////////
		// BIT Print
		//
		///////////////////////////////////////////////////////////
		for (int i = iCnt - 1; i >= 0; --i)
		{
			// TODO: `특정 비트`와 `i 번째 비트`을 AND 연산하여 특정 비트의 값 확인
			// Mask		shBit & (0x1 << i)
			// >> i		원래 값을 1이나 0으로 표시하기 위함
			//	ex) 1000/0000/0000/0000 → 32768 이므로 자릿수만큼 우측 시프트(>>) 연산으로 내려줘야 1로 표시됨
			printf("%d", (shBit & (0x1 << i)) >> i);
			if (i % 4 == 0 && i != 0)
				printf(" / ");
		}
		printf("\n");

		///////////////////////////////////////////////////////////
		// BIT Manipulate
		//
		///////////////////////////////////////////////////////////
		printf("Bit Pos (1~%d): ", iCnt);
		scanf_s("%d", &iIdx);
		if (iIdx > iCnt || iIdx <= 0)
		{
			printf("Exceeded Range.\n\n");
			continue;
		}

		printf("[0, 1] : ");
		scanf_s("%d", &iFlag);
		if (iFlag == 1)
		{
			shBit = shBit | (0x1 << iIdx - 1);
		}
		else if (iFlag == 0)
		{
			shBit = shBit ^ (0x1 << iIdx - 1); // XOR 연산
		}
		else
		{
			printf("Exceeded Range.\n\n");
		}
	}
}