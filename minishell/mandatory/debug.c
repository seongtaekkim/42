#include "shell.h"

// token data list
void    view_token(t_lexer *lexer)
{
    if (DEBUG)
    {
        t_token *t;
        t = lexer->token;
        printf("lexer ========================\n");
        while (t)
        {
            t_str *str = t->t_str;
            while (str)
            {
                printf("%c",str->c);
                str = str->next;
            }
            printf(", type:%d\n", t->type);
            t = t->next;
        } 
        printf("lexer ========================\n");
    }
}

// astree data list
// preorder
void    view_ast(t_astree *ast, int node_idx, char *pos)
{
    if (DEBUG)
    {
        
        if (!ast)
            return;
        char *s = ast->type == 1 ? "pipe" 
                : ast->type == 4 ? "<"
                : ast->type == 5 ? ">"
                : ast->type == 6 ? "<<"
                : ast->type == 7 ? ">>"
                : ast->type == 8 ? "cmd"
                : ast->type == 9 ? "arg"
                : ast->type == 10 ? "data"
                : ast->type == 11 ? "&&"
                : ast->type == 12 ? "||"
                : ast->type == 13 ? "(" 
                : ast->type == 14 ? ")" : "몰?루";
        if (ast->data)
            s_write(STDOUT_FILENO, ast->data);
        else
            s_write(STDOUT_FILENO, "NULL");
        s_write(STDOUT_FILENO, "(");
        s_write(STDOUT_FILENO, s);
        s_write(STDOUT_FILENO, ", ");
        s_write(STDOUT_FILENO, ft_itoa(node_idx));
        s_write(STDOUT_FILENO, ", ");
        s_write(STDOUT_FILENO, pos);
        // if (ast->after_meta == AST_PARENTHESES_O)
        //     s_write(STDOUT_FILENO, ", open ");           
        // if ( ast->before_meta == AST_PARENTHESES_C)
        //     s_write(STDOUT_FILENO, ", close");           
        s_write(STDOUT_FILENO, ") ");
        view_ast(ast->left, node_idx + 1, "L");
        view_ast(ast->right, node_idx + 1, "R");

        if (ast->subshell) {
            // if (ast->subshell->subshell)
            //     s_write(1, "in subshell!!\n");
            // else
            //     s_write(1, "not in subshell!!\n");
            view_ast(ast->subshell, 0, "n");//debug
        }
    }
}

static int get_size_token_str(t_token *cursor)
{
    int     length;
    t_str   *str;

    length = 0;
    str = cursor->t_str;
    while (str)
    {
        str = str->next;
        length++;
    }
    return (length);
}

// token data
char    *get_str_cursor(t_token *cursor)
{
    char    *buf;
    
    s_malloc((void **)&buf, get_size_token_str(cursor) + 1);
    t_str   *str = cursor->t_str;
    int     i = 0;
    while (str)
    {
        buf[i++] = str->c;
        str = str->next;
    }
    return (buf);
}