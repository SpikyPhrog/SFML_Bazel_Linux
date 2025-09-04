# SFML_Bazel_Linux
SFML base project, that works with bazel on Linux


# PREREQUISITES
- Make sure to install bazel on linux [Link to the install page](https://bazel.build/install)

- Make sure to have these libs installed too:
    - libudev-dev
    - libx11-dev
    - libxrandr-dev
    - libxcursor-dev
    - libxi-dev
    - libxinerama-dev
    - libfreetype-dev
    - libjpeg-dev
    - libopenal-dev
    - libsndfile1-dev

    And here's the full command in case you're feelin lazy
    ```
        sudo apt install libudev-dev libx11-dev libxrandr-dev libxcursor-dev \
                     libxi-dev libxinerama-dev libfreetype-dev libjpeg-dev \
                     libopenal-dev libsndfile1-dev
    ```

# How to run it?
Once you've installed the prerequisites, you can open a terminal at the root folder of the project and run:
```
    bazel run //src

```

If all goes well, you should see the project working opening a black window

If there are any issues, please drop them in the [issues section](https://github.com/SpikyPhrog/SFML_Bazel_Linux/issues)

Thank you for checking this out and good luck with your future projects

# Things to keep in mind

- Build files
    - If you want to nest src folders with code in them, make sure you create a Build file that consist of at least this
    ```
package(default_visibility = ["//visibility:public"])

filegroup(
    name = "_name_of_folder_", # change _name_of_folder to the name of the folder or the purose of this dir
    srcs = glob(["*.h", "*.cpp"]), # makes sure that this rule would include all the source code that your folder would contain
    )
```
And whenever you create such dir and build file, make sure you add that folder in the
```

    srcs = glob(["*.cpp", "*.h"]) + ["//src/_NameOfFolder_:_NameOfThe"Rule""], # the name of the rule is the name that you've put in the "filename(name = "...")"

```
