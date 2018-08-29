#ifndef MY_RUNTIME_ERROR_STUB_H
#define MY_RUNTIME_ERROR_STUB_H

#include "MyRuntimeError.h"

void MyRuntimeErrorStub_Reset(void);
const char* MyRuntimeErrorStub_GetLastError(void);
int MyRuntimeErrorStub_GetLastParameter(void);


#endif //MY_RUNTIME_ERROR_STUB_H