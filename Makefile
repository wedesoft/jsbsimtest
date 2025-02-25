.SUFFIXES: .cpp .o

CXX = g++
CXXFLAGS = -I/usr/local/include/JSBSim
LDFLAGS = -lJSBSim

jsbsimtest: jsbsimtest.o
	$(CXX) -o jsbsimtest jsbsimtest.o $(LDFLAGS)

.cpp.o:
	$(CXX) -c -o $@ $(CXXFLAGS) $<
