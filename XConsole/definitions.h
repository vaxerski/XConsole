
// Win32 / Linux
#ifdef _WIN32

#define WIN32_LINUX(win32, linux) win32
#define IS_WIN32() true

#else

#define WIN32_LINUX(win32, linux) linux
#define IS_WIN32() false

#endif
