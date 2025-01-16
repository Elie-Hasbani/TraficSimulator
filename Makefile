CXX = g++
CXXFLAGS = 
MAP_FLAG = -DMAP

OBJS = main2.o Vehicule.o Road.o Signalisation.o Simulation.o 
TARGET = main

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(MAP_FLAG) -o $(TARGET) $(OBJS)

main2.o: main2.cpp Vehicule.h Road.h Signalisation.h Simulation.h
	$(CXX) $(CXXFLAGS) $(MAP_FLAG) -c main2.cpp

Vehicule.o: Vehicule.cpp Vehicule.h
	$(CXX) $(CXXFLAGS) $(MAP_FLAG) -c Vehicule.cpp

Road.o: Road.cpp Road.h 
	$(CXX) $(CXXFLAGS) $(MAP_FLAG) -c Road.cpp

Signalisation.o: Signalisation.cpp Signalisation.h 
	$(CXX) $(CXXFLAGS) $(MAP_FLAG) -c Signalisation.cpp

Simulation.o: Simulation.cpp Simulation.h 
	$(CXX) $(CXXFLAGS) $(MAP_FLAG) -c Simulation.cpp



clean:
	del *.o 
	del *.exe