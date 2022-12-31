## Windows和Linux系统时间同步

**让 Windows 把硬件时间当作 UTC** 

打开powershell（管理员）或者cmd（管理员），输入下面命令并回车

```powershell
Reg add HKLM\SYSTEM\CurrentControlSet\Control\TimeZoneInformation /v RealTimeIsUniversal /t REG_DWORD /d 1
```



---

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



---

## Systemd

虽然经常被诟病过于专制，~~但是好用啊~~，常通过systemctl控制

|                  动作                  |                  命令                   |
| :------------------------------------: | :-------------------------------------: |
|            **显示系统状态**            |           `systemctl status`            |
|         **列出正在运行的**单元         |  `systemctl` or `systemctl list-units`  |
|           **列出失败的**单元           |          `systemctl --failed`           |
|          **列出已安装的**单元          |       `systemctl list-unit-files`       |
|                                        |                                         |
|          显示单元的**手册页**          |         `systemctl help *单元*`         |
|           显示单元的**状态**           |        `systemctl status *单元*`        |
|     **检查**单元是否配置为自动启动     |      `systemctl is-enabled *单元*`      |
|                                        |                                         |
|            立即**启动**单元            |    `systemctl start *单元*` as root     |
|            立即**停止**单元            |     `systemctl stop *单元*` as root     |
|            **重新启动**单元            |   `systemctl restart *单元*` as root    |
|        **重新加载**单元及其配置        |    `systemctl reload *单元*` as root    |
|                                        |                                         |
|          开机自动**启用**单元          |    `systemctl enable *单元*` as root    |
| 开机自动**启用**单元，并立即**启动**它 | `systemctl enable --now *单元*` as root |
|        **取消**开机自动启用单元        |   `systemctl disable *单元*` as root    |
|                                        |                                         |
|       **禁用**单元，使其无法启动       |     `systemctl mask *单元*` as root     |
|            **取消禁用**单元            |    `systemctl unmask *单元*` as root    |

安装 `polkit `后才能以普通用户身份使用电源管理。

|                   动作                   |           命令           |
| :--------------------------------------: | :----------------------: |
|                   重启                   |    `systemctl reboot`    |
|                   关机                   |   `systemctl poweroff`   |
|                   待机                   |   `systemctl suspend`    |
|                   休眠                   |  `systemctl hibernate`   |
| 进入混合休眠模式（同时休眠到硬盘并待机） | `systemctl hybrid-sleep` |

**即使标注了as root**，普通用户也可以不使用`sudo`，执行时会自动提示输入密码，如果在wm中需要弹出式窗口，安装`polkit-gnome`并设置自启`/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1`，在对应的wm中配置（如hyprland中在`~/.config/hypr/hyprland.conf`中增加一行`exec-once = /usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1`）或者在启动的shell中配置（如zsh的.zprofile或者.zlogin)(**未验证**)

部分命令也可搭配`--type`参数，如`systemctl list-unit-files --type=service`仅列出服务



---

## 用户组

### 修改登录名或主目录

更改用户主目录：

```
usermod -d /my/new/home -m username
```

`-m` 选项会自动创建新目录并移动内容。

更改用户登录名：

```
# usermod -l newname oldname
```

> [!WARNING]
>
> 确保你不是使用你要修改的用户名登录

### 其他用户管理示例

将用户加入 `*群组*`，用逗号分隔:

```
# usermod -aG 群组 username
```

> [!WARNING]
>
> 如果不使用 `-a` 选项，用户会离开没有列在`*群组*`的其它群组。

要修改用户的登录 shell:

```
# usermod -s /bin/bash username
```

使用`userdel`命令删除用户：

```
# userdel -r [用户名]
```

`-r`选项表示一并删除用户主目录和邮件。

## 用户组管理

使用`groups`命令查看用户所在组的名称：

```
$ groups [用户名]
```

若省略用户名，默认显示当前用户所在组。

`id`命令提供额外的信息，包括用户UID以及相关用户组GID：

```
$ id [用户名]
```

查看所有组：

```
$ cat /etc/group
```

使用`groupadd`创建新的组：

```
# groupadd [组名]
```

使用`gpasswd`将用户添加到组：

```
# gpasswd -a [用户名] [组名]
```

更改用户所属的组名，不变更`GID`：

```
# groupmod -n newname oldname
```

删除用户组：

```
# groupdel [组名]
```

将用户从组中移除：

```
# gpasswd -d [用户名] [组名]
```

如果用户已登录，必须重新登录使更改生效，如加入`input`组之后仍然无法使用`light`控制亮度。