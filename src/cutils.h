#ifndef __UTILS_H__
#define __UTILS_H__

#define SizeOf(x)   (sizeof(x)/sizeof(*(x)))

#ifdef DEBUG
#define deb(x)      x
#else
#define deb(x)
#endif

typedef unsigned char   uchar;
typedef signed char     schar;
typedef unsigned short  ushort;
typedef unsigned int    uint;
typedef unsigned long   ulong;


#define forever for(;;)


#endif
