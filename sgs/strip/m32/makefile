# 
#									
#	Copyright (c) 1987,1988,1989,1990,1991,1992   AT&T		
#			All Rights Reserved				
#									
#	  THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T.		
#	    The copyright notice above does not evidence any		
#	   actual or intended publication of such source code.		
#									
# 
#
#	BELLMAC-32 STRIP MAKEFILE
#
#	@(#) makefile: 1.9 9/15/83
#
SGS=m32
CC=cc
DMD= /usr/local/dmd
EXTRACFLAGS=-O
CFLAGS=-c -DDMD=\"$(DMD)\" $(EXTRACFLAGS)
ARCH=AR32WR
#	Set ARFORMAT to "PORTAR" for portable archive format (post 5.0)
#	Set ARFORMAT to OLDAR for pre-5.0 archive format
ARFORMAT=PORTAR
#	Set FLEX to -DFLEXNAMES for flexnames (post 6.0)
FLEX= -DFLEXNAMES
DEFLIST=-D$(ARCH) -D$(ARFORMAT) -DUNIX $(FLEX)
INCLIST=-I$(M32INC) -I$(COMINC) -I$(COMSTRIP) -I$(USRINC)
ENV=
CC_CMD=$(CC) $(CFLAGS) $(DEFLIST) $(INCLIST) $(ENV)
#
LD=$(CC)
LDFLAGS=$(FFLAG)
LD_CMD=$(LD) $(LDFLAGS)
#
STRIP=strip
SPFLAGS=
STRIP_CMD=$(STRIP) $(SPFLAGS)
#
LINT=lint
LINTFLAGS=-p
LINT_CMD=$(LINT) $(LINTFLAGS)
#
#	External Directories
#
ROOT=
VERSION=
USRINC= $(ROOT)/usr/$(VERSION)include
#
#	Internal Directories
#
BASE = ../..
BINDIR= $(BASE)/xenv/m32/bin
M32INC= $(BASE)/inc/m32
COMINC= $(BASE)/inc/common
COMSTRIP= $(BASE)/strip/common
#
LIBLD	= $(BASE)/libld/m32/libld.a
#
OBJECTS= main.o setflags.o process.o checkflags.o buildtmp.o buildfcns.o \
	copytmp.o fcns.o
#
all:	strip
#
strip:	$(OBJECTS) $(LIBLD)
	$(LD_CMD) -o strip $(OBJECTS) $(LIBLD)
#
main.o:  $(COMSTRIP)/main.c $(COMINC)/filehdr.h $(COMINC)/ldfcn.h $(M32INC)/paths.h \
	 $(M32INC)/sgs.h
	$(CC_CMD) $(COMSTRIP)/main.c
#
setflags.o:  $(COMSTRIP)/setflags.c $(M32INC)/sgs.h $(COMSTRIP)/defs.h
	$(CC_CMD) $(COMSTRIP)/setflags.c
#
process.o:  $(COMSTRIP)/process.c $(COMINC)/filehdr.h $(COMINC)/ldfcn.h \
	    $(COMSTRIP)/defs.h $(M32INC)/paths.h $(M32INC)/sgs.h
	$(CC_CMD) $(COMSTRIP)/process.c
#
checkflags.o: $(COMSTRIP)/checkflags.c $(COMINC)/filehdr.h $(COMINC)/ldfcn.h
	$(CC_CMD) $(COMSTRIP)/checkflags.c
#
buildtmp.o:  $(COMSTRIP)/buildtmp.c $(COMINC)/filehdr.h $(COMINC)/ldfcn.h \
	     $(COMSTRIP)/defs.h
	$(CC_CMD) $(COMSTRIP)/buildtmp.c
#
buildfcns.o:  $(COMSTRIP)/buildfcns.c $(COMINC)/filehdr.h $(COMINC)/scnhdr.h \
	      $(COMINC)/reloc.h $(COMINC)/syms.h $(COMINC)/ldfcn.h \
	      $(COMINC)/storclass.h $(COMSTRIP)/defs.h $(M32INC)/sgs.h $(COMINC)/linenum.h
	$(CC_CMD) $(COMSTRIP)/buildfcns.c
#
copytmp.o:  $(COMSTRIP)/copytmp.c $(COMINC)/filehdr.h $(COMINC)/ldfcn.h \
	    $(COMSTRIP)/defs.h
	$(CC_CMD) $(COMSTRIP)/copytmp.c
#
fcns.o:  $(COMSTRIP)/fcns.c $(COMINC)/filehdr.h $(COMINC)/ldfcn.h $(M32INC)/sgs.h \
	 $(COMSTRIP)/defs.h
	$(CC_CMD) $(COMSTRIP)/fcns.c
#
#
save:	$(BINDIR)/$(SGS)strip
	-rm -f $(BINDIR)/$(SGS)strip.back
	cp $(BINDIR)/$(SGS)strip $(BINDIR)/$(SGS)strip.back
#
install:	$(BINDIR)/$(SGS)strip
#
$(BINDIR)/$(SGS)strip:	strip
	-rm -f $(BINDIR)/$(SGS)strip
# Place strip in temp location so that the correct strip command
# for installation will be used.
	mv strip strip.temp
	cp strip.temp $(BINDIR)/$(SGS)strip
	-$(STRIP_CMD) $(BINDIR)/$(SGS)strip
# Once strip has been stripped, we can restore it from the temporary
# location.
	mv strip.temp strip
#
stripit:	uninstall
uninstall:
	-rm -f $(BINDIR)/$(SGS)strip
#
lint:	$(COMSTRIP)/main.c $(COMSTRIP)/setflags.c $(COMSTRIP)/process.c \
	$(COMSTRIP)/checkflags.c $(COMSTRIP)/buildtmp.c $(COMSTRIP)/buildfcns.c \
	$(COMSTRIP)/copytmp.c $(COMSTRIP)/fcns.c \
	$(COMINC)/filehdr.h $(COMINC)/ldfcn.h $(COMINC)/scnhdr.h \
	$(COMINC)/reloc.h $(COMINC)/syms.h $(COMINC)/storclass.h \
	$(M32INC)/paths.h $(M32INC)/sgs.h $(COMSTRIP)/defs.h
	$(LINT_CMD) $(DEFLIST) $(INCLIST) $(COMSTRIP)/*.c
#
clean:	shrink
shrink:
	-rm -f $(OBJECTS) strip
