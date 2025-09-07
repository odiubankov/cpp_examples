package(default_visibility = ["//visibility:public"])

load(":gcc_toolchain_config_info.bzl", "gcc_toolchain_config_info")

filegroup(name = "empty")

gcc_toolchain_config_info(name = "gcc_toolchain_config")

cc_toolchain(
    name = "gcc_cc_toolchain",
    toolchain_config = ":gcc_toolchain_config",
    all_files = ":empty",
    compiler_files = ":empty",
    dwp_files = ":empty",
    linker_files = ":empty",
    objcopy_files = ":empty",
    strip_files = ":empty",
)

toolchain(
    name = "gcc",
    toolchain = ":gcc_cc_toolchain",
    toolchain_type = "@bazel_tools//tools/cpp:toolchain_type",
)
