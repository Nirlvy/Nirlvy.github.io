## 前言

此次安装教程基于archlinux-2022.12.01-x86_64.iso，请**注意时效性**

使用Virtualbox以方便截图



---

## 开始安装

电脑启动选择镜像作为启动，选择第一个开始安装。~~在以前的版本中有复制到内存中的选项该版本没有~~

>[!TIP]
>
>使用<code>clear</code>命令清屏
>
>使用tab按键自动补全
>
>使用<code>rmmod pcspkr</code>或者<code>xset b off</code>命令关闭蜂鸣器（待验证）~~该版本iso虚拟机未报警实体机待验证~~



-----------

## 连接网络（安装必须需要网络连接）

### 网卡可用性检查

先使用<code>ip link</code>检测网络接口，如果无线网卡不能（特别是螃蟹卡）需先连接有线网络

![image-20221227222126563](../pic/image-20221227222126563.png ':size=70%')

如上实例，1为系统自身的虚拟接口（local），2是有线网卡接口（enp\*\*\*），3为无线网卡接口（wlp\*\*\*）

### 确认网卡已开启电源

在检查完之后执行<code>rfkill list</code>确认没有被rfkill所关闭。确保网卡下方的soft block显示的是**no**，如果为**yes**，执行<code>rfkill unblock wlan</code>

### 有线网卡

在确认已连接之后。输入命令<code>dhcpcd</code>即可

![image-20221227222920618](../pic/image-20221227222920618.png ':size=50%')

### 无线网卡（内置）

```bash
iwctl # iwd命令行控制
device list # 列出无线网卡设备名，wlan0等
station wlan0 scan # 扫描网络
station wlan0 get-networks # 列出所有 wifi 网络，无法显示中文（下图显示因为不是在tty中）
station wlan0 connect <wifi-name> # 连接，回车后输入密码再回车，同样无法连接带有中文的名称或者密码的wifi
exit # 连接成功后退出
```

![image-20221227231653292](../pic/image-20221227231653292.png)

