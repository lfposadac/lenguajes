CXXFLAGS=

pcalc: main.cpp scanner.cpp token.cpp parser.cpp scanner.h token.h parser.h
	$(CXX) -o $@ $^ -Wall

clean:
	rm -f pcalc
