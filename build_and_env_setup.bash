export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./local_stream_pkg/install/local_stream_pkg/lib/local_stream_pkg/
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./onnx_pool_pkg/install/onnx_pool_pkg/lib/onnx_pool_pkg/

[ -d "local_stream_pkg/build"   ] && rm -r local_stream_pkg/build 
[ -d "local_stream_pkg/install" ] && rm -r local_stream_pkg/install 
[ -d "local_stream_pkg/log"     ] && rm -r local_stream_pkg/log
[ -d "onnx_pool_pkg/build"      ] && rm -r onnx_pool_pkg/build 
[ -d "onnx_pool_pkg/install"    ] && rm -r onnx_pool_pkg/install 
[ -d "onnx_pool_pkg/log"        ] && rm -r onnx_pool_pkg/log
[ -d "injest_pkg/build"         ] && rm -r injest_pkg/build 
[ -d "injest_pkg/install"       ] && rm -r injest_pkg/install 
[ -d "injest_pkg/log"           ] && rm -r injest_pkg/log

(cd local_stream_pkg && colcon build --cmake-args -DCMAKE_BUILD_TYPE=RelWithDebInfo)
(cd onnx_pool_pkg && colcon build --cmake-args -DCMAKE_BUILD_TYPE=RelWithDebInfo)
(cd injest_pkg && colcon build --cmake-args -DCMAKE_BUILD_TYPE=RelWithDebInfo)

source ./local_stream_pkg/install/setup.bash
source ./onnx_pool_pkg/install/setup.bash
source ./injest_pkg/install/setup.bash
