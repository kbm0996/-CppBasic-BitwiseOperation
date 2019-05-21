# 반복문 없이 특정 ID 값 찾기
## 📢 개요
  사용자 정보등을 관리할 필요가 있는 프로그램들은 대게 Index와 ID를 각각 Key, Value로 하여 DB상의 Table 등에 저장하여 관리한다. 이러한 프로그램의 경우 특정 Index나 ID를 찾기 위해선 반복문으로 테이블 전체를 순회하며 찾고자하는 값과 Key나 Value를 일일이 비교하여 찾는 경우가 많다.

이런 식으로 시스템을 설계하면 구현 방식과 관리하는 데이터의 양에 따라서 찾는데 드는 시간이  스레드 할당 등으로 인하여 시스템에 부하가 걸릴 수 있다.
 
때문에 UINT64와 같이 표현 범위가 큰 값을 사용자 구조체나 클래스에 멤버로 두고 **상위 n비트**는 `배열이나 리스트의 Index`, **하위 n비트**는 `사용자의 ID`로 정해놓으면 배열이나 리스트에 직접 접근하여 검색 시간을 없앨 수 있다.  
 

## 📌 주요 소스

    /*상위 4비트 : 최대 16^4 (0 ~ 65,536)개의 Index 사용 가능 */
    #define CreateSessionID(ID, Index)	(((UINT64)Index << 48) | ID)
    #define GetSessionIndex(X) ((X >> 48) & 0xffff)	
    #define GetSessionID(X) ( X & 0x0000ffffffffffff) 

    /*상위 5비트 : 최대 16^5 (0 ~ 1048575)개의 Index 사용 가능 */
    #define CreateSessionID(ID, Index)	(UINT64)((Index << 44) | ID)			// 
    #define GetSessionIndex(SessionID) (UINT64)((SessionID >> 44) & 0xfffff)
    #define GetSessionID(SessionID) (UINT64)(SessionID & 0x00000fffffffffff)
