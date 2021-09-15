/* 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"
说明：

num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/multiply-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *multiply(char *num1, char *num2)
{
    if (!num1 || !num2)
        return NULL;
    int l1 = strlen(num1);
    int l2 = strlen(num2);
    char *num1_ptr = num1;
    char *num2_ptr = num2;

    char *result = (char *)malloc((l1 + l2 + 1) * sizeof(char));
    memset(result, 0, (l1 + l2 + 1) * sizeof(char));

    char **tmp_char = (char **)malloc((l1 + 1) * (l2 + 1) * sizeof(char*));
    memset(tmp_char, 0, (l1 + 1) * (l2 + 1) * sizeof(char));
    int i = 0, j = 0, increase = 0, tmp = 0;
    while (i < l1)
    {
        int n1 = (int)num1_ptr[l1 - i - 1] - 48;
        while (j < l2)
        {
            int n2 = (int)num2_ptr[l2 - j - 1] - 48;
            tmp = n1 * n2 + increase;
            if (tmp > 9)
                increase = tmp / 10;
            printf("multi numbers:%d,%d,result:%d\n", n1, n2, increase);
            tmp_char[i * l2 + j] = (char)(tmp % 10) + 48;
            printf("%s\n", tmp_char);
            j++;
        }
        break;
        i++;
    }
    return result;
}

char** allocate_two_chararray(){
    
}

int main()
{
    char *num1 = "123", *num2 = "456";
    multiply(num1, num2);
}