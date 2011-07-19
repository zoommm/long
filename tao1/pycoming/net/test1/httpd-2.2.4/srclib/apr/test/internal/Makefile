srcdir = /home/xwp/tao1/pycoming/net/test1/httpd-2.2.4/srclib/apr/test/internal
VPATH = /home/xwp/tao1/pycoming/net/test1/httpd-2.2.4/srclib/apr/test/internal

NONPORTABLE = \
	testregex

PROGRAMS = \

TARGETS = $(PROGRAMS) $(NONPORTABLE)

# bring in rules.mk for standard functionality
include /home/xwp/tao1/pycoming/net/test1/httpd-2.2.4/srclib/apr/build/apr_rules.mk

LOCAL_LIBS=../../libapr-${APR_MAJOR_VERSION}.la

CLEAN_TARGETS = testregex

INCDIR=../../include
INCLUDES=-I$(INCDIR)

CFLAGS=$(MY_CFLAGS)

all: $(PROGRAMS) $(NONPORTABLE)

check: $(PROGRAMS) $(NONPORTABLE)
	for prog in $(PROGRAMS) $(NONPORTABLE); do \
		./$$prog; \
		if test $$i = 255; then \
			echo "$$prog failed"; \
			break; \
		fi \
	done

testregex: testregex.lo $(LOCAL_LIBS)
	$(LINK) testregex.lo $(LOCAL_LIBS) $(ALL_LIBS)

# DO NOT REMOVE
