from distutils.core import setup, Extension

module1 = Extension("SuperFastFinder", sources=["SuperFast.cpp"])

setup(
    name="SuperFastFinder",
    version="1.0",
    description="My super fast module for searching min",
    ext_modules=[module1],
)
