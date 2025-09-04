cc_binary(
    name = "src",
    srcs = glob(["*.cpp", "*.h"]) + ["//src/Systems:systems", "//src/Widgets:widgets"],
    deps = [
        "@sfml",
        "@bazel_tools//tools/cpp/runfiles",
    ],
    data = [
        "//src/assets:assets"
    ],
    copts = ["-std=c++17"],
    linkopts = [
        "-ludev",
        "-lX11",
        "-lXrandr",
        "-lXcursor",
        "-lXinerama",
        "-lXi",
        "-lpthread",
        "-ldl",
        "-lfreetype",
        "-ljpeg",
        "-lopenal",
        "-lsndfile",
    ],
)
