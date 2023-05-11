JL_SHARE = $(shell julia -e 'print(joinpath(Sys.BINDIR, Base.DATAROOTDIR, "julia"))')
CXXFLAGS += $(subst -std=gnu99,,$(shell $(JL_SHARE)/julia-config.jl --cflags))
#CXXFLAGS += -DVERBOSE_IMPORT #To enable the verbose mode of the libray loading
#CXXFLAGS += -Wall -O0 -g     #To compile with debugger infomation
LDFLAGS  += $(shell $(JL_SHARE)/julia-config.jl --ldflags)
LDLIBS   += $(shell $(JL_SHARE)/julia-config.jl --ldlibs)

CXXWRAP_CPPFLAGS=-I $(shell julia -e 'using CxxWrap; print(CxxWrap.prefix_path() * "/include")') -std=c++17
CXXWRAP_LDFLAGS=-L $(shell julia -e 'using CxxWrap; print(CxxWrap.prefix_path() * "/lib")') -lcxxwrap_julia -lcxxwrap_julia_stl

#CXXFLAGS += -Wno-unused-variable -Wno-unused-but-set-variable -fmax-errors=3

CPPFLAGS += -MMD

LINK.o = $(CXX) $(LDFLAGS) $(TARGET_ARCH)
MODULE_NAME=Hello

CC_FILES=jlHello.cxx

.PHONY: all clean run_demo

.PRECIOUS: $(CC_FILES)

SOURCES = jlHello.cxx jl_NS_A_methods.cxx jl_NS_B_methods.cxx jl_NS_C_methods.cxx
OBJS = $(addsuffix .o, $(basename $(SOURCES)))
DEPS = $(addsuffix .d, $(basename $(SOURCES)))

PRODUCTS = jl$(MODULE_NAME).dylib

all: $(PRODUCTS)

clean:
	-$(RM) $(PRODUCTS) $(OBJS) $(DEPS)

jl%.cxx: %.wit
	wrapit --force $<

$(SOURCES): Hello.wit
	wrapit --force $<

%.o: %.cxx
	$(COMPILE.cc) $(CXXWRAP_CPPFLAGS) -o $@ $<

jl%.dylib: $(OBJS)
	$(LINK.o) -o $@ --shared -fPIC $(LDFLAGS) $(LDLIBS) $(CXXWRAP_LDFLAGS) $^
	touch $(MODULE_NAME).jl

echo_%:
	@echo $*=$($*)

run_demo: all
	source ./setup.sh && julia demo_$(MODULE_NAME).jl

