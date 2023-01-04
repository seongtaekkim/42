
# race condition 발생
raceCondition1.c
raceCondition2.c
RaceCondition1.java
RaceCondition2.java

# peterson's no guarantee
peterson.c

# peterson's guarantee
## atomic : AtomicBoolean : compare_and_swap
Peterson1.java
Peterson2.java

# atomic : compare and swap 
## java의 CompareAndSwap과 cpp의 CompareExchangeStrong
## java - Atomic vs synchronized
## cpp  - Atomic vs mutex
CompareAndSwap.java
CompareAndSwapInc.java
CompareExchangeStrong.cpp

# mutex
mutex_lock.c


# semapore
semaphore1.c
semaphore2.c

# condition variable : synchronized keyword
Monitor1.java ~ Moditor5.java

# concurrency problem : bounded_buffer
## mutex, semaphore
bounded_buffer.c
##  synchronized keyword
BoundedBuffer.java

# concurrency problem : philosophers
## pthread_cond_t, mutex
philosophers.c





# 출처
https://www.inflearn.com/course/%EC%9A%B4%EC%98%81%EC%B2%B4%EC%A0%9C-%EA%B3%B5%EB%A3%A1%EC%B1%85-%EC%A0%84%EA%B3%B5%EA%B0%95%EC%9D%98/dashboard

https://jenkov.com/tutorials/java-concurrency/index.html

https://velog.io/@sunkue/Mutex-Atomic

https://learn.microsoft.com/ko-kr/windows/win32/sync/mutex-objects