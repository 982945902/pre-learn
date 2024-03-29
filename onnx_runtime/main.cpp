#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

#include "benchmark/benchmark.h"
#include "onnxruntime/onnxruntime_cxx_api.h"

static std::function<void(benchmark::State&)> static_call;

int main(int argc, char* argv[]) {
  // Initialize the session
  Ort::Env env(OrtLoggingLevel::ORT_LOGGING_LEVEL_WARNING, "test");
  Ort::SessionOptions session_options;
  session_options.SetIntraOpNumThreads(1);
  session_options.SetInterOpNumThreads(1);
  session_options.SetGraphOptimizationLevel(
      GraphOptimizationLevel::ORT_ENABLE_BASIC);

  //   Ort::Session session_{env, "model.onnx", session_options};
  Ort::Session session_{env, argv[1], session_options};

  auto memory_info =
      Ort::MemoryInfo::CreateCpu(OrtDeviceAllocator, OrtMemTypeCPU);
  Ort::Allocator alloc(session_, memory_info);

  auto input_shape =
      session_.GetInputTypeInfo(0).GetTensorTypeAndShapeInfo().GetShape();
  auto input_type =
      session_.GetInputTypeInfo(0).GetTensorTypeAndShapeInfo().GetElementType();
  auto input_name = session_.GetInputNameAllocated(0, alloc);
  const char* input_names[] = {input_name.get()};

  auto prue_input_shape = input_shape;
  prue_input_shape[0] = 1;
  auto element_count =
      std::accumulate(prue_input_shape.begin(), prue_input_shape.end(), 1,
                      std::multiplies<int64_t>());

  //   std::cout << element_count << std::endl;
  //   for (const auto& dim : prue_input_shape) std::cout << dim << " ";

  //   auto test_input = new float[element_count];
  std::vector<float> test_input = {0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.32941176470588235,
                                   0.7254901960784313,
                                   0.6235294117647059,
                                   0.592156862745098,
                                   0.23529411764705882,
                                   0.1411764705882353,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.8705882352941177,
                                   0.996078431372549,
                                   0.996078431372549,
                                   0.996078431372549,
                                   0.996078431372549,
                                   0.9450980392156862,
                                   0.7764705882352941,
                                   0.7764705882352941,
                                   0.7764705882352941,
                                   0.7764705882352941,
                                   0.7764705882352941,
                                   0.7764705882352941,
                                   0.7764705882352941,
                                   0.7764705882352941,
                                   0.6666666666666666,
                                   0.20392156862745098,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.2627450980392157,
                                   0.4470588235294118,
                                   0.2823529411764706,
                                   0.4470588235294118,
                                   0.6392156862745098,
                                   0.8901960784313725,
                                   0.996078431372549,
                                   0.8823529411764706,
                                   0.996078431372549,
                                   0.996078431372549,
                                   0.996078431372549,
                                   0.9803921568627451,
                                   0.8980392156862745,
                                   0.996078431372549,
                                   0.996078431372549,
                                   0.5490196078431373,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.06666666666666667,
                                   0.25882352941176473,
                                   0.054901960784313725,
                                   0.2627450980392157,
                                   0.2627450980392157,
                                   0.2627450980392157,
                                   0.23137254901960785,
                                   0.08235294117647059,
                                   0.9254901960784314,
                                   0.996078431372549,
                                   0.41568627450980394,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.3254901960784314,
                                   0.9921568627450981,
                                   0.8196078431372549,
                                   0.07058823529411765,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.08627450980392157,
                                   0.9137254901960784,
                                   1.0,
                                   0.3254901960784314,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.5058823529411764,
                                   0.996078431372549,
                                   0.9333333333333333,
                                   0.17254901960784313,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.23137254901960785,
                                   0.9764705882352941,
                                   0.996078431372549,
                                   0.24313725490196078,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.5215686274509804,
                                   0.996078431372549,
                                   0.7333333333333333,
                                   0.0196078431372549,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.03529411764705882,
                                   0.803921568627451,
                                   0.9725490196078431,
                                   0.22745098039215686,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.49411764705882355,
                                   0.996078431372549,
                                   0.7137254901960784,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.29411764705882354,
                                   0.984313725490196,
                                   0.9411764705882353,
                                   0.2235294117647059,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.07450980392156863,
                                   0.8666666666666667,
                                   0.996078431372549,
                                   0.6509803921568628,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.011764705882352941,
                                   0.796078431372549,
                                   0.996078431372549,
                                   0.8588235294117647,
                                   0.13725490196078433,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.14901960784313725,
                                   0.996078431372549,
                                   0.996078431372549,
                                   0.30196078431372547,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.12156862745098039,
                                   0.8784313725490196,
                                   0.996078431372549,
                                   0.45098039215686275,
                                   0.00392156862745098,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.5215686274509804,
                                   0.996078431372549,
                                   0.996078431372549,
                                   0.20392156862745098,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.23921568627450981,
                                   0.9490196078431372,
                                   0.996078431372549,
                                   0.996078431372549,
                                   0.20392156862745098,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.4745098039215686,
                                   0.996078431372549,
                                   0.996078431372549,
                                   0.8588235294117647,
                                   0.1568627450980392,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.4745098039215686,
                                   0.996078431372549,
                                   0.8117647058823529,
                                   0.07058823529411765,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0,
                                   0.0};

  auto input_tensor = Ort::Value::CreateTensor(
      memory_info, test_input.data(), element_count * sizeof(float),
      prue_input_shape.data(), prue_input_shape.size(), input_type);

  auto output_shape =
      session_.GetOutputTypeInfo(0).GetTensorTypeAndShapeInfo().GetShape();
  auto output_type = session_.GetOutputTypeInfo(0)
                         .GetTensorTypeAndShapeInfo()
                         .GetElementType();
  auto output_name = session_.GetOutputNameAllocated(0, alloc);
  const char* output_names[] = {output_name.get()};
  auto prue_output_shape = output_shape;
  prue_output_shape[0] = 1;
  element_count =
      std::accumulate(prue_output_shape.begin(), prue_output_shape.end(), 1,
                      std::multiplies<int64_t>());
  //   std::cout << "d1 " << element_count << " " << prue_output_shape.size()
  //             << std::endl;
  //   for (const auto& dim : prue_output_shape) std::cout << dim << " ";

  auto output_tensor = Ort::Value::CreateTensor(
      alloc, prue_output_shape.data(), prue_output_shape.size(), output_type);

  int targc = argc - 1;
  char* targv[targc];
  targv[0] = argv[0];
  for (int i = 2; i < argc; i++) {
    targv[i - 1] = argv[i];
  }

  for (int i = 0; i < targc; i++) std::cout << targv[i] << " ";
  std::cout << std::endl;

  benchmark::Initialize(&argc, targv);
  static_call = [&](benchmark::State& state) {
    for (auto _ : state)
      session_.Run(Ort::RunOptions{nullptr}, input_names, &input_tensor, 1,
                   output_names, &output_tensor, 1);
  };

  BENCHMARK([](benchmark::State& state) {
    static_call(state);
  })->Iterations(10000 * 100);

  // 运行基准测试
  benchmark::RunSpecifiedBenchmarks();

  //   session_.Run(Ort::RunOptions{nullptr}, input_names, &input_tensor, 1,
  //                output_names, &output_tensor, 1);

  //   auto res = output_tensor.GetTensorData<float>();

  //   for (int i = 0; i < element_count; i++) {
  //     std::cout << res[i] << " ";
  //   }
}