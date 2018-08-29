#ifndef MY_RUNTIME_ERROR_H
#define MY_RUNTIME_ERROR_H

void MyRuntimeError(const char* message, int parameter,
                    const char* file, int line);

#define MYRUNTIME_ERROR(description, parameter)\
    MyRuntimeError(description, parameter, __FILE__, __LINE__)

#endif //MY_RUNTIME_ERROR_H