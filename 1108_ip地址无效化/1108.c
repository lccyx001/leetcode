/* 给你一个有效的 IPv4 地址 address，返回这个 IP 地址的无效化版本。
所谓无效化 IP 地址，其实就是用 "[.]" 代替了每个 "."。
示例 1：
输入：address = "1.1.1.1"
输出："1[.]1[.]1[.]1"
示例 2：
输入：address = "255.100.50.0"
输出："255[.]100[.]50[.]0"
提示：
给出的 address 是一个有效的 IPv4 地址 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char * defangIPaddr(char * address){
    if (address == NULL)return NULL;

    int len = strlen(address);
    char* s=address; 
    char* result = (char*) malloc((len + 7)* sizeof(char));
    if (result== NULL)return NULL;

    while (*s!='\0'){
        if (*s=='.'){
            *(result++) = '[';
            *(result++) = *(s++);
            *(result++) = ']';
        }
        else{
            *(result++) = *(s++);
        }
    }
    *result ='\0';
    
    return result-len-6;
};

int main(){
    char* a = "1.1.1.1";
    char* b = defangIPaddr(a);
    printf("%s\n",b);
}