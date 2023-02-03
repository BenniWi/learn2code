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
 && sudo apt-get install -y cmake lldb gdb ninja-build libgtest-dev clang clang-tools\
 && sudo rm -rf /var/lib/apt/lists/*
 
# install google chrome
RUN sudo wget https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb
RUN sudo apt install ./google-chrome-stable_current_amd64.deb
RUN sudo rm ./google-chrome-stable_current_amd64.deb

# install latest nodejs
RUN \
 sudo apt install -y curl \
 && curl -sL https://deb.nodesource.com/setup_18.x | sudo -E bash - \
 && sudo apt-get update \
 && sudo apt-get install -y nodejs

# install marp
RUN sudo npm install -g @marp-team/marp-cli
