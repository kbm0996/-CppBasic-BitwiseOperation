#include <cstdio>
void main()
{
	unsigned int uiByte = 0;
	unsigned int uiByte_Mask;
	int iIndex_Input;
	int iValue_Input;
	while (1)
	{
		///////////////////////////////////////////////////////////
		// BYTE Print
		//
		///////////////////////////////////////////////////////////
		for (int i = sizeof(uiByte) - 1; i >= 0; --i)
		{
			// TODO: `Ư�� ����Ʈ`�� `i ��° ����Ʈ`�� AND �����Ͽ� Ư�� ����Ʈ(8��Ʈ)�� �� Ȯ��
			// Mask		uiByte & (0xff << i * 8)
			// >> i*8	���� 0~255���� ǥ���ϱ� ���� ���� ����Ʈ(>>)
			//	ex) 127,000,000,000(7f,00,00,00) �� 2,130,706,432,000,000,000(10����)�� ǥ�õǹǷ�
			//    �ڸ�����ŭ ���� ����Ʈ(>>) �������� ������� 0~255 ���� ������ ǥ�õ�
			if (i != sizeof(uiByte) - 1)
				printf(" / ");
			printf("%03d", (uiByte & (0xff << i * 8)) >> i * 8);
		}
		printf("\n");

		///////////////////////////////////////////////////////////
		// BYTE Manipulate
		//
		///////////////////////////////////////////////////////////
		printf("Index (1~%d) : ", sizeof(uiByte));
		scanf_s("%zd", &iIndex_Input);
		if (iIndex_Input < 1 || iIndex_Input > sizeof(uiByte))
		{
			printf("Exceeded Range.\n\n");
			continue;
		}

		printf("[0~255] : ");
		scanf_s("%d", &iValue_Input);
		if (iValue_Input < 0 || iValue_Input> 255)
		{
			printf("Exceeded Range.\n\n");
			continue;
		}

		uiByte_Mask = 0;
		uiByte_Mask = ~(uiByte_Mask | 0xff << (iIndex_Input - 1) * 8);
		uiByte = uiByte & uiByte_Mask;
		uiByte = uiByte | (iValue_Input << (iIndex_Input - 1) * 8);
		printf("\n\n");
	}
}