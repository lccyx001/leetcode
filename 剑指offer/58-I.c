// 字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
// 请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。
// 示例 1：
// 输入: s = "abcdefg", k = 2
// 输出: "cdefgab"
// 示例 2：
// 输入: s = "lrloseumgh", k = 6
// 输出: "umghlrlose"
// 限制：
// 1 <= k < s.length <= 10000
// lrlose\0
// loselr\0
# include<stdio.h>
# include<string.h>
# include<stdlib.h>

char* reverseLeftWords(char* s, int n){
    // int len = strlen(s),i = 0;;
    // char *ans = malloc(sizeof(char) * (len + 1));
    // while(i < len){
    //     *(ans++) = s[(n + i++)%len];
    // }
    // *ans= '\0';
    // return ans - len;

    if (s==NULL||n<0) return NULL;

    int len = strlen(s),i=0;
    char* r = (char*)malloc( (len+1) * sizeof(char));
    if (r==NULL)return NULL;

    while (i<len)
    {
        *(r++) = s[(n+i++)%len];
    };
    *r = '\0';
    return r-len;
}

int main(){
    char s[]="123456";
    char* r = reverseLeftWords(s,2);
    printf("%s\n",r);
}
