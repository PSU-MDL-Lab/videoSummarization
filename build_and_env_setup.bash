export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./local_stream_pkg/install/local_stream_pkg/lib/local_stream_pkg/
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./net_stream_pkg/install/net_stream_pkg/lib/net_stream_pkg/
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./compute_pool_pkg/install/compute_pool_pkg/lib/compute_pool_pkg/

[ -d "local_stream_pkg/build"   ] && rm -r local_stream_pkg/build 
[ -d "local_stream_pkg/install" ] && rm -r local_stream_pkg/install 
[ -d "local_stream_pkg/log"     ] && rm -r local_stream_pkg/log
[ -d "net_stream_pkg/build"     ] && rm -r net_stream_pkg/build 
[ -d "net_stream_pkg/install"   ] && rm -r net_stream_pkg/install 
[ -d "net_stream_pkg/log"       ] && rm -r net_stream_pkg/log
[ -d "compute_pool_pkg/build"   ] && rm -r compute_pool_pkg/build 
[ -d "compute_pool_pkg/install" ] && rm -r compute_pool_pkg/install 
[ -d "compute_pool_pkg/log"     ] && rm -r compute_pool_pkg/log
[ -d "injest_pkg/build"         ] && rm -r injest_pkg/build 
[ -d "injest_pkg/install"       ] && rm -r injest_pkg/install 
[ -d "injest_pkg/log"           ] && rm -r injest_pkg/log

(cd local_stream_pkg && colcon build --cmake-args -DCMAKE_BUILD_TYPE=RelWithDebInfo)
(cd net_stream_pkg && colcon build --cmake-args -DCMAKE_BUILD_TYPE=RelWithDebInfo)
(cd compute_pool_pkg && colcon build --cmake-args -DCMAKE_BUILD_TYPE=RelWithDebInfo)
(cd injest_pkg && colcon build --cmake-args -DCMAKE_BUILD_TYPE=RelWithDebInfo)

source ./local_stream_pkg/install/setup.bash
source ./net_stream_pkg/install/setup.bash
source ./compute_pool_pkg/install/setup.bash
source ./injest_pkg/install/setup.bash
