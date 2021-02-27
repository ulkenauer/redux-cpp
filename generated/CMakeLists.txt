cmake_minimum_required(VERSION 3.17)
include(FetchContent)

project(example)

set(CMAKE_CXX_STANDARD 14)
add_executable(example main.cpp
        export/redux/ReduxStore.h
        module/actions/ChangeDescriptionAction.h module/actions/ChangeTagAction.h
        module/generated/State.cpp module/generated/State.h export/redux/IReducer.h
        module/reducers/ChangeDescriptionReducer.cpp module/reducers/ChangeDescriptionReducer.h
        export/redux/ActionMetadata.h export/redux/WrappedAction.h module/generated/utils/WrappedActionFactory.cpp module/generated/utils/WrappedActionFactory.h export/redux/ReducerMetadata.h export/redux/WrappedReducer.h module/generated/utils/WrappedReducerFactory.cpp module/generated/utils/WrappedReducerFactory.h module/generated/StoreBuilder.cpp module/generated/StoreBuilder.h)

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