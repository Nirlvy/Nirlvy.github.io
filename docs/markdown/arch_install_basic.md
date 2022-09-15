## 前言

此次安装教程基于Virtualbox以方便截图

教程来源于多处加上自己习惯改编

[在家无聊？一起来装Arch Linux吧！（安装篇）作者：NeMaZHENG](https://www.coolapk.com/feed/16407712?shareKey=YzZhZjQwNDg5YTY0NjMxMDcwNTY~&shareUid=2991758&shareFrom=com.coolapk.market_12.4.2)

[Arch Linux安装好了该做什么？进来康康 作者：NeMaZHENG](https://www.coolapk.com/feed/16504103?shareKey=ZTA0NDM4NmQxYzVkNjMxMDcwZjA~&shareUid=2991758&shareFrom=com.coolapk.market_12.4.2)

[archlinux 简明指南 — Arch Linux 安装使用教程](https://arch.icekylin.online/prologue.html)

[Arch Linux 安装使用教程 - ArchTutorial - Arch Linux Studio](https://archlinuxstudio.github.io/ArchLinuxTutorial/#/)

[官方教程](https://wiki.archlinux.org/title/Installation_guide_(%E7%AE%80%E4%BD%93%E4%B8%AD%E6%96%87))

排名不分先后

---

## 开始安装

选1或者3都行

![install](../pic/image-20220901170332317.png ':size=60%')

漆黑的命令行

![install](../pic/image-20220901170637154.png ':size=60%')

> [!NOTE] 
>
> Linux[#](https://code.visualstudio.com/docs/editor/settings-sync#_linux)
>
> If the keychain throws the error "No such interface "org.freedesktop.Secret.Collection" on object at path /org/freedesktop/secrets/collection/login", try following the steps described in [issue #92972](https://github.com/microsoft/vscode/issues/92972#issuecomment-625751232) to create a new keyring.
>
> If the error is "Writing login information to the keychain failed with error 'Unknown or unsupported transport “disabled” for address “disabled:”'", check that `dbus-launch` has been started by following the instructions in [issue #120392](https://github.com/microsoft/vscode/issues/120392#issuecomment-814210643).
>
> If the error is "The name org.freedesktop.secrets was not provided by any .service files", make sure that you have a package that implements the [Secret Storage API](https://www.gnu.org/software/emacs/manual/html_node/auth/Secret-Service-API.html) installed, such as `gnome-keyring`. VS Code expects such a package for storing credentials on the machine. More information can be found in [issue #104319](https://github.com/microsoft/vscode/issues/104319#issuecomment-1057588052).
>
> If the error is "Writing login information to the keychain failed with error 'Cannot create an item in a locked collection'.", you need to:
>
> 1. Add the following lines to your `~/.xinitrc`:
>
>    ```
>    # see https://unix.stackexchange.com/a/295652/332452
>    source /etc/X11/xinit/xinitrc.d/50-systemd-user.sh
>    
>    # see https://wiki.archlinux.org/title/GNOME/Keyring#xinitrc
>    eval $(/usr/bin/gnome-keyring-daemon --start)
>    export SSH_AUTH_SOCK
>    
>    # see https://github.com/NixOS/nixpkgs/issues/14966#issuecomment-520083836
>    mkdir -p "$HOME"/.local/share/keyrings
>    ```
>
> 2. Login again.
>
> 3. Have the following programs installed (installation assumes arch/pacman, should be similar to other distros):
>
>    ```
>    sudo pacman -S gnome-keyring libsecret libgnome-keyring
>    ```
>
> 4. Launch `seahorse`, unlock the default password keyring or create a new one, and keep it unlocked.
>
> 5. Restart the login procedure.
