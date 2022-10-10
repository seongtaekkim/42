/* printf함수를 사용하기위한 헤더 */
# include <stdio.h>
/* free함수를 사용하기위한 헤더 */
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <fcntl.h>
# include <dirent.h> // ?
# include <errno.h>
/* readline함수를 사용하기위한 헤더 */
# include <readline/readline.h>

/* add_history함수를 사용하기위한 헤더 */
# include <readline/history.h>
void signal_handler(int signum)
{
   // printf("signal is : %d\n", signum);
    if (signum != SIGINT) // ctrl + c
        return;
    rl_on_new_line();
    rl_replace_line("", 1); // 문자열 replace
    rl_redisplay(); // 프롬프트 재 출력
}
void setting_signal()
{
    signal(SIGINT, signal_handler);  // CTRL + C
    signal(SIGTERM, signal_handler); // CTRL + D
    signal(SIGQUIT, signal_handler); // CTRL + /
}
/* readline함수를 활용하여 간단한 프로그램 작성하기 */
int main(void)
{
/* readline함수의 리턴값을 저장하기위해 임의로 포인터를 하나 선언한다 */
    char *str;
    ///signal(SIGINT, handler);
    setting_signal();
/* 무한루프를 돌리면서 readline();함수를 반복적으로 호출할 것이다 */
    while(1)
    {
        /* readline함수가 호출되면 인자(prompt : )를 터미널에 출력하고 저장할 라인을 입력받는다 */
        str = readline("minishell-1.0$");/* read함수는 저장한 문자열의 메모리주소를 반환한다 */
        if (str)/* 입력이 된다면 (주소가 존재한다면) */
        {
            if (*str)
                printf("%s, %d\n", str, *str);/* 주소안에 문자열을 출력해보자 */
        }
        else/* str = NULL 이라면 (EOF, cntl + D)*/
        {
            //rl_replace_line("exit\n", 5);
            ///printf("exit\n");
            break ;/* 반복문을 탈출해준다.*/
        }
	/* add_history에 저장된 문자열은 up & down 방향키를 이용해 확인할수있다 */
        add_history(str);
	/* 라인은 힙메모리에 저장되기때문에 다 사용한 메모리는 할당을 해제해줘야한다 */
        free(str);
    }
    /* 함수종료 */
    return(0);
}