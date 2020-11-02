load(
    "//bazel:envoy_build_system.bzl",
    "envoy_cc_extension",
    "envoy_cc_library",
    "envoy_extension_package",
)

licenses(["notice"])  # Apache 2

# Golang extentions filter.
# Public docs: docs/root/configuration/http_filters/golang_extention_filter.rst

envoy_extension_package()

cc_import(                             
    name = "golang_extention",
    hdrs = ["golang_extention.h"],
    shared_library = "golang_extention.so",
)

envoy_cc_library(
    name = "golang_extention_filter_lib",
    srcs = ["golang_extention_filter.cc"],
    hdrs = [
            "golang_extention_filter.h",
            "golang_extention.h",

    ],
    deps = [
        "//include/envoy/http:codes_interface",
        "//include/envoy/http:filter_interface",
        "//source/common/common:enum_to_int",
        "//source/common/common:utility_lib",
        "//source/common/grpc:common_lib",
        "//source/common/grpc:context_lib",
        "//source/common/http:headers_lib",
        "//source/common/http/http1:codec_lib",
        ":golang_extention",
    ],
)

envoy_cc_extension(
    name = "config",
    srcs = ["config.cc"],
    hdrs = ["config.h"],
    # Legacy test use. TODO(#9953) clean up.
    extra_visibility = [
        "//source/exe:__pkg__",
        "//test/integration:__subpackages__",
        "//test/server:__subpackages__",
    ],
    security_posture = "unknown",
    deps = [
        "//include/envoy/registry",
        "//include/envoy/server:filter_config_interface",
        "//source/extensions/filters/http:well_known_names",
        "//source/extensions/filters/http/common:factory_base_lib",
        "//source/extensions/filters/http/golang_extention:golang_extention_filter_lib",
        "@envoy_api//envoy/extensions/filters/http/golang_extention/v3:pkg_cc_proto",
    ],
)
