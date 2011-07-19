srcdir = /home/xwp/tao1/pycoming/net/test1/httpd-2.2.4/srclib/apr/test
VPATH = /home/xwp/tao1/pycoming/net/test1/httpd-2.2.4/srclib/apr/test

# PROGRAMS includes all test programs built on this platform.
# STDTEST_PORTABLE
#   test programs invoked via standard user interface, run on all platforms
# STDTEST_NONPORTABLE
#   test programs invoked via standard user interface, not portable
# OTHER_PROGRAMS
#   programs such as sendfile, that have to be invoked in a special sequence
#   or with special parameters

STDTEST_PORTABLE = \
	testlockperf \
	testshmproducer \
	testshmconsumer \
	testmutexscope \
	testall

OTHER_PROGRAMS = sendfile 

PROGRAMS = $(STDTEST_PORTABLE) $(STDTEST_NONPORTABLE) $(OTHER_PROGRAMS)

TARGETS = $(PROGRAMS)

# bring in rules.mk for standard functionality
include /home/xwp/tao1/pycoming/net/test1/httpd-2.2.4/srclib/apr/build/apr_rules.mk

LOCAL_LIBS=../libapr-${APR_MAJOR_VERSION}.la

CLEAN_TARGETS = testfile.tmp mod_test.slo proc_child occhild \
	readchild tryread sockchild \
	globalmutexchild lfstests/large.bin \
	data/test*.txt data/test*.dat
CLEAN_SUBDIRS = internal

INCDIR=../include
INCLUDES=-I$(INCDIR) -I$(srcdir)/../include

# link programs using -no-install to get real executables not
# libtool wrapper scripts which link an executable when first run.
LINK_PROG = $(LIBTOOL) $(LTFLAGS) --mode=link $(LT_LDFLAGS) $(COMPILE) -no-install $(ALL_LDFLAGS) -o $@

check: $(STDTEST_PORTABLE) $(STDTEST_NONPORTABLE)
	for prog in $(STDTEST_PORTABLE) $(STDTEST_NONPORTABLE); do \
		./$$prog; \
		if test $$? = 255; then \
			echo "$$prog failed"; \
			break; \
		fi; \
	done

occhild: occhild.lo $(LOCAL_LIBS)
	$(LINK_PROG) occhild.lo $(LOCAL_LIBS) $(ALL_LIBS)

sockchild: sockchild.lo $(LOCAL_LIBS)
	$(LINK_PROG) sockchild.lo $(LOCAL_LIBS) $(ALL_LIBS)

readchild: readchild.lo $(LOCAL_LIBS)
	$(LINK_PROG) readchild.lo $(LOCAL_LIBS) $(ALL_LIBS)

globalmutexchild: globalmutexchild.lo $(LOCAL_LIBS)
	$(LINK_PROG) globalmutexchild.lo $(LOCAL_LIBS) $(ALL_LIBS)

tryread: tryread.lo $(LOCAL_LIBS)
	$(LINK_PROG) tryread.lo $(LOCAL_LIBS) $(ALL_LIBS)

proc_child: proc_child.lo $(LOCAL_LIBS)
	$(LINK_PROG) proc_child.lo $(LOCAL_LIBS) $(ALL_LIBS)

# FIXME: -prefer-pic is only supported with libtool-1.4+
mod_test.slo: $(srcdir)/mod_test.c
	$(LIBTOOL) $(LTFLAGS) --mode=compile $(COMPILE) -prefer-pic -c $(srcdir)/mod_test.c && touch $@

mod_test.la: mod_test.slo $(LOCAL_LIBS)
	$(LIBTOOL) $(LTFLAGS) --mode=link $(COMPILE) -rpath `pwd` -avoid-version -module mod_test.lo $(LT_LDFLAGS) $(ALL_LDFLAGS) -o $@

libmod_test.la: mod_test.slo $(LOCAL_LIBS)
	$(LIBTOOL) $(LTFLAGS) --mode=link $(COMPILE) -rpath `pwd` -avoid-version mod_test.lo $(LT_LDFLAGS) $(ALL_LDFLAGS) -o $@ $(LOCAL_LIBS) $(ALL_LIBS)

testlockperf: testlockperf.lo $(LOCAL_LIBS)
	$(LINK_PROG) testlockperf.lo $(LOCAL_LIBS) $(ALL_LIBS)

sendfile: sendfile.lo $(LOCAL_LIBS)
	$(LINK_PROG) sendfile.lo $(LOCAL_LIBS) $(ALL_LIBS)

testshmproducer: testshmproducer.lo $(LOCAL_LIBS)
	$(LINK_PROG) testshmproducer.lo $(LOCAL_LIBS) $(ALL_LIBS)

testshmconsumer: testshmconsumer.lo $(LOCAL_LIBS)
	$(LINK_PROG) testshmconsumer.lo $(LOCAL_LIBS) $(ALL_LIBS)

testprocmutex: testprocmutex.lo $(LOCAL_LIBS)
	$(LINK_PROG) testprocmutex.lo $(LOCAL_LIBS) $(ALL_LIBS)

testmutexscope: testmutexscope.lo $(LOCAL_LIBS)
	$(LINK_PROG) testmutexscope.lo $(LOCAL_LIBS) $(ALL_LIBS)

TESTS = testutil.lo testtime.lo teststr.lo testvsn.lo testipsub.lo \
	testmmap.lo testud.lo testtable.lo testsleep.lo testpools.lo \
	testfmt.lo testfile.lo testdir.lo testfileinfo.lo testrand.lo \
	testdso.lo testoc.lo testdup.lo testsockets.lo testproc.lo \
	testpoll.lo testlock.lo testsockopt.lo testpipe.lo testthread.lo \
	testhash.lo testargs.lo testnames.lo testuser.lo testpath.lo \
	testenv.lo testprocmutex.lo testrand2.lo testfnmatch.lo \
        testatomic.lo testflock.lo testshm.lo testsock.lo testglobalmutex.lo \
        teststrnatcmp.lo testfilecopy.lo testtemp.lo testlfs.lo

testall: $(TESTS) mod_test.la libmod_test.la occhild \
	 readchild abts.lo proc_child \
         tryread sockchild globalmutexchild \
         $(LOCAL_LIBS)
	$(LINK_PROG) $(TESTS) abts.lo $(LOCAL_LIBS) $(ALL_LIBS)


# DO NOT REMOVE
