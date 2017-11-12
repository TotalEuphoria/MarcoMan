#OBJS specifies which files to compile as part of the project
OBJS = main.cpp Game.cpp Player.cpp Map.cpp Block.cpp Texture.cpp Scenario.cpp Collision.cpp StaticEntity.cpp MovingEntity.cpp Physics.cpp Point.cpp Vector.cpp Timer.cpp

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w -std=c++14

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lboost_system -lboost_filesystem

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = marcoman

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
