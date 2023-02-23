FROM gitpod/workspace-full

RUN \
 # bring in latest cmake
 sudo wget -qO /etc/apt/trusted.gpg.d/kitware-key.asc https://apt.kitware.com/keys/kitware-archive-latest.asc \ 
 && echo "deb https://apt.kitware.com/ubuntu/ focal main" | sudo tee /etc/apt/sources.list.d/kitware.list \
 && sudo add-apt-repository -y ppa:system76/pop \
# bring in latest clang toolchain
 && sudo add-apt-repository "deb http://apt.llvm.org/focal/ llvm-toolchain-focal-16 main"\
 && sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 15CF4D18AF4F7421 \
 # install packages
 && sudo apt-get update \
 && sudo apt-get install -y build-essential cmake gdb ninja-build libgtest-dev chromium clangd lldb clang clang-tools clang-format clang-tidy\
 # install latest llvm tools like clang etc.
 && sudo bash -c "$(wget -O - https://apt.llvm.org/llvm.sh)"\
 # clean up
 && sudo rm -rf /var/lib/apt/lists/*

