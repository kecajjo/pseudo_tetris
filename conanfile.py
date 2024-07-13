from conan import ConanFile
from conan.tools.cmake import cmake_layout


class Tetris(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"

    def requirements(self):
        self.requires("ncurses/6.5")

    def layout(self):
        cmake_layout(self)