METHOD ?= opt

appname := vtable
full_appname := $(appname)-$(METHOD)

#CXX := mpicxx
CXXFLAGS := -std=c++11

srcfiles := $(shell find . -name "*.C")
objects	 := $(patsubst %.C, %-$(METHOD).o, $(srcfiles))

INC_DIRS := $(shell find include -type d -not -path "*/.svn*")
INCLUDES  := $(foreach i, $(INC_DIRS), -I$(i))

all: $(full_appname)

$(appname)-opt: $(objects)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -Wall -Wextra -Wpedantic -g -fno-omit-frame-pointer -O3 -o $(full_appname) $(objects) $(LDLIBS)

$(appname)-dbg: $(objects)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -Wall -Wextra -Wpedantic -g -fno-omit-frame-pointer -o $(full_appname) $(objects) $(LDLIBS)

%-opt.o: %.C
	$(CXX) -c $(CXXFLAGS) $(LDFLAGS) -Wall -Wextra -Wpedantic -g -fno-omit-frame-pointer -O3 -MMD -MP -MF $@.d $(INCLUDES) -MT $@ $< -o $@ $(LDLIBS)

%-dbg.o: %.C
	$(CXX) -c $(CXXFLAGS) $(LDFLAGS) -Wall -Wextra -Wpedantic -g -fno-omit-frame-pointer -MMD -MP -MF $@.d $(INCLUDES) -MT $@ $< -o $@ $(LDLIBS)

clean:
	rm -f *.o
	rm -f $(objects)
	rm -f $(full_appname)
	rm -rf *.d
	rm -rf problem1
	rm -rf problem2
	rm -f *~*

-include $(patsubst %, %-opt.o.d, $(basename $(srcfiles)))
