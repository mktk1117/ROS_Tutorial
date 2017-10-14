# phenox-ros
This is a tutorial of the group, phenox-ros.

## Git
#### Basic Commands
Some examples from [Basic Git commands](https://confluence.atlassian.com/bitbucketserver/basic-git-commands-776639767.html).
- git clone /path/to/repository
    - Create a working copy of a local repository
- git add <filename>
    - Add one or more files to staging.
- git commit -m "Commit message"
    - Commit any files you've added with git add, and also commit any files you've changed since then.
- git push origin master
    - Send changes to the master branch of your remote repository.
- git status
    - List the files you've changed and those you still need to add or commit.
- git pull
    - Fetch and merge changes on the remote server to your working directory.
- git push origin <branchname>
    - Push the branch to your remote repository, so others can use it.

#### Add ssh key to gitlab
Its more convinient to use ssh rather than https.  
[GitLab Documentation SSH](https://docs.gitlab.com/ce/ssh/README.html)  
[SSH認証キーをGitLabに登録・設定手順 覚書](https://qiita.com/redamoon/items/07e445d1fce360cb5fa3)


## ROS
- [ROS](http://wiki.ros.org/)
- [ROS Tutorials](http://wiki.ros.org/ROS/Tutorials)
- [ROS チュートリアル(ja)](http://wiki.ros.org/ja/ROS/Tutorials)

If you have not installed ROS yet, install it first and complete the rosdep initialization.

### Install dependencies
```bash
sudo apt-get install python-rosinstall -y
sudo apt-get install python-catkin-tools -y
sudo apt-get install ros-kinetic-geometry -y
```

### Setup workspace
We explain with ROS kinetc. If you use other version, please replace with your version.
```bash
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws
catkin init
catkin config --extend /opt/ros/kinetic
catkin config --cmake-args -DCMAKE_BUILD_TYPE=Release
catkin config --merge-devel # this is important, otherwise you may get weird linking errors
cd src
wstool init
wstool set --git tutorial https://github.com/mktk1117/ROS_Tutorial.git -y
wstool update
wstool merge tutorial/rosinstall/ethz_asl.rosinstall
wstool update -j8
echo "source ~/catkin_ws/devel/setup.bash" >> ~/.bashrc
source ~/.bashrc
```

### Set up ccache

ccache is a tool that caches intermediate build files to speed up rebuilds of the same code. On Ubuntu it can be set up with the following command.
```bash
sudo apt-get install -y ccache
echo 'export PATH="/usr/lib/ccache:$PATH"' | tee -a ~/.bashrc \
&& source ~/.bashrc && echo $PATH
```
### Build
Compile the repositories.
```bash
cd ~/catkin_ws
catkin build
```

### Errors
- If you are using Jetson, and have an error of config.guess at glog_catkin, replace config.guess and config.sub.

```bash
cp ~/catkin_ws/src/tutorial/glog_files_jetson/config.guess ~/catkin_ws/build/glog_catkin/glog_src-prefix/src/glog_src/
cp ~/catkin_ws/src/tutorial/glog_files_jetson/config.sub ~/catkin_ws/build/glog_catkin/glog_src-prefix/src/glog_src/
```
- If there is an error with libGL.so on jetson, follow the command below.

```bash
cd /usr/lib/aarch64-linux-gnu
sudo rm libGL.so
sudo ln -s /usr/lib/aarch64-linux-gnu/tegra/libGL.so libGL.so
```
