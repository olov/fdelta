int delta_create(
		 const char *zSrc,      /* The source or pattern file */
		 unsigned int lenSrc,   /* Length of the source file */
		 const char *zOut,      /* The target file */
		 unsigned int lenOut,   /* Length of the target file */
		 char *zDelta           /* Write the delta into this buffer */
		 );
int delta_output_size(const char *zDelta, int lenDelta);
int delta_apply(
		const char *zSrc,      /* The source or pattern file */
		int lenSrc,            /* Length of the source file */
		const char *zDelta,    /* Delta to apply to the pattern */
		int lenDelta,          /* Length of the delta */
		char *zOut             /* Write the output into this preallocated buffer */
		);
