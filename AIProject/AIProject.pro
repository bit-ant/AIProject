TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        api/EightPuzzleNode.cpp \
        core/AStarSearch.cpp \
        core/HillClimbSearch.cpp \
        core/ManhattanHeuristic.cpp \
        core/MisplacedHeuristic.cpp \
        main.cpp

HEADERS += \
    api/EightPuzzleNode.h \
    api/IHeuristicFunction.h \
    api/ISearchAlgorithm.h \
    core/AStarSearch.h \
    core/HillClimbSearch.h \
    core/ManhattanHeuristic.h \
    core/MisplacedHeuristic.h
