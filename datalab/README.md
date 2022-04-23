## datalab笔记

1. 一个数异或它本身的结果为0，根据这个特性，判断两个数`a`与`b`是否相等可以表示为`!(a ^ b)`。
2. 作业中的第3题(isTmax)，思路如下：

    思路一：32位补码整数中，最大的数为0x7FFFFFFF，将其加1后得到原码为0x80000000的数，而它的相反数的补码表示恰巧也是0x80000000，因此可以利用这个特点进行判断。但需要注意的是，0的相反数的补码也为0，所以需要排除原数为-1的情况，这一步骤可以利用0的“逻辑为否”的特点，使用非运算完成。

    代码如下：

    ```C
    int nXPlus1 = x + 1;
    // NOTE: a == b <=> !(a ^ b)
    return !(((~nXPlus1 + 1) ^ nXPlus1) | !nXPlus1);
    // Same as !((~nXPlus1 + 1) ^ nXPlus1) & !!nXPlus1.
    ```

    思路二：观察到当`x`为0x7FFFFFFF时，`(x + 1) + x`为0xFFFFFFFF，取反为0。当`x`为-1，即32位补码表示为0xFFFFFFFF时有同样的结果，然而此时`x + 1`为0，可根据此性质排除。此思路对应的代码在最终的文件中，它的运算次数能少1步。

3. **左移/右移运算不应该用于负数上，其结果在C++标准中没有被定义。** 例如`1 << -1`和`-1 >> 1`的结果都是未定义的，完全取决于不同编译器的实现。另外，如果一个变量被移动的位数大于储存它所占用的位数，其结果也是未定义的，例如对32位无符号整数，`1 << 33`的结果未定义；但对于64位无符号整数，`1ULL << 62`的结果是确定且有效的。简而言之，对于C/C++中的位移运算操作，总应将其视为逻辑移位，且参与运算的操作数均应视为无符号的。

    > 参考: [Left shift and right shift operators ('<<' and '>>') | Microsoft Docs](https://docs.microsoft.com/en-us/cpp/cpp/left-shift-and-right-shift-operators-input-and-output?view=msvc-170#right-shifts)

    > 参考: [INT34-C. Do not shift an expression by a negative number of bits or by greater than or equal to the number of bits that exist in the operand - SEI CERT C Coding Standard - Confluence (cmu.edu)](https://wiki.sei.cmu.edu/confluence/display/c/INT34-C.+Do+not+shift+an+expression+by+a+negative+number+of+bits+or+by+greater+than+or+equal+to+the+number+of+bits+that+exist+in+the+operand)

4. 关于作业中的第6题(isAsciiDigit)，更加易于理解的表示是：

    ```C
    int bValidHigh = !(nHigh ^ 3);
    int bValidLow = !(nLow >> 8);
    int bRet = bValidHigh & bValidLow;
    bRet == !!bRet == !(!bValidHigh | !bValidLow)
    ```

    类似于第3题(isTmax)，可以通过两次取反省略一次操作，因此得到了代码中的表示方式。

5. 作业中的第9题(logicalNeg)，思路如下：

    首先考虑0和其他数的区别，那就是`+0 == -0`，在补码表示中，一个数和它的相反数进行或运算，只有当这个数为0时，结果才为0。而对于其他数(包括最小数10…0)可以发现，运算的结果最高位必为1。根据这个特性，将运算结果取最高位(注意：由于前面提到的第3点未定义问题，为了保险多进行一次与运算取移位后的最低位，这样无论编译器将其实现为逻辑移位`shr`还是算术移位`sar`，都可以保证结果统一)，若其为0表示原数为0，若其为1表示原数非0。最后，将结果异或1，得到非运算的输出。
