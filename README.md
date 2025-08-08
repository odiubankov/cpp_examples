# Examples of C++ features from different standards

Build with bazel:
* Download bazelisk from official repository and put it to ```~/bin```
  
```wget https://github.com/bazelbuild/bazelisk/releases/download/<latest_version>/bazelisk-linux-amd64```

* Add ```~/bin``` to PATH
```
# ~/.bashrc
export PATH=~/bin:$PATH
```

* create bazel symlink in bin directory above
```
ln -s bazelisk-linux-amd64 bazel
```
* Testing of project can be done from the root project directory with following syntax:
```
bazel test //17/template_arg_deduct
```
