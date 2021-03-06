#include "MyRuntimeErrorStub.h"

static const char* message = "No Error";
static int parameter = -1;
static const char* file = 0;
static int line = -1;

void MyRuntimeErrorStub_Reset(void)
{
    message = "No Error";
    parameter = -1;
}

const char* MyRuntimeErrorStub_GetLastError(void)
{
    return message;
}

void MyRuntimeError(const char * m, int p, const char * f, int l)
{
    message = m;
    parameter = p;
    file = f;
    line = l;
}

int MyRuntimeErrorStub_GetLastParameter(void)
{
    return parameter;
}
