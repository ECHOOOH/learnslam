# CH2实践 &作业  CMake基础&CLion安装破解

参考链接：  
[linux下CMake简明教程](https://blog.csdn.net/whahu1989/article/details/82078563)  
[CMake常用语法总结](https://www.jianshu.com/p/8909efe13308)    
[CMake使用整理总结](https://blog.csdn.net/wzzfeitian/article/details/40963457)    
[CLion安装破解](https://www.jb51.net/article/198343.htm)(网页里写的是IDEA 都是JetBrains家的 都一样)  


## CMake 基本语法

+ cmake变量使用${}方式取值  
+ 指令(参数1 参数2…)参数使用括弧括起,参数之间使用空格或分号分开。
+ 指令是大小写无关的,参数和变量是大小写相关的。推荐你全部使用**大写**指令。

### 常用预定义变量

PROJECT_SOURCE_DIR 工程的根目录  
EXECUTABLE_OUTPUT_PATH 重新定义目标二进制可执行文件的存放位置
LIBRARY_OUTPUT_PATH 重新定义目标链接库文件的存放位置

### 常用命令列表

+ PROJECT(projectname [CXX] [C] [Java])
  指定工程名称,并可指定工程支持的语言。支持语言列表可忽略,默认支持所有语言
+ SET
  SET(VAR [VALUE] [CACHE TYPE DOCSTRING [FORCE]])
  定义变量(可以定义多个VALUE,如SET(SRC_LIST main.c util.c reactor.c))
+ ADD_EXECUTABLE
  ADD_EXECUTABLE(bin_file_name ${SRC_LIST})
  生成可执行文件
+ ADD_LIBRARY
  ADD_LIBRARY(libname [SHARED | STATIC | MODULE] [EXCLUDE_FROM_ALL] SRC_LIST)
  生成动态库或静态库
+ SET_TARGET_PROPERTIES
  设置输出的名称,设置动态库的版本和API版本
+ ADD_SUBDIRECTORY
  ADD_SUBDIRECTORY(src_dir [binary_dir] [EXCLUDE_FROM_ALL])
  向当前工程添加存放源文件的子目录,寻找下级CMakeLists.txt。可以指定中间二进制和目标二进制的存放位置
  EXCLUDE_FROM_ALL含义：将这个目录从编译过程中排除
+ INCLUDE_DIRECTORIES
  INCLUDE_DIRECTORIES([AFTER | BEFORE] [SYSTEM] dir1 dir2 … )
  向工程添加多个特定的头文件搜索路径,路径之间用空格分隔,如果路径包含空格,可以使用双引号将它括起来,默认的行为为追加到当前头文件搜索路径的后面。有如下两种方式可以控制搜索路径添加的位置
+ AUX_SOURCE_DIRECTORY
  AUX_SOURCE_DIRECTORY(dir VAR)
  发现一个目录下所有的源代码文件并将列表存储在一个变量中

## 基本工程结构

正规一点来说，一般会把源文件放到src目录下，把头文件放入到include文件下，生成的对象文件放入到build目录下，最终输出的elf文件会放到bin目录下，这样整个结构更加清晰。让我们把前面的文件再次重新组织下   
|–--**bin**  
|–--**build**  
|–--CMakeLists.txt  
|–--**include**  
|–--|--–testFunc1.h  
|–--|–--testFunc.h  
|–--**src**  
|–--|--–CMakeLists.txt  
|–--|--–mian.c   
|–--|--–testFunc1.c  
|–--|–--testFunc.c

最外层CMakeLists.txt负责统领全局  

```
#声明最低版本 要写 不写会有警告
cmake_minimum_required (VERSION 2.8)
#工程名称
project (name)
#向当前工程添加存放源文件的子目录
add_subdirectory (src)
```

这里指定src目录下存放了源文件，当执行cmake时，就会进入src目录下去找src目录下的CMakeLists.txt，所以在src目录下也建立一个CMakeLists.txt，内容如下  

```
# 把本文件夹(src)下的所有源文件都储存在一个变量SRC_LIST里然后在add_executable里调用SRC_LIST（注意调用变量时的写法）
# aux_source_directory(dir var)第一个参数dir是指定目录，第二个参数var是用于存放源文件列表的变量
aux_source_directory (. SRC_LIST)

# include_directories。该命令是用来向工程添加多个指定头文件的搜索路径，路径之间用空格分隔。
include_directories (../include)

# 生成可执行文件
add_executable (main ${SRC_LIST})

# 设置可执行文件的存放位置 这里set的意思是把存放elf文件的位置设置为工程根目录下的bin目录
# 系统自带的预定义变量
# EXECUTABLE_OUTPUT_PATH ：目标二进制可执行文件的存放位置
# PROJECT_SOURCE_DIR：工程的根目录
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
```

在build目录下输入`cmake ..`  然后运行`make`

## 静态库和动态库的编译控制

### 生成库

文件组织结构  
|----**build**  
|----CMakeLists.txt  
|—-**lib**  
|—-**testFunc**  
|—-|—-testFunc.c  
|—-|—-testFunc.h  
在build目录下运行cmake，并把生成的库文件存放到lib目录下。  
CMakeLists.txt内容如下：  

```cmake_minimum_required (VERSION 3.5)
project (demo)
# 添加源文件
set (SRC_LIST ${PROJECT_SOURCE_DIR}/testFunc/testFunc.c)

# 生成动态库或静态库(第1个参数指定库的名字；第2个参数决定是动态还是静态，如果没有就默认静态；第3个参数指定生成库的源文件)
add_library (testFunc_shared SHARED ${SRC_LIST})
add_library (testFunc_static STATIC ${SRC_LIST})

# set_target_properties: 设置最终生成的库的名称，还有其它功能，如设置库的版本号等等
set_target_properties (testFunc_shared PROPERTIES OUTPUT_NAME "testFunc")
set_target_properties (testFunc_static PROPERTIES OUTPUT_NAME "testFunc")

# LIBRARY_OUTPUT_PATH: 库文件的默认输出路径，这里设置为工程目录下的lib目录
set (LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
```

### 链接库

新建工程目录，拷贝生成的库文件  
|—-**bin**  
|—-**build**  
|—-CMakelists.txt  
|----**src**  
|—-|—-main.c  
|—-**testFunc**  
|—-|—-**inc**  
|—-|—-|—-testFunc.h  
|—-|—-**lib**  
|—-|—-|—-libtestFunc.a  
|—-|—-|—-libtestFunc.so  
CMakeLists.txt内容如下:  

```
cmake_minimum_required (VERSION 2)

project (demo)
# 输出位置
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 添加源文件
set (SRC_LIST ${PROJECT_SOURCE_DIR}/src/main.c)
# 添加头文件
include_directories (${PROJECT_SOURCE_DIR}/testFunc/inc)
# 在指定目录下查找指定库，并把库的绝对路径存放到变量里，其第一个参数是变量名称，第二个参数是库名称，第三个参数是HINTS，第4个参数是路径，其它用法可以参考cmake文档
find_library(TESTFUNC_LIB testFunc HINTS ${PROJECT_SOURCE_DIR}/testFunc/lib)
# 生成
add_executable (main ${SRC_LIST})
# 链接库
target_link_libraries (main ${TESTFUNC_LIB})

```



