/* assert.h standard header */
#undef assert	/* remove existing definition */

#ifdef NDEBUG
	#define assert(test)	((void)0)
#else			/* NDEBUG not defined */
	void _Assert(char *);
		/* macros */
//内置宏_STR/__VAL用于将内置宏_LINE_扩展成字符串字面量
	#define _STR(x)	_VAL(x)
	#define _VAL(x)	#x
	#define assert(test)	((test) ? (void)0 \
		: _Assert(__FILE__ ":" _STR(__LINE__) " " #test))
#endif
