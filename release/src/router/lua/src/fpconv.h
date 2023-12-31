/* Lua CJSON floating point conversion routines */

/* Buffer required to store the largest string representation of a double.
 *
 * Longest double printed with %.14g is 21 characters long:
 * -1.7976931348623e+308 */
#define FPCONV_G_FMT_BUFSIZE   32
//使用内部的转换机制
//#define USE_INTERNAL_FPCONV 
//暴露cjson 为lua的全局对象使用就像使用os.clock()直接使用
#define ENABLE_CJSON_GLOBAL
//将inline 冲定义为 __inline
//#define inline __inline  
#ifdef USE_INTERNAL_FPCONV  
static inline void fpconv_init()  
{  
	/* Do nothing - not required */  
}  
#else  
extern void fpconv_init();  
#endif  
 
extern int fpconv_g_fmt(char*, double, int);
extern double fpconv_strtod(const char*, char**); 
 
/* vi:ai et sw=4 ts=4:
 */
