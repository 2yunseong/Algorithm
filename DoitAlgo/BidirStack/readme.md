#양방향 스택(Bidirection Stack)


1.flag를 바꾸어 앞 뒤로 Push&Pop 할 수 있도록 구현.


2.Print, Search, Peek 제공.


##잡아야 할 벌레들


1.Push 를 호출할때 , Data 를 입력하고 IsEmpty 판단을함.


 -Data를 입력하기 전에 IsEmpty 판단하도록 조정할 것.
 
 
2.Pop함수가 front에 하나 이상 Data가 들어있을 때, rear에 데이터가 없는
상태에서 Pop을 하면, Out of range Error 발생(컴파일러 디버그 안잡힘)


-IsEmpty 함수 오류로 보임.. 


###넣어야 할 기능


-Push, Pop 하는 위치(인덱스) 출력하게 만들기.
