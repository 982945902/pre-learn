//

#include <dlpack/dlpack.h>
#include <tvm/runtime/c_runtime_api.h>
#include <tvm/runtime/crt/module.h>

int main() {
  TVMModuleHandle mod_factory;
  int dtype_code = kDLFloat, dtype_bits = 32, dtype_lanes = 1;
  int device_type = kDLCPU, device_id = 0;

  // 加载模型库
  TVMFuncCall(TVMModuleLoadFromFile, "/root/module.so", &mod_factory);
  // 创建模型实例
  TVMModuleHandle graph_runtime_module;
  TVMFuncCall(mod_factory, "default", &graph_runtime_module);
  return 0;
}