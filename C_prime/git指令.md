# Git基础及进阶使用教程<1.git的安装>

## Git的介绍及安装教学

### Git是什么

Git作为一种世界上最先进的分布式版本控制系统，克隆项目的速度非常快。每个开发都可以从master上克隆本地版本库，就算没有网络，也可以提交代码到本地仓库、查看log、创建项目分支等等。

每个版本库都可以创建无限个分支，分支是个完整的目录，且这个目录拥有完整的实际文件，所以可以有效并且高效的处理从很小到非常大的版本项目管理。

### Git的安装

#### Mac上的安装

##### homebrew的安装

在Mac上安装并使用git，推荐各位首先下载***homebrew***，***homebrew***作为一款Mac OS平台下的软件包管理工具，拥有安装、卸载、更新、查看、搜索等很多实用的功能。简单的一条指令，就可以实现包管理，而不用你关心各种依赖和文件路径的情况，十分方便快捷。而且***homebrew***的安装也非常简单：

1. 打开终端(terminal);

2. 安装命令:

   ```ABAP
         命令1:/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"（这个命令不好使会报错，如果报错尝试使用命令2）
         命令2:/bin/zsh -c "$(curl -fsSL https://gitee.com/cunkai/HomebrewCN/raw/master/Homebrew.sh)"//(这是一个脚本，同样可以安装Homebrew)
   ```

这样***homebrew***就安装成功了，下面给出一些homebrew的基础命令：

- 1.查看Homebrew命令：***brew*** ***help***
- 2.安装任意包：***brew install <packageName>***，e.g.：brew install node
- 3.卸载任意包：***brew uninstall <packageName>***，e.g.：brew uninstall git
- 4.查询可用包：***brew search <packageName>***
- 5.查询已安装包列表：***brew*** ***list***
- 6.查看任意包信息：***brew info <packageName>***
- 7.更新Homebrew：***brew update***
- 8.Homebrew帮助信息：***brew -h***
- 9.查看brew版本：***brew -v***
- 10.更新brew版本：**brew update**
- 11.整理重复语句：***open ~/.zshrc -e、open ~/.bash_profile -e***

我们在Mac上安装homebrew，就打开终端输入下列指令即可：

```
brew install git
```

##### git安装成功后的检查

我们输入指令后如何检查git是否安装成功呢？接下来，在终端中使用

```
git --version
```

指令即可判断，如果成功弹出git的相关版本信息，就已经成功安装好git了。

#### Windows上的安装

在Windows上使用Git，可以从Git官网上直接下载安装程序，选择指定的系统下载，然后按默认选项安装即可。安装完成后，在开始菜单里找到“Git”->“Git Bash”，显示出类似命令行的窗口，说明Git安装成功。

下载地址： [Git - Downloads (git-scm.com)https://git-scm.com/downloads](https://git-scm.com/downloads) 

同样的在cmd内输入git --version 查看git的版本信息。

___

至此，最基础的git的安装教学就已经介绍完啦，还没有下载git的各位快去试试吧～

## Git的