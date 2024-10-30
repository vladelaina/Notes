





# <img src="./images/WSL.png" alt="WSL" style="zoom: 25%;" />WSL

### <img src="./images/启用或关闭windows功能.png" alt="启用或关闭windows功能" style="zoom:25%;" />启用或关闭windows功能

<img src="./images/image-20241021224830326.png" align="left" alt="image-20241021224830326" />





### Install



###### renew

```shell
wsl --update
```



###### View installable

```shell
wsl -l -o
```

- `-o` online



###### Install

```shell
wsl --install VersionName --web-download
```



###### Uninstall

```shell
wsl --unregister VersionName
```



###### Start up

```shell
wsl -d VersionName	/	wsl 
```



###### Network

To `.bashrc`

```shell
host_ip=$(cat /etc/resolv.conf | grep "nameserver" | cut -f 2 -d " ")
export ALL_PROXY="http://$host_ip:10809"
```





<img src="./images/image-20241030195706956.png" align=
left alt="image-20241030195706956" style="zoom: 80%;" />



### <img src="./images/linux.png" alt="linux" style="zoom:5%;" />Linux

```shell
sudo apt update
sudo apt install gcc
sudo apt install git 
sudo apt install neovim
```



###### <img src="./images/Starship.png" alt="Starship" align="left" style="zoom:8%;" />[Starship](https://starship.rs/)

```shell
curl -sS https://starship.rs/install.sh | sh
```



Add the following to the end of ~/.bashrc

```shell
eval "$(starship init bash)" 
```

```shell
source ~/.bashrc 
```




# <img src="./images/wezterm.png" alt="wezterm" style="zoom: 25%;" />Wezterm







## Configuration



> It will automatically reload, and can manually reload it using `CTRL+SHIF+R`

- Locaton

  `$HOME/.config/wezterm/wezterm.lua`





<img src="./images/JetBrains Mono.png" align="left" alt="JetBrains Mono" style="zoom: 25%;" />[JetBrains Mono](https://www.jetbrains.com/lp/mono/)

> Install everything in **ttf**




```lua
local wezterm = require("wezterm")

local config = {
    font_size = 20,
    
    -- Using a regular weight font
    font = wezterm.font("JetBrains Mono NL", { weight = "Regular" }),
    
    -- Allow dragging the edges to resize
    window_decorations = "RESIZE",
    
    
    color_scheme = "Catppuccin Mocha",
    
    -- opacity
    text_background_opacity = 0.8,
    window_background_opacity = 0.8,
    
      
    use_fancy_tab_bar = false,
    hide_tab_bar_if_only_one_tab = true,
    show_new_tab_button_in_tab_bar = false,
    adjust_window_size_when_changing_font_size = false,
    window_close_confirmation = "NeverPrompt"
    
    window_padding = {	-- The distance between the content and the windows edges
        left = 20,
        right = 20,
        top = 20,
        bottom = 5,
    },
    
}

return config

```





To_do 

```lua
local wezterm = require("wezterm")  -- 引入 wezterm 模块
config = wezterm.config_builder()     -- 创建配置构建器

config = {
    automatically_reload_config = true,  -- 自动重新加载配置
    enable_tab_bar = false,               -- 禁用标签栏
    window_close_confirmation = "NeverPrompt", -- 窗口关闭时不提示确认
    window_decorations = "REsIzE",        -- 禁用标题栏但启用可调整大小的边框
    default_cursor_style = "BlinkingBar", -- 默认光标样式为闪烁条形
    color_scheme = "Nord (Gogh)",        -- 设置颜色主题为 Nord (Gogh)
    font = wezterm.font("JetBrains Mono", { weight = "Bold" }), -- 设置字体为 JetBrains Mono，加粗
    font_size = 12.5,                     -- 设置字体大小
}

return config  -- 返回配置

```



# <img src="./images/nvim-icon.png" alt="nvim-icon" style="zoom:20%;" />Nvim
