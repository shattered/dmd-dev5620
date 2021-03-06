/* */
/*									*/
/*	Copyright (c) 1987,1988,1989,1990,1991,1992   AT&T		*/
/*			All Rights Reserved				*/
/*									*/
/*	  THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T.		*/
/*	    The copyright notice above does not evidence any		*/
/*	   actual or intended publication of such source code.		*/
/*									*/
/* */
static char ID[] = "@(#) main.c:	2.1 6/2/83";

#include	<stdio.h>

#include	"conv.h"

char	*filev[MAXFILES];
char	curfile[30];
int	errlvl;

main(argc, argv)

int	argc;
char	**argv;
{

	/*
	 * conv -t target file ...
	 *
	 *	converts the common object file "file"
	 *	from one produced on some machine to that produced
	 *	on "target" 
	 */

	extern		fprintf( ),
			exit( ),
			getargs( ),
			convert( );

	int		filec,		/* number of <file> arguments */
			i;

	/*
	 * process command line
	 */

	if ( (filec = getargs(argc,argv)) <= 0 )  {
		fprintf(stderr, "Usage: conv [-s] [-] [ -p | -o | -a ] -t pdp|vax|n3b|m32|ibm|i80|mc68|tahoe|sun files\n");
		exit(1);
		}


	for ( i=0; i < filec; ++i ) {
		strcpy(curfile, sname(filev[i]));
		convert( filev[i] );
		}

	exit(errlvl);
}
