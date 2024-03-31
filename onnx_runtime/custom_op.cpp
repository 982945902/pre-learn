// custom_op.cpp
#include <onnxruntime/core/providers/cpu/cpu_provider_factory.h>
#include <onnxruntime/core/framework/op_kernel.h>

namespace onnxruntime {

class CustomOpKernel : public OpKernel {
public:
    explicit CustomOpKernel(const OpKernelInfo& info) : OpKernel(info) {
        // 读取和解析自定义操作的参数
        // ...
    }

    Status Compute(OpKernelContext* context) const override {
        // 获取输入和输出张量
        const Tensor* input_tensor = context->Input<Tensor>(0);
        Tensor* output_tensor = context->Output(0, input_tensor->Shape());

        // 执行自定义操作的前向计算逻辑
        // ...
        
        return Status::OK();
    }
};

// 注册自定义操作
ONNX_OPERATOR_KERNEL_EX(CustomOp,
                        "CustomOp",
                        1,
                        kCpuExecutionProvider,
                        KernelDefBuilder()
                            .InputMemoryType(OrtMemType::OrtMemTypeCPUInput, 0)
                            .OutputMemoryType(OrtMemType::OrtMemTypeCPUOutput, 0),
                        CustomOpKernel);

}  // namespace onnxruntime

// 导出创建和注册自定义操作的函数
ORT_API_STATUS_IMPL(OrtCustomOpRegister, int domain, const char* op_type, void* op_kernel_factory) {
    onnxruntime::CustomOpKernelFactory* factory = static_cast<onnxruntime::CustomOpKernelFactory*>(op_kernel_factory);
    ::onnxruntime::OpSchemaRegistry::DomainToVersionRange::Instance().AddDomainToVersion(domain, op_type, 1, 1);
    ::onnxruntime::OpSchemaRegistry::Instance().RegisterCustomOp(op_type, domain, factory);
    return nullptr;
}