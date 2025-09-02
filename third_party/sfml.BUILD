package(default_visibility = ["//visibility:public"])

# Define the modules and their corresponding libraries
MODULES = [
    "audio",
    "audio-d",
    "graphics",
    "graphics-d",
    "window",
    "window-d",
    "system",
    "system-d",
]

MODULES_MAP = {
    "audio" : "audio-s",
    "audio-d" : "audio-s-d",
    "graphics" : "graphics-s",
    "graphics-d" : "graphics-s-d",
    "window" : "window-s",
    "window-d" : "window-s-d",
    "system" : "system-s",
    "system-d" : "system-s-d",
}

# Dynamically define `cc_import` for each module
[
    cc_import(
        name = module,
        static_library = "lib/libsfml-{}.a".format(statics),  # Path to static lib
        shared_library = "lib/libsfml-{}-3.so".format(module),  # Path to shared lib (.so)
        hdrs = glob(["include/SFML/**/*.hpp", "include/SFML/**/*.inl"]),
        includes = ["include"],  # Specify the include directory
    )
for module, statics in MODULES_MAP.items()]

# Define the main SFML library by combining all the modules
cc_library(
    name = "sfml",
    hdrs = glob([
        "include/SFML/**/*.hpp",  # Include all headers for SFML
    ]),
    includes = ["include"],  # Specify the include directory
    deps = MODULES,
)
