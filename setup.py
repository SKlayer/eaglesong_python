from distutils.core import setup, Extension

eaglesong_hash_module = Extension('eaglesong_hash',
                               sources = ['Eaglesong.c',
                                          'eaglesong_module.c',
										  
										  ],
                            include_dirs=['.'])

setup (name = 'eaglesong_hash',
       version = '1.0',
       description = 'Eaglesong hash of CKB mining',
       ext_modules = [eaglesong_hash_module])
