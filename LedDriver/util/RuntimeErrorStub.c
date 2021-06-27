#include "RuntimeErrorStub.h"

static const char * sMessage = "No error!";
static int sParameter = -1;
static const char * sFile = 0;
static int sLine = -1;

void RuntimeErrorStub_Reset(void)
{
    sMessage = "No error!";
    sParameter = -1;
}

const char * RuntimeErrorStub_GetLastError(void)
{
    return sMessage;
}

void RuntimeError(const char * m, int p, const char * f, int l)
{
    sMessage = m;
    sParameter = p;
    sFile = f;
    sLine = l;
}

int RuntimeErrorStub_GetLastParameter(void)
{
    return sParameter;
}