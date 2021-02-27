cmake_minimum_required(VERSION 3.17)
include(FetchContent)

project(example)

set(CMAKE_CXX_STANDARD 14)
add_executable(example main.cpp
        export/redux/ReduxStore.h
actions/ChangeDescriptionAction.h actions/ChangeTagAction.h
State.cpp State.h export/redux/IReducer.h
reducers/ChangeDescriptionReducer.cpp reducers/ChangeDescriptionReducer.g.cpp reducers/ChangeDescriptionReducer.h
        export/redux/ActionMetadata.h export/redux/WrappedAction.h actions/utils/WrappedActionFactory.cpp actions/utils/WrappedActionFactory.h export/redux/ReducerMetadata.h export/redux/WrappedReducer.h reducers/utils/WrappedReducerFactory.cpp reducers/utils/WrappedReducerFactory.h StoreBuilder.cpp StoreBuilder.h)

#FetchContent_Declare(
#        testrepo
#        GIT_REPOSITORY git@github.com:ulkenauer/redux-cpp.git
#        GIT_TAG        master
#)
##FetchContent_MakeAvailable(testrepo)
#FetchContent_Populate(testrepo)
#
##FetchContent_GetProperties(testrepo)
##if(NOT testrepo_POPULATED)
##    FetchContent_Populate(testrepo)
##endif()
##add_subdirectory(${testrepo_SOURCE_DIR} ${testrepo_BINARY_DIR})
target_include_directories(example PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/export>)