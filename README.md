# learn2code

This repository contains slides, exercise examples and more for my lecture "Software Development".

All documents are located in the folder [docs](docs). The documents are completely written in markdown and are optimized for [marp](https://marp.app/).


1. [Prepared Environments](#prepared-environments)
2. [How to Create the Slides](#how-to-create-the-slides)
3. [How to Build the Code](#how-to-build-the-code)

## Prepared Environments 

[![Open in GitHub Codespaces](https://github.com/codespaces/badge.svg)](https://github.com/codespaces/new?hide_repo_select=true&ref=main&repo=545666306&machine=basicLinux32gb&location=WestEurope)

<a href="https://gitpod.io/#git@github.com:BenniWi/learn2code.git">
  <img
    src="https://img.shields.io/badge/Contribute%20with-Gitpod-908a85?logo=gitpod"
    alt="Contribute with Gitpod"
  />
</a>

## How to Create the Slides

### Install Latest nodejs
https://tecadmin.net/install-latest-nodejs-npm-on-ubuntu/
```sh
sudo apt install -y curl 
curl -sL https://deb.nodesource.com/setup_18.x | sudo -E bash - 
```

### Install Marp
```sh
npm install -g @marp-team/marp-cli
```

### Install google-chrome
```sh
wget -q https://dl.google.com/linux/direct/google-chrome-stable_current_amd64.deb
sudo apt-get install ./google-chrome-stable_current_amd64.deb
rm ./google-chrome-stable_current_amd64.deb
```

### Possible Marp Call
```sh
marp -c docs/marp_config.yaml docs/slides_learn2code_1.md
```

## How to Build the Code
Most of the code samples are supporting [CMake](https://cmake.org/).
All *CMake* capable samples are collected in the top-level [CMakeLists.txt](CMakeLists.txt).
Configure this top level project and your good to go.

For all non CMake samples you should use the compiler of your joice (mostly [gcc](https://gcc.gnu.org/) or [clang](https://clang.llvm.org/) and build it manually.
