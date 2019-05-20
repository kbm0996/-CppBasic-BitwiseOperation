# 비트 연산
## ▶ 비트 연산자(Bit Operator)
  
  | example | comment |
  |:--------:|:--------:|
  | a & b | 비트단위 AND |
  | a ㅣ b | 비트단위 OR |
  | a ^ b | 비트단위 exclusive (XOR) |
  | a << b | 왼쪽으로 비트를 b만큼 이동 |
  | a >> b | 오른쪽으로 비트를 b만큼 이동 |
  | ~ a | NOT |
  
  ### 1. & 연산자 
  
   두 비트를 비교하여 모두 1일 때에만 1을 반환
  
    12 = 00001100 (In Binary)
    25 = 00011001 (In Binary)

    Bit Operation of 12 and 25
      00001100
    & 00011001
      ________
      00001000  = 8 (In decimal)
      
  #### Example #1: Bitwise AND
    #include <stdio.h>
    int main()
    {
        int a = 12, b = 25;
        printf("Output = %d", a&b);   // Output = 8
        return 0;
    }

  ### 2. | 연산자 
  
   두 비트를 비교하여 하나라도 1이면 1을 반환
  
    12 = 00001100 (In Binary)
    25 = 00011001 (In Binary)

    Bitwise OR Operation of 12 and 25
      00001100
    | 00011001  = 29 (In decimal)
    ________
    00011101  = 29 (In decimal)
      
  #### Example #2: Bitwise OR
    #include <stdio.h>
    int main()
    {
        int a = 12, b = 25;
        printf("Output = %d", a|b);   // Output = 29
        return 0;
    }
    
   ### 3. ^ (XOR; exclusive OR) 연산자 
  
   두 비트를 비교하여 모두 1이면 0 반환
  
    12 = 00001100 (In Binary)
    25 = 00011001 (In Binary)

    Bitwise XOR Operation of 12 and 25
      00001100
    ^ 00011001
      ________
      00010101  = 21 (In decimal)
      
  #### Example #3: Bitwise XOR
    #include <stdio.h>
    int main()
    {
        int a = 12, b = 25;
        printf("Output = %d", a^b);    // Output = 21
        return 0;
    }
    
   ### 4. << (Left Shift) 연산자 
  
   a << b. a의 비트를 b만큼 왼쪽으로 이동시키고 오른쪽 비트는 0으로 채움
  
    212 = 11010100 (In binary)
    212<<1 = 110101000 (In binary) [Left shift by one bit]
    212<<0 =11010100 (Shift by 0)
    212<<4 = 110101000000 (In binary) =3392(In decimal)
      
  #### Example #4: Left Shift Operator
    #include <stdio.h>
    int main()
    {
        int num=212, i;
         for (i=0; i<=2; ++i) 
            printf("Left shift by %d: %d\n", i, num<<i);   
            
        // Left Shift by 0: 212
        // Left Shift by 1: 424
        // Left Shift by 2: 848

         return 0;
    }
    
   ### 5. >> (Right Shift) 연산자 
  
   a >> b. a의 비트를 b만큼 오른쪽으로 이동시키고 오른쪽 비트는 음수면 1, 양수면 0으로 채움
  
    212 = 11010100 (In binary)
    212>>2 = 00110101 (In binary) [Right shift by two bits]
    212>>7 = 00000001 (In binary)
    212>>8 = 00000000 
    212>>0 = 11010100 (No Shift)
      
  #### Example #5: Right Shift Operator
    #include <stdio.h>
    int main()
    {
        int num=212, i;
        for (i=0; i<=2; ++i)
            printf("Right shift by %d: %d\n", i, num>>i);
            
        // Right Shift by 0: 212
        // Right Shift by 1: 106
        // Right Shift by 2: 53
        
         return 0;
    }
    
   ### 6. ~ (NOT, Complement) 연산자 
  
   ~a. a의 모든 비트 반전
  
    35 = 00100011 (In Binary)

    Bitwise complement Operation of 35
    ~ 00100011 
      ________
      11011100  = 220 (In decimal)
     
   #### 2의 보수(Complement)
  
   2의 보수는 2 진수에 대한 연산. 숫자의 2의 보수는 해당 숫자의 보수에 1을 더한 것과 같음
  
     Decimal         Binary           2's complement 
     0            00000000           -(11111111+1) = -00000000 = -0(decimal)
     1            00000001           -(11111110+1) = -11111111 = -256(decimal)
     12           00001100           -(11110011+1) = -11110100 = -244(decimal)
     220          11011100           -(00100011+1) = -00100100 = -36(decimal)
    
    35의 비트 보수는 220 (십진수)
    220의 2의 보수는 -36
    따라서 출력은 220 대신 -36. (~는 비트단위 연산이므로 2의 보수)
    
    Note: Overflow is ignored while computing 2's complement.
      
  #### Example #6: Complement Operator
    #include <stdio.h>
    int main()
    {
        printf("Output = %d\n",~35);  // Output = -36
        printf("Output = %d\n",~-12); // Output = 11
        return 0;
    }
