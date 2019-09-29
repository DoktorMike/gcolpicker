## Process this file with automake to produce Makefile.in

SUBDIRS = src po pixmaps

EXTRA_DIST = \
	autogen.sh \
	gcolor2.spec.in \
	gcolor2.glade \
	gcolor2.gladep

#install-data-local:
#	@$(NORMAL_INSTALL)
#	if test -d $(srcdir)/pixmaps; then \
#	  $(mkinstalldirs) $(DESTDIR)$(datadir)/$(PACKAGE)/pixmaps; \
#	  for pixmap in $(srcdir)/pixmaps/*; do \
#	    if test -f $$pixmap; then \
#	      $(INSTALL_DATA) $$pixmap $(DESTDIR)$(datadir)/$(PACKAGE)/pixmaps; \
#	    fi \
#	  done \
#	fi

#dist-hook:
#	if test -d pixmaps; then \
#	  mkdir $(distdir)/pixmaps; \
#	  for pixmap in pixmaps/*; do \
#	    if test -f $$pixmap; then \
#	      cp -p $$pixmap $(distdir)/pixmaps; \
#	    fi \
#	  done \
#	fi

