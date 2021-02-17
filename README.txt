# ---------------------- SET LOCALE -----------------------------------------------------
sudo apt update && sudo apt install locales
sudo locale-gen en_US en_US.UTF-8
sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
export LANG=en_US.UTF-8
# ---------------------- SET LOCALE ----------------------------------------------------




# ---------------------- ADD THE ROS2 APT REPOSITORY -----------------------------------
sudo apt update && sudo apt install curl gnupg2 lsb-release
curl -s https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | sudo apt-key add -
sudo sh -c 'echo "deb [arch=$(dpkg --print-architecture)] http://packages.ros.org/ros2/ubuntu $(lsb_release -cs) main" > /etc/apt/sources.list.d/ros2-latest.list'
# ---------------------- ADD THE ROS2 APT REPOSITORY -----------------------------------




# ---------------------- INSTALL ROS2 PACKAGES -----------------------------------------
sudo apt install ros-foxy-desktop
sudo apt install ros-foxy-ros-base
# ---------------------- INSTALL DEVELOPMENT TOOLS AND ROS TOOLS ----------------------




# ---------------------- RNN DEMO -----------------------------------------------------
source /opt/ros/foxy/setup.bash
source videoSummarization/build_and_env_setup.bash
ros2 run injest_pkg injest
# ---------------------- RNN DEMO -----------------------------------------------------