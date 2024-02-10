cmake_minimum_required(VERSION 3.10)

project(BinPacking3D)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ajouter les fichiers source
set(SOURCES
    src/main.cpp
    src/Item.cpp
    src/Container.cpp
    src/Utils.cpp
    src/BinPackingAlgorithm.cpp 
)

# Ajouter les fichiers d'en-tête
set(HEADERS
    include/Item.h
    include/Container.h
    include/Utils.h
    include/BinPackingAlgorithm.h 
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC include)

