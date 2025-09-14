# Modern C++ Challenges – My Solutions

This repository contains my **personal solutions** to the exercises from the book  
[*Modern C++ Challenges* by Marius Bancila](https://www.packtpub.com/product/modern-c-challenges/9781788993869).

⚠️ **Disclaimer**:  
The original problem statements are **not included** here to respect copyright.  
Only my own code and explanations are provided.  
For the official exercises and reference solutions, please refer to the  
[author’s GitHub repository](https://github.com/PacktPublishing/The-Modern-Cpp-Challenge).

---

## 📖 About the book
*Modern C++ Challenges* is a collection of 100 programming problems designed to help developers practice modern C++ (C++11/14/17/20).  
The challenges cover topics such as:
- General language features
- Data structures and algorithms
- Concurrency and parallelism
- Design patterns and best practices

---

## 🧑‍💻 My approach
For each challenge, I aim to:
1. Write **clean, idiomatic, and modern C++** code (RAII, smart pointers, constexpr, ranges, etc.).
2. Provide **tests** to validate correctness.
3. Optimize when possible (time/space complexity).
4. Compare my solutions to the [official ones](https://github.com/PacktPublishing/Modern-Cpp-Challenges) and sometimes propose **alternative approaches**.

---

## 📂 Repository structure
- 📂`github`
- 📂`challenges` all challenges
  - 📂`challenge_X` each challenge has his own folder
    - 📂`src` The OBJECT library with the challenge solutions.
    - 📂`test`All tests runs by GTest 
  - `create.sh` script to start a new challenge
  - `detect.sh` script to detect challenges and add it to the CMake project
- 📂`cmake`
- 📂`lib` custom libraries that I use une several challenges
- 📂`thirdparty`

## 🚀 How to build & run
This project uses **CMake** and requires a C++20 (or later) compiler.

```bash
mkdir build && cd build
cmake ..
make -j
ctest