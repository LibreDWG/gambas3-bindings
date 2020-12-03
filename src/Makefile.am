COMPONENT = gb.dwg
include ../component.am

gblib_LTLIBRARIES = gb.dwg.la

gb_dwg_la_LIBADD = @LIBREDWG_LIBS@
gb_dwg_la_LDFLAGS = -no-undefined -module @LD_FLAGS@
gb_dwg_la_CFLAGS = @LIBREDWG_INC@

gb_dwg_la_SOURCES = main.h main.c \
                    c_dwg.h c_dwg.c c_dwg_gen.c

