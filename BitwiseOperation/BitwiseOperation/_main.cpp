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
			// TODO: `Ư�� ��Ʈ`�� `i ��° ��Ʈ`�� AND �����Ͽ� Ư�� ��Ʈ�� �� Ȯ��
			// Mask		shBit & (0x1 << i)
			// >> i		���� ���� 1�̳� 0���� ǥ���ϱ� ����
			//	ex) 1000/0000/0000/0000 �� 32768 �̹Ƿ� �ڸ�����ŭ ���� ����Ʈ(>>) �������� ������� 1�� ǥ�õ�
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
			shBit = shBit ^ (0x1 << iIdx - 1); // XOR ����
		}
		else
		{
			printf("Exceeded Range.\n\n");
		}
	}
}