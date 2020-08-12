#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


// 计数二进制子串
// 给定一个字符串 s，计算具有相同数量0和1的非空(连续)子字符串的数量，并且这些子字符串中的所有0和所有1都是组合在一起的。
// 重复出现的子串要计算它们出现的次数。
// 示例 1 :
// 输入: "00110011"
// 输出: 6
// 解释: 有6个子串具有相同数量的连续1和0：“0011”，“01”，“1100”，“10”，“0011” 和 “01”。
// 请注意，一些重复出现的子串要计算它们出现的次数。
// 另外，“00110011”不是有效的子串，因为所有的0（和1）没有组合在一起。
// 示例 2 :
// 输入: "10101"
// 输出: 4
// 解释: 有4个子串：“10”，“01”，“10”，“01”，它们具有相同数量的连续1和0。
// 注意：
// s.length 在1到50,000之间。
// s 只包含“0”或“1”字符。


// int countBinarySubstrings(char* s){
//     int result = 0;
//     int length = strlen(s);
//     if (length==0)return result;
//     char dest[length];
//     memset(dest,0,length);

//     for (int out_idx=0; out_idx<length;++out_idx){
//         for (int idx=out_idx;idx<length;++idx){
//             dest[idx-out_idx] = s[idx]; // 不能再次调用strlen（），需要弄清楚为什么
//             int dlength = idx-out_idx+1;
//             if (dlength % 2!=0 || dlength==0)continue;

//             int one=0,zero=0,err=0,next = 1,change=0;
//             for (int i=0;i<dlength;i++){
//                 if (strncmp(&dest[i],"1",1)==0)one++;
//                 else if (strncmp(&dest[i],"0",1)==0)zero++;
//                 else {err=1 ;break;}
//                 if (i==dlength-1)break;
//                 if (dest[i]!=dest[next])change ++;
//                 next++;
//             }

//             if (err==1)continue;
//             if (one!=zero) continue;
//             if (change!=1)continue;
//             result ++;
//         }
//         memset(dest,0,length); // 清空数组
//     }
//     return result;
// }
// 超时解

int countBinarySubstrings(char* s) {
    int n = strlen(s);
    int counts[n], counts_len = 0;
    memset(counts, 0, sizeof(counts));
    int ptr = 0;
    while (ptr < n) {
        char c = s[ptr];
        int count = 0;
        while (ptr < n && s[ptr] == c) {
            ++ptr;
            ++count;
        }
        counts[counts_len++] = count;
    }
    int ans = 0;
    for (int i = 1; i < counts_len; ++i) {
        ans += fmin(counts[i], counts[i - 1]);
    }
    return ans;
}



int main(){
    char a[12] = "00110";
    printf("raw str   %s\n",a);
    int r = countBinarySubstrings(a);
    printf("result count %d:",r);
    return 0;
}                   
                    
                                                                                                                   