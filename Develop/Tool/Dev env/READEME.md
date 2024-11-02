





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









### <img src="./images/linux.png" alt="linux" style="zoom:5%;" />Linux

###### Elevate  privileges

```shell
sudo usermod -aG sudo $USER
```

- Promote current user

- `a`   -   append

  `G`   -   groups



###### Common applications

```shell
sudo apt update
sudo apt install gcc
sudo apt install git 
sudo apt install neovim
```





#### <img src="./images/Zsh.png" align="left" alt="Zsh" />[Zsh](https://github.com/zsh-users/zsh)



##### Install

```shell
sudo apt update
sudo apt install zsh
```



##### Change default

```shell
chsh -s $(which zsh)
```

- Restart shell
- Recommend `0`





#### <img src="./images/Starship.png" alt="Starship" align="left" style="zoom:8%;" />[Starship](https://starship.rs/)



##### Install

```shell
curl -sS https://starship.rs/install.sh | sh
```



##### Set up shell to use it

Add the following to the end of ~/.zshrc

```shell
eval "$(starship init zsh)"
```

```shell
source ~/.zshrc 
```



##### [Configure](https://starship.rs/presets/)

```toml
nvim ~/.config/starship.toml
```



###### Recommended

```toml
starship preset no-runtime-versions -o ~/.config/starship.toml
```



### syntax-highlighting & autosuggestions

```shell
sudo apt install zsh-syntax-highlighting zsh-autosuggestions
```



End of ~/.zshrc

```shell
source /usr/share/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh
source /usr/share/zsh-autosuggestions/zsh-autosuggestions.zsh
```

```shell
source ~/.zshrc 
```




# <img src="./images/wezterm.png" alt="wezterm" style="zoom: 25%;" />Wezterm







## Configuration



> It will automatically reload, and can manually reload it using `CTRL+SHIF+R`

- Locaton

  `$HOME/.config/wezterm/wezterm.lua`





### Fonts



<img src="./images/JetBrains Mono.png" alt="JetBrains Mono" align="left" style="zoom:35%;" />[JetBrains Mono](https://www.jetbrains.com/lp/mono/)





<img src="./images/Nerdfonts.png" alt="Nerdfonts" align="left" style="zoom: 15%;" />[Nerd-fonts](https://github.com/ryanoasis/nerd-fonts/releases/tag/v3.2.1)

> Recommend	-	[Fira Code](https://www.programmingfonts.org/#firacode)





### Configuration


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
    automatically_reload_config = true,
    hide_tab_bar_if_only_one_tab = true,
    show_new_tab_button_in_tab_bar = false,
    adjust_window_size_when_changing_font_size = false,
    
    default_cursor_style = "BlinkingBar",
    window_close_confirmation = "NeverPrompt",
    
    window_padding = {	-- The distance between the content and the windows edges
        left = 20,
        right = 20,
        top = 20,
        bottom = 5,
    },
    
    background = {
    {
      source = {
        File = "C:\\Users\\" .. os.getenv("USERNAME") .. "\\.config\\wezterm\\1.jpg",
      },
      hsb = {
        hue = 1.0,
        saturation = 1.00,
        brightness = 1,
      },
    },
    {
	-- Add a blur effect
      source = {
        Color = "#282c35",
      },
      width = "100%",
      height = "100%",
      opacity = 0.55,
    },
  },
  -- Set initial size
    initial_rows = 150,  
    initial_cols = 100, 
   
  -- Default program and change to a specific directory
    default_prog = { "wsl.exe", "--cd", "/home/vladelaina" },
}

return config

```







# <img src="./images/nvim-icon.png" alt="nvim-icon" style="zoom:20%;" />Nvim
