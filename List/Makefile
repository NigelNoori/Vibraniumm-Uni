CXX = g++
CXXFLAGS = -std=c++11 -Wall

# List of source files
SOURCES = List.cc prob1.cc

# Object files corresponding to source files
OBJECTS = $(SOURCES:.cc=.o)

# Executable name
EXECUTABLE = prob1

# Rule to compile .cc files into .o files
%.o: %.cc
    $(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to link object files into the executable
$(EXECUTABLE): $(OBJECTS)
    $(CXX) $(OBJECTS) -o $(EXECUTABLE)

# Clean rule to remove object files and the executable
clean:
    rm -f $(OBJECTS) $(EXECUTABLE)
