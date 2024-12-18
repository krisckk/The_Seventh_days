# Detect OS
ifeq ($(OS),Windows_NT)
    ALLEGRO_PATH = C:/allegro
    CXX = clang++
    ALLEGRO_LIBS = -lallegro_monolith -lsqlite3
    RM = del /Q
    EXE = The7Days.exe
else
    CXX = clang++
    ALLEGRO_LIBS = `pkg-config --libs allegro-5 allegro_main-5 allegro_font-5 allegro_dialog-5 allegro_primitives-5 allegro_image-5 allegro_ttf-5 allegro_audio-5 allegro_acodec-5` -lsqlite3
    RM = rm -f
    EXE = The7Days
endif

# Compiler flags
CXXFLAGS = -std=c++14 -I. -IEngine -IResource

# Source files
SOURCES = $(wildcard Engine/*.cpp) $(wildcard UI/Component/*.cpp) $(wildcard Scene/*.cpp) $(wildcard Scene/Act1/Glyswen/*.cpp) $(wildcard Scene/Act1/Bakery/*.cpp) $(wildcard Scene/Act1/Port/*.cpp) $(wildcard Scene/Act1/MushroomFarm/*.cpp) $(wildcard Scene/Act1/Saturday/*.cpp) $(wildcard Scene/Act1/Sunday/*.cpp) $(wildcard Scene/Act2/Monday/*.cpp) $(wildcard Scene/Act2/Tuesday/*.cpp) $(wildcard Scene/Act2/Wednesday/*.cpp) $(wildcard Scene/Act2/Thursday/*.cpp) $(wildcard Scene/Act2/Friday/*.cpp) $(wildcard Scene/Act2/Saturday/*.cpp) $(wildcard Scene/Ending/*.cpp) $(wildcard Shared/*.cpp) $(wildcard Character/*.cpp) main.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Build rules
all: $(EXE)

$(EXE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXE) $(ALLEGRO_LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(EXE)

.PHONY: all clean
