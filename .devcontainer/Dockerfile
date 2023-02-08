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
 && sudo apt-get install -y build-essential cmake lldb gdb ninja-build libgtest-dev clang clang-tools clang-format wget curl
 
# install google chrome
RUN \
 sudo apt-get update \
 && sudo apt-get install -y fonts-liberation libasound2 libatk-bridge2.0-0 libatk1.0-0 libatspi2.0-0 libcairo2 libcups2\
 libdrm2 libgbm1 libgtk-3-0 libnspr4 libnss3 libpango-1.0-0 libu2f-udev libvulkan1 libx11-6 libxcb1 libxcomposite1\
 libxdamage1 libxext6 libxfixes3 libxkbcommon0 libxrandr2 xdg-utils
RUN wget -q https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb
RUN sudo dpkg -i google-chrome-stable_current_amd64.deb
RUN sudo apt -f install -y
RUN rm ./google-chrome-stable_current_amd64.deb

# install latest nodejs
RUN \
 sudo apt install -y curl \
 && curl -sL https://deb.nodesource.com/setup_18.x | sudo -E bash - \
 && sudo apt-get update \
 && sudo apt-get install -y nodejs

# install marp
RUN sudo npm install -g @marp-team/marp-cli

# clean up
RUN sudo rm -rf /var/lib/apt/lists/*
