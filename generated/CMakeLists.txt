cmake_minimum_required(VERSION 3.17)
project(example)

set(CMAKE_CXX_STANDARD 14)

add_executable(example main.cpp
ReduxStore.cpp ReduxStore.h
actions/ChangeDescriptionAction.cpp actions/ChangeDescriptionAction.g.cpp actions/ChangeDescriptionAction.h
actions/ChangeTagAction.cpp actions/ChangeTagAction.g.cpp actions/ChangeTagAction.h
State.cpp State.h Action.h Reducer.h ReduxStore.g.cpp ReduxStore.cpp ReduxStore.h
reducers/ChangeDescriptionReducer.cpp reducers/ChangeDescriptionReducer.g.cpp reducers/ChangeDescriptionReducer.h
)