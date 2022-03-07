CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
    main.cpp
    src/Player.h
    src/PointGuard.h
    src/ShootingGuard.h
    src/SmallForward.h
    src/PowerForward.h
    src/center.h
    src/csvReader.h
    src/bestLineUpAlgorithm.h
    src/playerSorter.h
    src/teamSorter.h
    src/valueSorter.h
)
