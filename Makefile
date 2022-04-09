experiment:
	g++ -std=c++11 -xc++ -static-libstdc++ -shared-libgcc src/utils.cpp src/algorithms.cpp src/experiment.cpp -o bin/experiment

