## Process this file with automake to produce Makefile.in

gcolpicker_CPPFLAGS = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = gcolpicker

gcolpicker_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h

gcolpicker_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

