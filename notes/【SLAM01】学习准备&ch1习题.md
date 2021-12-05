# 学习准备
## 写给自己
因为毕设，准备开始学习一下SLAM相关的内容，计划在这里记录一下自己的学习过程。选择了高翔博士的《视觉SLAM十四讲》，网上可供参考的内容也比较多。笔记整理的过程中肯定也会借鉴其他人的成果。同时希望这个过程能尽快的熟悉一下github、Linux以及养成定时回顾和整理的好习惯、管理参考文献的好习惯。
## 学习准备
### 1.Linux系统
使用VMware虚拟机下的**ubantu1804**
参考安装教程： 
[vmware+ubuntu1804](https://blog.csdn.net/qq_39557270/article/details/102926282)  
[安装VMware-tools解决窗口太小的问题](https://blog.csdn.net/u014337397/article/details/80753056)  
[linux系统基础](http://c.biancheng.net/linux_tutorial/10/)  
[鸟哥的Linux私房菜](http://cn.linux.vbird.org/linux_basic/linux_basic.php)
#### 1.5Linux下使用Git
[git/github使用教程](https://blog.csdn.net/hebtu666/article/details/106007346)  
+ 添加到缓冲区  
`git add filename`
+ 提交到仓库  
`git commit -m "Notes on this submission"`  
+ 查看状态  
`git status`  
+ 撤销修改 回到最后一次commit 或 add 的状态  
`git checkout -- filename`  
+ 查看修改内容  
`git diff`  
+ 查看历史记录  
`git log`  
+ 回退到历史版本  
`git reset -- hard HEAD^`  
在Git中，用HEAD表示当前版本，上一个版本就是HEAD^，上上一个版本就是HEAD^^，往上100个版本可以写成HEAD~100。
 + 把本地库的所有内容推送到远程库GitHub上  
 `git push origin master`  
+ 克隆一个GitHub库到本地  
`git clone git@github.com:yourname/gitlearninig.git`

### 2.vim  
Linux下的文本编辑器 解放鼠标 仅使用键盘操作  
[vim基本操作](https://www.runoob.com/linux/linux-vim.html)  
[从Vim小白到Vim superstar](https://blog.csdn.net/xlinsist/article/details/54143380)

##### 命令模式
用户刚刚启动 vi/vim，便进入了命令模式.此状态下敲击键盘动作会被Vim识别为命令，而非输入字符。比如我们此时按下i，并不会输入一个字符，i被当作了一个命令。

**以下是常用的几个命令：**

i 切换到输入模式，以输入字符。  
x 删除当前光标所在处的字符。  
: 切换到底线命令模式，以在最底一行输入命令。  
若想要编辑文本：启动Vim，进入了命令模式，按下i，切换到输入模式。

命令模式只有一些最基本的命令，因此仍要依靠底线命令模式输入更多命令。
##### 输入模式
输入模式
在命令模式下按下i就进入了输入模式。

在输入模式中，可以使用以下按键：

+ 字符按键以及Shift组合，输入字符
+ ENTER，回车键，换行
+ BACK SPACE，退格键，删除光标前一个字符
+ DEL，删除键，删除光标后一个字符
+ 方向键，在文本中移动光标
+ HOME/END，移动光标到行首/行尾
+ Page Up/Page Down，上/下翻页
+ Insert，切换光标为输入/替换模式，光标将变成竖线/下划线
+ ESC，退出输入模式，切换到命令模式

##### 底线命令模式
在命令模式下按下:（英文冒号）就进入了底线命令模式。  
底线命令模式可以输入单个或多个字符的命令，可用的命令非常多。  
在底线命令模式中，基本的命令有（已经省略了冒号）：
+ q 退出程序
+ w 保存文件
按ESC键可随时退出底线命令模式。

![三种模式切换](https://img-blog.csdnimg.cn/img_convert/c057c05fd079c370f6a688eedfcc45f9.png)  
# 第一章习题
[第一节参考答案链接](https://blog.csdn.net/weixin_43619346/article/details/103181076)   
[全14讲参考答案](https://blog.csdn.net/jiahao62/article/details/80655542)  

[线性方程组的解](https://blog.csdn.net/youngpan1101/article/details/54574130)  
[高斯分布](https://www.cnblogs.com/bingjianing/p/9117330.html)  

vim和Linux参见前文

>参考链接：
https://blog.csdn.net/qq_39557270/article/details/102926282
https://blog.csdn.net/u014337397/article/details/80753056
http://c.biancheng.net/linux_tutorial/10/
https://blog.csdn.net/hebtu666/article/details/106007346
https://www.runoob.com/linux/linux-vim.html
https://blog.csdn.net/xlinsist/article/details/54143380
http://cn.linux.vbird.org/linux_basic/linux_basic.php


