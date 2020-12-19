cmake_minimum_required(VERSION 3.17)
project(Lab_2_GitHub)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab_2 main.cpp
        ExecutionContext.h
        ExecutionContext.cpp
        Commands/ReadFile.h
        Commands/ReadFile.cpp
        Commands/WriteFile.h
        Commands/WriteFile.cpp
        Commands/Sort.h
        Commands/Sort.cpp
        Commands/Grep.h
        Commands/Grep.cpp
        Commands/Replace.h
        Commands/Replace.cpp
        Commands/Dump.h
        Commands/Dump.cpp
        WorkFlowParser.h
        WorkFlowParser.cpp
        ArgumentsHandler.h
        ArgumentsHandler.cpp
        WorkFlowValidator.h
        WorkFlowValidator.cpp
        WorkFlowExecutor.h
        WorkFlowExecutor.cpp
        CommandsFactory.h
        CommandsFactory.cpp
        ICommandCreator.h
        )
