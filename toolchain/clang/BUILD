package(default_visibility = ["//visibility:public"])

load(":clang_toolchain_config_info.bzl", "clang_toolchain_config_info")

filegroup(name = "empty")

clang_toolchain_config_info(name = "clang_toolchain_config")

cc_toolchain(
    name = "clang_cc_toolchain",
    toolchain_config = ":clang_toolchain_config",
    all_files = ":empty",
    compiler_files = ":empty",
    dwp_files = ":empty",
    linker_files = ":empty",
    objcopy_files = ":empty",
    strip_files = ":empty",
)

toolchain(
    name = "clang",
    toolchain = ":clang_cc_toolchain",
    toolchain_type = "@bazel_tools//tools/cpp:toolchain_type",
)
