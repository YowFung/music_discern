/* 辅助函数头文件 */
#ifndef HELPER_H
#define HELPER_H


// 计算数组长度
template <class T>
int array_len(T& array)
{
    if (*array == nullptr)
        return 0;
    else
        return (sizeof(array) / sizeof(array[0]));
}

#endif // HELPER_H
