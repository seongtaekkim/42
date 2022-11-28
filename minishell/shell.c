#include "shell.h"

void signal_handler(int signum)
{
    if (signum == SIGQUIT)
    { printf("\033[14C");
        return ;
    }
    if (signum == SIGINT)
    {
        //     if (rl_on_new_line() == -1) // readline으로 설정한 문자열을 한 번 출력한다?
        // exit(1);
        rl_on_new_line();
        rl_replace_line("", 1); // 문자열 replace
        rl_redisplay(); // 프롬프트 재 출력
    }
    else
        return;
}

void setting_signal()
{
    signal(SIGINT, signal_handler);  // CTRL + C
   // signal(SIGTERM, signal_handler); // CTRL + D
    signal(SIGQUIT, signal_handler); // CTRL + /
}

int main(void)
{
    char *str;
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ECHOCTL);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    setting_signal();
    while(1)
    {
        str = readline("shell-1.0$");
        if (str)
        {
            if (*str)
                printf("%s, %d\n", str, *str);
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