#include<stdio.h>
#include<string.h>
int main(){
    char* m_url;
    char* text="Get weil";
    m_url = strpbrk(text, " ");
    printf("%s",m_url);
    getchar();
    getchar();
    return 0;
}
