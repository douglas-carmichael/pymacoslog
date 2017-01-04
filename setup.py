from distutils.core import setup, Extension

module1 = Extension('macoslog',
                    sources = ['macoslog.c'])

setup (name = 'macOSLog',
       version = '1.0',
       description = 'This is an extension to log to the macOS Unified Logging system.',
       ext_modules = [module1])
