## Windows和Linux系统时间同步

**让 Windows 把硬件时间当作 UTC** 

打开powershell（管理员）或者cmd（管理员），输入下面命令并回车

```powershell
Reg add HKLM\SYSTEM\CurrentControlSet\Control\TimeZoneInformation /v RealTimeIsUniversal /t REG_DWORD /d 1
```



## 关于GRUB的美化

[在此](https://www.pling.com/browse?cat=109&ord=latest)选择一个下载，解压出来的文件夹，复制

```bash
sudo cp -rf . /usr/share/grub/themes/<themename>
```

以将主题放置在系统的 GRUB 默认文件夹内。

编辑 `/etc/default/grub` 文件，修改 `#GRUB_THEME=` 一行，将前面的注释去掉，并指向主题的 `theme.txt` 文件。即

```bash
# GRUB_THEME= 
# 修改为
GRUB_THEME="/usr/share/grub/themes/<themename>/theme.txt"
```

然后再在终端输入

```bash
grub-mkconfig -o /boot/grub/grub.cfg
```