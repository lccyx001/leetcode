# 编码技巧&编码习惯

## 编码技巧

- 进制转换 任意k进制转十进制 int(n,k) n为字符串,十进制转任意进制

```python
b=[]
while True:
    s=n//x  # 商
    y=n%x  # 余数
    b=b+[y]
    if s==0:
        break
    n=s
b.reverse()
```

- 返回两个整数的最大值 int((abs(a-b)+a+b)/2)

## 编码习惯

- 开始编码前，想好测试用例
  