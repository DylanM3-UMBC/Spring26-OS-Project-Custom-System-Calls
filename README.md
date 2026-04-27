# Project title - OS Project Custom System Calls


## Project overview
- This project tests the basic implementation of custom system calls. The custom system calls that is implemented in this project are a Print of Hello World and syscall version of Memcpy


## Purpose 
- This project is made to practice and learn the basic OS cpncepts of creating custom system calls and how the userspace interacts with the kernelspace


## Technologies used
1. A Virtual Box with Debian 11 and Linux Kernel 5.15.67


## Setup/installation: How to Compile
1. step one: execute command "g++ test.c -o test"
2. step two: execute command "./test" to run test


## Key features/functionality/Example usage
1. Can print hello world when ./test is run


# Lesson notes:
1. The macro of SYSCALL_DEFINE takes a specified number arguments when defined. For instance SYSCALL_DEFINE0 has 0 to state that it takes no arguments and SYSCALL_DEFINE3 takes 3 arguments


# My role or contribution
- As a student in operating systems class I coded a test file to test the two custom system calls I implemented of memcpy and print of hello world
