from conans import ConanFile, CMake, tools, RunEnvironment
import os


class ParticleEvaluationToolConan(ConanFile):
    name = "PET"
    description = ""
    topics = ("conan", "libname", "logging")
    url = "https://github.com/themhmoritz3/"
    homepage = "https://github.com//"
    license = "MIT"  # Indicates license type of the packaged library; please use SPDX Identifiers https://spdx.org/licenses/
    exports_sources = ["*"]
    generators = "cmake", "visual_studio_multi"

    version = "NVP"

    settings = "os", "arch", "compiler", "build_type"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": True, "fPIC": True}

    requires = [ "qt/6.3.1"]
            

    def config_options(self):
        if self.settings.os == 'Windows':
            del self.options.fPIC

    def build_requirements(self):
        self.build_requires("cmake/3.23.2")
        #if self._meson_supported():
            #self.build_requires("meson/0.60.2")

    def _configure_cmake(self):
        self.output.info("Building with cmake_find_package_multi")
        env_build = RunEnvironment(self)
        with tools.environment_append(env_build.vars):
            cmake = CMake(self, set_cmake_flags=True)
            print(self.deps_cpp_info["qt"].rootpath+"/lib/cmake/Qt6")
            cmake.definitions['Qt6_DIR'] = self.deps_cpp_info["qt"].rootpath + "/lib/cmake/Qt6"
            if self.settings.os == "Macos":
                cmake.definitions['CMAKE_OSX_DEPLOYMENT_TARGET'] = '10.14'

            cmake.configure()
        return cmake
    
    
    def build(self):
        cmake = self._configure_cmake()
        cmake.build()

    def package(self):
        self.copy(pattern="LICENSE", dst="licenses", src=".")
        cmake = self._configure_cmake()
        cmake.install()
        # If the CMakeLists.txt has a proper install method, the steps below may be redundant
        # If so, you can just remove the lines below
        include_folder = os.path.join(self._source_subfolder, "include")
        self.copy(pattern="*", dst="include", src=include_folder)
        self.copy(pattern="*.dll", dst="bin", keep_path=False)
        self.copy(pattern="*.lib", dst="lib", keep_path=False)
        self.copy(pattern="*.a", dst="lib", keep_path=False)
        self.copy(pattern="*.so*", dst="lib", keep_path=False)
        self.copy(pattern="*.dylib", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = tools.collect_libs(self)
