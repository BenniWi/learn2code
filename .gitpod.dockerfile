FROM gitpod/workspace-full

RUN \
 # bring in latest cmake
 sudo wget -qO /etc/apt/trusted.gpg.d/kitware-key.asc https://apt.kitware.com/keys/kitware-archive-latest.asc \ 
 && echo "deb https://apt.kitware.com/ubuntu/ focal main" | sudo tee /etc/apt/sources.list.d/kitware.list \
 && sudo add-apt-repository -y ppa:system76/pop \
 && sudo apt-get update \
 && sudo apt-get install -y build-essential cmake lldb gdb ninja-build libgtest-dev clang clang-tools clang-format chromium\
 && sudo rm -rf /var/lib/apt/lists/*
 # && sudo snap install marp-cli-carroarmato0 
