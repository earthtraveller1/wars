/*
    This header file contains some basic OpenGL debugging symbols. It is going to
    be used pretty oftenly and that's all I can say for now.
*/

#ifndef B7B386A0_C3D1_4A67_9399_13CC52A084F5
#define B7B386A0_C3D1_4A67_9399_13CC52A084F5

// Turn off opengl debugging if we are compiling release codes
#include <config.h>
#ifndef ENABLE_OPENGL_DEBUGGING
    #define glCall(x, ...) x(__VA_ARGS__)
    #define glCallR(x, ...) x(__VA_ARGS__)
    #define glCallN(x) x()
    #define glCallRN(x) x()
#else
    #define glCall(x, ...) gldb::glCallImpl(x, __VA_ARGS__)
    #define glCallR(x, ...) gldb::glCallRImpl(x, __VA_ARGS__)
    #define glCallN(x) gldb::glCallImpl(x)
    #define glCallRN(x) gldb::glCallRImpl(x)
#endif

namespace gldb {
    // Print out all of the errors generated from the previous OpenGL call, and
    // trigger a breakpoint when in debug mode
    void printErrors();
    
    // Check the passed OpenGL call for errors
    template<typename callType, typename... argsType>
    void glCallImpl(callType call, argsType... args) {
        call(args...);
        printErrors();
    }
    
    // Same as the function above, but this one returns a value
    template<typename callType, typename... argsType>
    auto glCallRImpl(callType call, argsType... args) {
        auto result = call(args...);
        printErrors();
        return result;
    }
}

#endif /* B7B386A0_C3D1_4A67_9399_13CC52A084F5 */
