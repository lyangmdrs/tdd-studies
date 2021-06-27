#ifndef RUNTIMEERRORSTUB_H
#define RUNTIMEERRORSTUB_H

    // Yeah, this should be in another file, I know.
    void RuntimeError(const char * message, int parameter,
                    const char * file, int line);

    #define RUNTIME_ERROR(description, parameter)\
        RuntimeError(description, parameter, __FILE__, __LINE__)
    // ---

    void RuntimeErrorStub_Reset(void);

    const char * RuntimeErrorStub_GetLastError(void);

    int RuntimeErrorStub_GetLastParameter(void);
    
#endif