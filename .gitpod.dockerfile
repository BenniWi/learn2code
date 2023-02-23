FROM gitpod/workspace-full

RUN \
 # bring in latest cmake
 sudo wget -qO /etc/apt/trusted.gpg.d/kitware-key.asc https://apt.kitware.com/keys/kitware-archive-latest.asc \ 
 && echo "deb https://apt.kitware.com/ubuntu/ focal main" | sudo tee /etc/apt/sources.list.d/kitware.list \
 && sudo add-apt-repository -y ppa:system76/pop \
 # bring in latest clang toolchain
 && wget https://apt.llvm.org/llvm.sh \
 && chmod +x llvm.sh \
 && sudo ./llvm.sh 16 all \
 && rm .llvm.sh \
 # install packages
 && sudo apt-get update \
 && sudo apt-get install -y build-essential cmake gdb ninja-build libgtest-dev chromium\
 # clean up
 && sudo rm -rf /var/lib/apt/lists/*

