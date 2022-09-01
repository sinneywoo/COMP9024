cmake_minimum_required(VERSION 3.22)
project(assignment)

set(CMAKE_CXX_STANDARD 14)

add_executable(assignment list.h list.c graph.h graph.c pagerank.h dijkstra.h main.c mainG.c crawler.c)
