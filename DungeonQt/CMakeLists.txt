cmake_minimum_required(VERSION 3.23)
project(PG2_DungeonCrawler)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PG2_DungeonCrawler
        AbstractUI.cpp
        AbstractUI.h
        Character.cpp
        Character.h
        Dungeoncrawler.cpp
        Dungeoncrawler.h
        Floor.cpp
        Floor.h
        Level.cpp
        Level.h
        Aktive.cpp
        Aktive.h
        main.cpp
        Portal.cpp
        Portal.h
        Tile.cpp
        Tile.h
        Wall.cpp
        Passive.cpp
        Passive.h
        Wall.h TerminalUI.cpp TerminalUI.h Door.cpp Door.h Switch.cpp Switch.h Pit_Rampe.cpp Pit_Rampe.h AbstractController.cpp AbstractController.h)
