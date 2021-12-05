# CH2 习题

### **1.阅读文献【1】【14】**    
以后再读

### **2.阅读综述文献【9,15,16,17,18】**  
以后再读

### **3.g++命令**   
[g++常用操作指令](https://www.jianshu.com/p/05d4f77326fc) (更清晰)  
[linux下gcc/g++的命令和使用详解](https://blog.csdn.net/langb2014/article/details/50452041)  
gcc and g++是c & c++编译器，gcc/g++在执行编译工作的时候，总共需要4步  
1.预处理,生成.i的文件[预处理器cpp]
2.将预处理后的文件转换成汇编语言,生成文件.s[编译器egcs]
3.由汇编变为目标代码(机器代码)生成.o的文件[汇编器as]
4.连接目标代码,生成可执行程序[链接器ld]

+ `-x language filename`

  设定文件所使用的语言,使后缀名无效,对以后的多个有效.也就是根据约定C语言的后缀名称是.c的，而C++的后缀名是.C或者.cpp,如果你很个性，决定你的C代码文件的后缀名是.pig ，那你就要用这个参数,这个参数对他后面的文件名都起作用，直到下一个参数的使用。

  可选参数名：　`c`, `objective-c`, `c-header`, `c++`, `cpp-output`, `assembler`, and `assembler-with-cpp`.

  eg:`gcc  -x hello.pig`

+ `-x none filename`  
  
  关掉上一个选项，也就是让gcc根据文件名后缀，自动识别文件类型
  eg:`gcc -x c hello.pig` 
  
  ​     `gcc -x none hello2.c`
  
+ `-c`  只激活预处理,编译,和汇编
  
  也就是他只把程序做成obj文件
  eg:`gcc -c hello.c`
  他将生成.o的obj文件
  
+ -S  只激活预处理和编译
  
  就是指把文件编译成为汇编代码。
  eg:`gcc -S hello.c`
  他将生成.s的汇编代码，你可以用文本编辑器察看
  
+ -E  只激活预处理
  
  这个不生成文件，你需要把它重定向到一个输出文件里面。
  eg:`gcc -E hello.c > pianoapan.txt`
  一个hello word 也要与处理成800行的代码
  
+ **-o  制定目标名称**
  　　
  缺省的时候,gcc 编译出来的文件是a.out
  eg:`gcc -o hello hello.c `
  
+ `-g`  产生调试信息

  选项告诉GCC产生能被 GNU调试器(DGB) 使用的调试信息，以调试程序

  eg:`g++ -g test.cpp -o test`

+ 优化源代码

  g++ 对源代码进行基本优化。这些优化在大多数情况下都使程序执行得更快，常用优化级别如下：

  `-O`  :同时减少代码的长度和执行时间，其效果等价于 `-O1`

  `-O0`: 表示不做优化

  `-O1`: 表示默认优化

  `-O2`: 告诉 g++ 产生尽可能小和尽可能快的代码。除了完成`-O1` 的优化之外，还进行一些额外的调整工作，如指令调整等

  `-O3`: 包括循环展开和其他一些与处理性相关的优化工作，选项将使编译的速度比 `-O` 慢，但通常产生的代码执行速度会更快。

  一般不要用太高等级的优化

+ `-l` `-L` 指定库文件

  -l 参数（小写L）就是用来指定程序要链接的库，-l 参数紧接着就是库名，在`/lib`、`/usr/lib`、`/usr/local/lib`里的库直接调用 -l 参数就能链接，这三个库目录我们在下文中叫做**系统库目录**

  eg:`g++ -lglog test.cpp` 链接 glog库 编译

  如果库文件没有放在**系统库目录**中，需要使用-L 参数（大写l）指定库文件所在目录，-L 参数跟着的是库文件所在的目录名

  eg:`g++ -L~/lib -lmytest test.cpp` 链接 mytest库。libmytest.so 在 ~/lib目录下

+ `-I` 指定头文件搜索目录

  `/usr/include` 一般不用指定，gcc 知道去那里找，但是如果头文件不在 `/usr/include` 里我们就要用 `-I` 参数指定了，比如头文件放在 `/myinclude`目录里，那编译命令行就要加上 `-I/myinclude` 参数，如果不加你会得到一个 `xxx.h: No such file or directory` 的错误。`-I` 参数可以使用相对路径，也可以使用绝对路径。

+ `-Wall` 打印警告信息

  eg:`g++ -Wall test.cpp`

+ `-w` 关闭警告信息

  在使用高版本的C++标准进行编译的时候，代码写的不规范的时候，比如定义变量但是不使用，g++将会提示对应的警告信息。但可以使用`-w`关闭这些警告

  eg:`g++ -w test.cpp`

+ `-std`设置编译标准

  eg:`g++ -std=c++11 test.cpp` 使用 c++11 标准编译 test.cpp

### **4.使用build文件夹编译**

工程目录结构见CH2 实践 cmake使用

### 5.6.**编译报错**

随时百度

### 7.阅读《cmake实践》

贴一些不错的教程连接 现用现学   
[CMake入门实战](https://www.hahack.com/codes/cmake/)

### 8.find_package调用小程序库

见《cmake实践》第四章  
CSDN参考文档[CMake 实践与踩坑记录（二）](https://blog.csdn.net/weixin_43619346/article/details/103113527)    
以后再做

### 9.关于kdevelop

换用了CLion

