akaedu-c-learning
=================

my C demo code in akaedu learning




# Chp-8 位运算

## 基本概念

加法器  和  异或运算之间的关系

### 与
AND  &

### 或
OR  |

### 非
NOT  ~

### 异或
XOR  ^

### 注意事项
* Integer Promotion
8bit -> 32bit

* example
(unsigned char)0xfc -> unsigned int 

### 进制转换
0xC = 0b1100 
0xd = 1101
0xe = 1110
0xf = 1111
0xa = 1010
0xb = 1011

### 错误辨析1
char c;

for (c = 0x00; c < 0xff; c++)

为什么是一个无限循环？

怎么修改正确？  （答案是 unsigned char c 或者 int c)
提示： 从 127 + 1 = -128 所以会出问题。

### 错误辨析2
	if (0 & 1 == 0)
		printf("c = %d\n", c);

以上代码为何无法打印输出？

## 移位运算
左移操作 等价于 *2   低位（右边）补0
右移操作 等价于 /2   高位（左边）补符号位

所以 a / 16 等价于  a >> 4
a % 16 等价于  a & 0x0F

一般我们进行移位操作的时候，通常会强制类型转换为 unsigned     (unsigned)a >> n

## 常用位操作

### 设置位 set_bit(num, pos, 1)
或操作，或 | 上 1, 1需要左移pos位

	num = num | (1<<pos);
	num |= ((unsigned)1<<pos);

### 清除位 set_bit(num, pos, 0)   clear_bit(num, pos)
与操作，与 & 上 0，1左移pos位然后取反

	num = num & ~(1<<pos);
	num &= ~((unsigned)1<<pos);

### 测试位 = get_bit(num, pos)
#### 判别是否为1
* 写法1 if ((num & (1<<pos)) == (1<<pos))
* 写法2 if (num & (1<<pos))

#### 判别是否为0
* 写法1 if ((num & (1<<pos)) == 0x0)
* 写法2 if (!(num & (1<<pos)))

### 设置位域 bit-field
如果需要实现 从 pos 位开始的 len 个bit，设置为 value
* 步骤1 与操作，与 & 上 0，从pos位开始len位都是1然后取反
* 步骤2 或操作，或 | 上 value, value需要左移pos位

例如 pos = 8, len = 4, value = 0b1011

	num = num & ~(0b1111 << pos);
	num = num | (value << pos);

### 获取位域 bit-field
例如，请实现对于一个 int 型变量 num 的 十六进制输出（也就是0x%x的方式输出)
void put_int_hex(int num)

## 课后作业
### 求1-100里面有多少个9？
### 请实现两个函数接口 void set_bit(num, pos, value) 和 int get_bit(num, pos)
### 请实现位域函数接口 void set_bit_filed(num, pos, len, value)
### 请参考 put_int_hex 的实现，完成 8进制的输出函数 void put_int_oct(int num)

for (i = 10; i >= 0; i--)
	put_oct(((unsigned)num >> (i*3)) & 0x7)


https://github.com/limingth/NCCL


# chp-9 指针基础

## 预备知识

### 计算机组成原理

#### CPU内部结构
* ALU 算术逻辑单元
* Reg 寄存器
* ID 指令译码器 (Instruction Decoder)
* IB 指令缓冲器 (Instruction Buffer)
* PC 程序计数器 (Program Counter)
* Addr Bus 地址总线
* Data Bus 数据总线
* Control Unit 控制单元 （与Control Bus 控制总线相连）
* LDR/STR 访存指令
* MMU

### 进程地址空间
* cat /proc/pid/maps
* cat /proc/kallsyms 

#### 各个段的地址
* 代码段 [text]
* 数据段 [data]
* 堆 [heap]
* 栈 [stack]

	&local = 0xbfffc01c
	&global = 0x804a01c
	&myconst = 0x8048620
	&mystatic = 0x804a020
	const string = 0x80487fd
	malloc = 0x987a008
	main = 0x8048454

#### 进程的地址空间映射图
----- 4G

------ 3G
             栈


             堆
             数据段
             代码段
------ 0G

### 指针基础
#### man ascii
* hexdump -C hanzi.txt

#### 重要结论
如何看待指针变量？
* 指针变量p更像是一个 int 整型变量i。而不是一个数组a[]。
	- 指针是一个变量，存储的是一个地址，而这个地址是一个 int 整型数。指针变量占4个字节的存储，表示0-4G的虚拟地址。可以通过 (int) 强制转换为一个 int 整型数。
	- 指针的值表示变量内存的起始地址，指针的类型决定*p要访问的内存单元的长度，而整型变量不能使用 *i 来访问内存。
	- 指针变量存储的地址是有一定的取值范围（约束），而整型变量则可以任意。
	- 指针变量的 +1 操作，是指向下一个同类型变量的内存单元的地址，而整型变量的 +1 操作，就是数值上加了1.
	- 指针变量可以做 加/减运算，但不能作 乘/除运算，而整型变量都可以。
	- 数组是连续的多个变量，指针是单个变量。
	- 数组存储的是变量的值，指针存储的是某个变量的地址。
	- 数组名不可以自增加和自减少 (a++/a--)，指针则可以 p++/p--/。
	- 数组名可以做加/减运算(a+1)，指针也可以做 加/减运算(p+1)。
	- 数组名和指针一样，在进行加减运算的基础上，还可以进行 *(a+1) / *(p+1)

#### 反汇编工具
* objdump -D a.out  反汇编

#### 段错误是怎么产生的？
* 原因1： 要访问（R/W）的内存地址（VA）在该进程中没有映射

* 原因2： 要写入（W）的内存地址（VA）所在的页面是只读属性

* 段错误不是给指针赋值（哪怕是错误值）所产生的，而是用 *p 去访问内存的时候才会产生段错误。

* 给指针赋初始化的值，这个值的取值范围和方法(3种)是有一定约束的。
	- 1. p = &a;   (int a;)
	- 2. p = malloc(100);
	- 3. p = array;   (int array[100];)
	- 4. p = func;
	- 5. p = old_p++;

### 指针作为参数的传“址“调用 （vs 传值调用）

### malloc

#### NULL 不是 C语言的一个关键词 keyword，可以作为变量名。

	#define NULL ((void *)0)
 
int NULL； （ int while; )

int a；

akaedu@ubuntu:~/teacher_li/pointer$ find  /usr/include/ -name stddef.h
/usr/include/linux/stddef.h
akaedu@ubuntu:~/teacher_li/pointer$ vi /usr/include/linux/stddef.h 

 
  6 #undef NULL
  7 #if defined(__cplusplus)
  8 #define NULL 0
  9 #else
 10 #define NULL ((void *)0)
 11 #endif

### malloc 的最大值
 p = malloc(0x47100000);   可以
 p = malloc(0x47200000);   不可以，返回 NULL

### malloc 的最小值
 p = malloc(0);		返回值不是 NULL，而是分配的 虚拟页面首地址+8
最小的这个虚拟页面 heap 的空间，大约是 0x21000 = 132K

#### alloca 的范围
* bf9c4000-bf9d9000 [stack]

size = 0x15000 约84k

p = alloca(0x9f0000);	可以
p = alloca(0xa00000);	不可以，返回 NULL，栈空间的最大值约为 10M

栈的最大值：

bf5a6000-bff99000 rw-p 00000000 00:00 0          [stack]

局部变量分配在栈上，其中最大的数组大小可以是10M左右。

 10 #define N 0x9f0000
 11     char a[N];
 12     
 13     a[N-4] = 'a';

全局变量的最大数组长度 0x10000000 是可以的，用 0x20000000 就几乎不可用了。
 #define N 0x10000000
 char a[N];

最大长度和物理内存的大小有一定关系。

## 课后作业
### 用数组来解决约瑟夫环问题 Josephus 

### 用数组来解决求素数问题 is_prime(int num); 

# chp-10 字符串

## 字符串的连接
printf("hello, please"
         "input a number:\n");

## 对比 '\0' vs '0' vs 0 vs "0"
* '\0': 1byte (0x00) char
* '0' : 1byte (0x30) char
*  0  : 4bytes (0x00000000) int
* "0" : 2bytes (0x30 0x00) char *


## 字符串作为参数传递时
例如 printf("hello\n");
等价于 printf(0x8048040);

例如 printf("hello, this is a good boy\n");
等价于 printf(0x8048140);

char * p1 = "hello";
char * p2 = "hello, this is a bad boy\n";

这个赋值是可以的，允许的。
char * p1;
p1 = "hello";
p1 = "world";

这个赋值是不可以的，只能用 strcpy(str, "hello"); 给 str 数组赋值。
char str[100];
str = "hello";

如果 我们用 
char str[100];
char * p;
p = str;
p = "hello";
 strcpy(p, "world"); 

但是如果改成
char str[100];
char * p;
p = str;
p = "hello";    ->   替换为 strcpy(p, "hello");  就可以了。

## 字符串变量
char s[5] = "hello";

* strlen 表示肉眼可以看出的长度
	strlen(s) = 5;  

* sizeof 表示计算机内部的存储空间
	sizeof(s) = 6;  	

### 反汇编工具查看数据段
* objdump -S -j .data  a.out > a.txt  
推荐用大写 S ，可以看到变量名

* objdump -s -j .data  a.out > a.txt

* objdump -S -j .text -j .rodata -j .data  a.out > a.txt  

### 字符串和字符指针辨析题
char * s = "hello";
char s[] = "hello";

* 编译的时候加上 -g 参数，产生调试信息（把源码加入到 a.out 中)
* objdump -S -s -j .text -j .data -j .rodata a.out > a.txt

* case 1: 全局指针变量
char * s = "hello";
{}

s 指针存储的内容为 0x080484C0
在 0x80484C0 的地方，其实是 .rodata 段，和 代码段 .text 属于同一个虚拟页面
同时 s 是一个全局变量，因此 s 也有自己的存储空间和变量地址，这个地址是 0x804a014,属于 .data 数据段。

s = "hello" 这里用到的等号，并不是一条赋值语句，应该被看成是  char * s : "hello";
这里的等号，是告诉编译器，把字符串的首地址 0x80484C0 填入到数据段中的 s 变量所在的内存单元。

* case 2: 局部指针变量
{
	char * s = "hello";
}

s 指针存储的内容为 0x080484d6，这个仍然是.rodata 段，和 代码段 .text 属于同一个虚拟页面
同时，s 是一个局部变量，因此 s 自己的存储空间在栈上，每次分配的地址都不一样（不确定），但编译计算该地址的方法（偏移量）是确定的，表现为 0x1c(%esp) 也就是在栈指针的基础上，偏移 0x1C 字节。

 87  80483ed:   c7 44 24 1c d6 84 04    movl   $0x80484d6,0x1c(%esp)
 88  80483f4:   08
 89  80483f5:   c7 44 24 1c 78 56 34    movl   $0x12345678,0x1c(%esp)
 90  80483fc:   12

s = "hello" 这里的等号，被编译器编译为一条 mov 指令，是真正的赋值语句，和 s = 0x12345678 是完全一样的。所以其实也可以写成 char * s;    s = "hello";

* case 3: 全局字符数组
char s[] = "hello";
{}

1. 没有4个字节来存放地址，或者 s 数组名在数据段中不占空间。
2. s 作为数组名，由编译器直接当成一个常量数据看待（这个数据并不在 .rodata 中占空间），它的值就是 0x8048014 ，从这个地址连续5个字节都属于这个数组的内容空间。
3. 这里的等号，也相当于告诉编译器，把 "hello" 这个字符串，放在 0x8048014 的位置上。
也应该被看成是  char s[] : "hello";  
4. s 不是一个变量，一旦编译结束，这个 s 将不复存在，所有用到 s 的地方，都被替换为  0x8048014 这个常量。例如 s[0] = 'a';


* case 4: 局部字符数组
{
	char s[] = "hello";
}

  movl   $0x4c4c4548,0x1a(%esp)		"hell" -> %esp + 0x1a
  movw   $0x4f,0x1e(%esp)			"o"\0  -> %esp + 0x1e

如果字符数组的初始化值特别长，则编译器不再使用上面的方法来对局部数组赋值，改为循环指令 rep movsl。
所有初始化值的字符串被放到了 .rodata 段中，起始地址是 0x8048600

 92  8048491:   8d 54 24 1c             lea    0x1c(%esp),%edx
 93  8048495:   b8 00 86 04 08          mov    $0x8048600,%eax
 94  804849a:   b9 1d 00 00 00          mov    $0x1d,%ecx
 95  804849f:   89 d7                   mov    %edx,%edi
 96  80484a1:   89 c6                   mov    %eax,%esi
 97  80484a3:   f3 a5                   rep movsl %ds:(%esi),%es:(%edi)

最后的这条指令  rep movsl %ds:(%esi),%es:(%edi) 相当于 执行了 30次 movsl 指令，搬移了120个字节的内容。


### getchar() 的直接返回问题
system("stty raw");

    do  
    {   
        ch = getchar();
        printf("ch = %c (0x%x) \r\n", ch, ch);
    } while (1);

system("stty -raw");


sudo apt-get install ncurses-dev

gcc demo.c -l curses

http://blog.csdn.net/buaa_shang/article/details/9158007

## 课后作业
安装 ncurses-dev ，学习上面的范例程序，写一个贪吃蛇/推箱子/坦克大战的小游戏。

## 课堂作业
读取一个文件，然后把其中的单词识别并打印出来，统计字符数，单词数和行数

## 字符串库函数
vi /usr/include/string.h 

* DOS 下的 TT 打字软件
www.duote.com/soft/2732.html

* Linux 下抓取网页的工具
sudo apt-get install curl

### 课堂大作业 mytt.c
* 功能1： 统计 man string 文本文件中的单词个数，并打印出来。

* 功能2： 对以上单词，分别计算单词长度并对齐打印，然后找出最长的单词。（如果有多个，则打印多个）
提示： 用结构体数组来实现，通过调用 strlen(s) 来计算字符串长度。strcpy 来给结构体 name[] 赋值。
strcat(dst, src); 来实现对齐打印。

* 功能3： 对以上单词，分别计算单词出现的次数，如果有重复出现的单词，则归为一类。
提示：增加一个函数，int find(char * word); 返回值如果为 -1 ，则表示没找到；否则返回找到的位置下标。
find 函数中，可以使用 strcmp(s1, s2) 函数来进行判别。

* 功能4： 对于上面的词频，进行排序输出。（出现次数最多的在前面，比较偏僻的在后面）

* 功能5： 使用 ./trans.rb 脚本，支持在线查 google 字典

* 功能6： 根据上面的词频，实现一个类似 tt 的背单词软件（参考 curses 库实现一个游戏界面）


### 课后作业
* 请自己重新实现一下 p173 页的 memcpy() 函数，要求考虑4字节对齐的拷贝方式
* 请自己按照教材内容，调用 strtok, strtok_r 两个函数，并观察结果。
* 请分析 index.html 文件中的 <html> Webpages </html>，请找出 >  和  < 之间的内容 Webpages。

### strtok 的实现
http://www.360doc.com/content/11/0422/23/1317564_111662571.shtml

char *strtok(register char *string, const char *separators) 
{ 
	register char *s1, *s2; 
	static char *savestring; 
 
	if (string == NULL) { 
		string = savestring; 
		if (string == NULL) return (char *)NULL; 
	} 
 
	s1 = string + strspn(string, separators); 
	if (*s1 == '\0') { 
		savestring = NULL; 
		return (char *)NULL; 
	} 
 
	s2 = strpbrk(s1, separators); 
	if (s2 != NULL) 
		*s2++ = '\0'; 
	savestring = s2; 
	return s1; 
} 


# Makefile 基础

## 规则 Rule

	目标 Target：条件 Prerequisite
		命令1 Commands
		命令2 Commands
		命令3 Commands

## 自动生成依赖关系
* gcc -M main.c
* gcc -MM main.c

## 伪目标
.PHONY: clean

## 几条有用的命令
* printenv | grep PATH 打印全部的环境变量
* export PATH=value  导出到环境变量
* echo $PATH 显示某个环境变量
* PATH=.:/bin/:/usr/bin:/usr/local/bin:/sbin
* source ~/.bashrc 重新设置 PATH
* source /etc/profile 
* . ~/.bashrc
* ./a.out 的由来，当前目录 . 没有在默认的 PATH 中

## 变量的赋值
* A = value   延迟展开
* A := value  立即展开
* A += value  追加赋值（用空格间隔，不是 strcat）
* A ?= value  无则赋值

* 技巧：全文替换  :%s/gcc/$(CC)/gc

## 内置特殊变量
target: p1 p2 p3

* $@ 目标 （冒号左边的目标）  -> target
* $< p1 p2 p3 这些条件中的第一个（最左边的那个）  -> p1
* $^ 指代冒号右边的所有条件 -> p1 p2 p3
* $? 在 p1 p2 p3 中，所有比目标新的条件。例如 p1 p2 比 target 新，则这个就指代 -> p1 p2

# chp15 预处理
## gcc 编译参数 -E

## gcc 编译参数 -S


### SWITCH(S) 的字符串匹配方案
搜索关键字  SWITCH(S)   _S    stackoverflow.com 

http://stackoverflow.com/questions/14219156/how-to-fix-switch-and-case-macros-for-string-in-order-to-avoid-defining-variable

	#define SWITCH(S) char *_S = S; if (0)
	#define CASE(S) } else if (strcmp(_S, S) == 0) {switch(1) { case 1
	#define BREAK }
	#define DEFAULT } else {switch(1) { case 1

	int main()
	{
	    char buf[256];

	    printf("\nString - Enter your string: ");
	    scanf ("%s", buf);

	    SWITCH (buf) {
		CASE ("abcdef"):
		    printf ("B1!\n");
		    BREAK;
		CASE ("ghijkl"):
		    printf ("C1!\n");
		    BREAK;
		DEFAULT:
		    printf ("D1!\n");
		    BREAK;
	    }
	}

	int main()
	{
	    char buf[256];

	    printf("\nString - Enter your string: ");
	    scanf ("%s", buf);

	    char *_S = buf;
	    if (0) {
	    } else if (strcmp(_S, "abcdef") == 0) {switch(1) { case 1:
		printf ("B1!\n");
		};
	    } else if (strcmp(_S, "ghijkl") == 0) {switch(1) { case 1:
		printf ("C1!\n");
		};
	    } else {switch(1) { case 1:
		printf ("D1!\n");
		};
	    }
	}

### 带参数的宏定义
* MAX(i, j)
* TOUPPER(c)

### 运算符 # 和 ##
* # 代表转化为字符串
* ## 表示连接字符串

* grep -rns "##" * | grep define

### do-while(0) 的用法分析
为何会出现 while (0) 有什么意义？ 
答案： 重点不在 while (0) 而在于后面的分号，可以符合 if-else 语句中 else 前面出现分号，语法不出错。

### gcc 的参数汇总
* -S: 编译，生成汇编文件 .s
* -o: 输出，指定生成文件名
* -g: 生成gdb可调试文件，源码进入 a.out
* -c: 只编译，不链接
* -Wall: Warning 警告 all 全部输出
* -E: 预处理
* -M: 生成源码文件的依赖关系(复杂，包含系统头文件)
* -D: 指定宏，定义宏，给宏赋值 -DMAX=100   -DDEBUG
* -U: 去掉宏，取消宏 -UDEBUG
* -MM: 生成源码文件的依赖关系(简单，不包含系统头文件)
* -I: 指定寻找头文件的路径
* -v: 显示版本信息
* -O: 指定优化级别 -O0, -O1, -O2, -O3
* -Werror: 把警告当成error中止
* -L: 指定链接库的路径
* -l: 指定链接库的名称 -lm, -lc, -lcurses, -lpthread, -ljpeg, -lcurl
* --help: 帮助信息

### 如何处理头文件的重复包含
#ifndef HEAD_H
#define HEAD_H

...

#endif

### 如何计算结构体成员的偏移量
 &(((struct test *)0x1000)->member) - 0x1000;
 &(((struct test *)0x0)->member)

#define OFFSET(member)	 (&(((struct test *)0x0)->member))	


# chp11 x86 汇编基础
## ELF 格式

bss (block started by symbol)
int a = 100;    => .data
int b; 	   => .bss
int c = 0;      => .bss


## ABI 含义


### hello.o 和 hello 文件的区别
* file hello.o vs file hello ->  relocatable vs executable
* .rel.text 段 vs 可重定位段的消失
* 相对0地址 vs 绝对地址 0x8048000
* 代码中的 00 00 00 00 vs 代码被重定位后的 a0 90 04 08
* REL vs EXEC (ELF header)
* Sections (.o) vs Segments (a.out)
* Section Header Table vs Program Header Table
* Linker vs Loader

# chp12 汇编和C的关系
## 栈帧 (stack frame)
* 函数调用时 call
	- 保存返回地址 
	- 跳转进入
* 函数进入时 entry
	- 保存老的栈帧 ebp
	- 开辟新的栈帧 ebp esp
* 函数退出时 leave
	- 恢复老的栈帧 esp
	- 恢复老的栈帧 ebp
* 函数返回时 ret
	- 恢复返回地址
	- 跳转回退  1 #include <stdio.h>
  2 
  3 typedef struct {
  4     unsigned int one:1;
  5     unsigned int two:3;
  6     unsigned int three:10;
  7     unsigned int four:5;
  8     unsigned int :2;
  9     unsigned int five:8;
 10     unsigned int six:3;
 11 } demo_type;
 12 
 13 int main(void)
 14 {   
 15 //  demo_type s = { 1, 5, 513, 17, 129, 0x81 };
 16     demo_type s = { 1, 0x5, 0x321, 0x1a, 0x3, 0x81, 0x7 };


 /usr/lib/gcc/i486-linux-gnu/4.4.3/collect2 -dynamic-linker /lib/ld-linux.so.2 -o a6 -z relro /usr/lib/gcc/i486-linux-gnu/4.4.3/../../../../lib/crt1.o /usr/lib/gcc/i486-linux-gnu/4.4.3/../../../../lib/crti.o /usr/lib/gcc/i486-linux-gnu/4.4.3/crtbegin.o -L/usr/lib/gcc/i486-linux-gnu/4.4.3 -L/usr/lib/gcc/i486-linux-gnu/4.4.3 -L/usr/lib/gcc/i486-linux-gnu/4.4.3/../../../../lib -L/lib/../lib -L/usr/lib/../lib -L/usr/lib/gcc/i486-linux-gnu/4.4.3/../../.. -L/usr/lib/i486-linux-gnu hello.o -lgcc --as-needed -lgcc_s --no-as-needed -lc -lgcc /usr/lib/gcc/i486-linux-gnu/4.4.3/crtend.o /usr/lib/gcc/i486-linux-gnu/4.4.3/../../../../lib/crtn.o


### ABI
* Calling Convention

## 变量存储布局
* readelf -a
* hexdump -C
* objdump -dS

## bit-field 位域
  1 #include <stdio.h>
  2 
  3 typedef struct {
  4     unsigned int one:1;
  5     unsigned int two:3;
  6     unsigned int three:10;
  7     unsigned int four:5;
  8     unsigned int :2;
  9     unsigned int five:8;
 10     unsigned int six:3;
 11 } demo_type;
 12 
 13 int main(void)
 14 {   
 15 //  demo_type s = { 1, 5, 513, 17, 129, 0x81 };
 16     demo_type s = { 1, 0x5, 0x321, 0x1a, 0x81, 0x7 };

                         111 1000 0001 00 1 1010  11 0010 0001 101  1

1111 0000 0010 0110 1011 0010 0001 1011
  F  0   2   6    b   2   1   b


0010 0000 0110 0110 1011 0010 0001 1011


# chp13 链接详解

## 多目标文件链接
### 默认链接脚本 ld script
* ld -verbose
* ENTRY(_start)
* __executable_start = 0x8048000;
* . = ALIGN(...)

## 静态库
### 生成
* gcc -c 
* ar rs 
* ranlib 

### 使用
* gcc -lxxx -Ldir
* gcc -print-search-dirs
* 先找共享库，再找静态库
* gcc -static 优先考虑静态链接

## 共享库
### 生成
* gcc -c -fPIC
* gcc -shared

### 使用
* gcc -l -L 和静态库一样

### 运行
* ./a.out 
error while loading shared libraries: libmymath.so: cannot open shared object file: No such file or directory

#### 加载出错的解决方法
* 1. 环境变量 LD_LIBRARY_PATH
* 2. 缓存文件 
	- 修改 /etc/ld.so.conf
	- sudo ldconfig -v
	- 生成 /etc/ld.so.cache
* 3. 拷贝到系统路径
	- /usr/lib
	- /lib
* 4. 写死路径在文件中
	- gcc main.c -lxxx -Ldir -o main -Wl,-rpath,/home/akaedu/somedir

## 三个名字
* linker name (/usr/lib/libc.so)	-lc
	  1 /* GNU ld script
	  2    Use the shared library, but some functions are only in
	  3    the static library, so try that secondarily.  */
	  4 OUTPUT_FORMAT(elf32-i386)
	  5 GROUP ( /lib/libc.so.6 /usr/lib/libc_nonshared.a  AS_NEEDED ( /lib/ld-linux.so.    2 ) )

* so name (/lib/libc.so.6)
	akaedu@ubuntu:~/teacher_li/chp13-linker$ ls -l /lib/libc.so.6 
	lrwxrwxrwx 1 root root 14 2011-04-12 22:58 /lib/libc.so.6 -> libc-2.11.2.so

* real name (/lib/libc-2.11.1.so)
	kaedu@ubuntu:~/teacher_li/chp13-linker$ ls -l /lib/libc-2.11.1.so
	-rwxr-xr-x 1 root root 1335560 2011-01-21 15:53 /lib/libc-2.11.1.so


# chp16 指针高级
## 课堂作业
统计当前目录下所有 c 文件中，行数最多的文件以及行数。
提示： find . -name *.c -exec wc -l {} \; > myc.txt ，对 myc.txt 文件进行处理。


## 函数指针
* 使用例子： struct file_operations in fs.h 内核头文件
/usr/src/linux-headers-2.6.32-30$ vi include/linux/fs.h +1487




# chp19 链表
## 链表的节点定义
### struct node
### typedef struct node * link;

## 链表的插入操作
### 1. insert before head
### 2. insert after tail (search tail)
### 3. insert after current pos
### 4. insert before current pos (search prev)

## 链表的删除操作
### 1. delete at head
### 2. delete after head (search prev)

# 大作业--学生管理系统


## 数据文件格式
  1 # name cname age gender native mobile      qq         email               hobby
  2 liming  李明  35   男    陕西  13691584139 2372614758 limingth@gmail.com  乒乓,羽毛球，音乐，文学

## 数据结构定义
struct student
{
	char name[32];
	char cname[16];
	int age;
	char gender[4];
	char native[16];
	char qq[16];
	char email[32];
	char hobby[128];
};
typedef struct student stu_t;

## 功能需求分析
1. 列出学生信息
2. 按某种条件进行排序功能（name，age）
3. 按某种条件进行查找功能（native, hobby）

ssh 192.168.102.136

## 模块设计与接口分析
1. 有几个 .c 文件？  .h 文件？
main.c
fileio.c
shell.c
func.c 

public.h

2. 每个 .c 文件做什么？
main.c -> main()

#include "func.h"
int load(int argc, char *argv[]);
int list(int argc, char *argv[]);
int sort(int argc, char *argv[]);
int find(int argc, char *argv[]);

struct cmd
{
	char name[16];
	int (*pf)(int argc, char *argv[]);
} cmds[] =
{
	"load", load,
	"list", list,
	"sort", sort,
	"find", find
};

int main(void)
{
	while (1)
	{
		char buf[128];

		fgets(buf, 128, stdin);

		parse(buf, &argc, argv);

		for (i = 0; i < sizeof(cmds)/sizeof(cmd[0]); i++)
			if (strcmp(argv[0], cmds[i].name) == 0)
				cmds[i].pf(argc, argv);
	}
}

fileio.c -> load(filename, &students)
完成从 数据文件到结构体的加载

shell.c -> parse(buf, argc, argv)
实现对用户命令的解析

func.c -> list()
	-> sort_by_name()
	-> sort_by_age()
	-> find_native(s)
	-> find_hobby(s)
完成用户命令的实现

先实现用户命令处理模块，再实现文件处理模块，最后实现用户功能模块

3. 最常用的接口有哪些？

# chp20 二叉树
## 基本概念
* 二叉树 Binary tree
* 满二叉树
* 完全二叉树
* 排序二叉树
* 平衡二叉树

## 遍历
* 前序
* 中序
* 后序

* 重要结论： 前序和中序能够唯一确定二叉树； 中序和后序也可以； 前序和后序则不行！


# 快译通项目开题
## 预备知识
* find . -name "*" | xargs ls -l | awk '{ print $5 " " $0 }' | sort -n
* find . -name ret.txt -exec rm {} \;

https://github.com/limingth/lexico-c-flex.git

## Git 命令
* git clone
* git pull
* git push
* git config



















