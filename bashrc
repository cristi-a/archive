# C++ aliases
alias g++11f='g++ -DLOCAL_DEFINE -std=c++11 -Wall -Wextra -Wshadow -Wunused -O2'
alias g++11='g++ -DLOCAL_DEFINE -std=c++11 -Wall -Wextra -Wshadow -Wunused -fsanitize=address,undefined -g'

make() {
  if [ -f "grader.cpp" ]; then
    g++11 -o $1 $1.cpp grader.cpp
  else
    g++11 -o $1 $1.cpp
  fi
}

run() {
  make $1
  ./$1
}

makef() {
  if [ -f "grader.cpp" ]; then
    g++11f -o $1 $1.cpp grader.cpp
  else
    g++11f -o $1 $1.cpp
  fi
}

submit() {
  cp $1.cpp ~/sol.cpp
}

export -f make
export -f run
export -f makef
export -f submit
