FROM mcr.microsoft.com/vscode/devcontainers/base:ubuntu-20.04

RUN \
 # bring in latest cmake
 sudo wget -qO /etc/apt/trusted.gpg.d/kitware-key.asc https://apt.kitware.com/keys/kitware-archive-latest.asc \ 
 && echo "deb https://apt.kitware.com/ubuntu/ focal main" | sudo tee /etc/apt/sources.list.d/kitware.list \
 && sudo apt-get update \
 # need that to get add-apt-repository
 && sudo apt-get install -y software-properties-common \ 
 && sudo add-apt-repository -y ppa:system76/pop \
 && sudo apt-get update \
 && sudo apt-get install -y cmake lldb gdb ninja-build libgtest-dev clang clang-tools chromium\
 && sudo rm -rf /var/lib/apt/lists/*
