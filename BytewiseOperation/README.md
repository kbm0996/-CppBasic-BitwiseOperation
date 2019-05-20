# 비트 연산
## 📢 개요
 바이트 단위 조작 연습
      

## ▶️ 프로그램 기능

  ![Bytewise Operation](https://github.com/kbm0996/Practice-BitwiseOperation/blob/master/BytewiseOperation/figure/BytewiseOperation.jpg)

 **figure 1. Bytewise Operation*
 

## 📌 주요 소스

    ...
    scanf_s("%d", &iValue_Input);
    ...
    uiByte_Mask = 0;                                                // 마스크 초기화
    uiByte_Mask = ~(uiByte_Mask | 0xff << (iIndex_Input - 1) * 8);  // 변경할 위치의 비트를 초기화하기 위해 마스크 설정
    uiByte = uiByte & uiByte_Mask;                                  // 비트에 마스크를 씌워 초기화
    uiByte = uiByte | (iValue_Input << (iIndex_Input - 1) * 8);     // 비트에 변경할 값 삽입 

 ## 📌 출처 
 
 개요 예제 - https://www.programiz.com/c-programming/bitwise-operators

