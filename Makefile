.SUFFIXES: .cpp .o

CXX = g++
CXXFLAGS = -I/usr/local/include/JSBSim
LDFLAGS = -lJSBSim
OBJS = jsbsimtest.o

jsbsimtest: $(OBJS)
	$(CXX) -o jsbsimtest $(OBJS) $(LDFLAGS)

clean:
	rm -f jsbsimtest *.o

.cpp.o:
	$(CXX) -c -o $@ $(CXXFLAGS) $<
