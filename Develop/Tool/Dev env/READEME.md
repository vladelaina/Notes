





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





##### Network

Add the following to the `C:\Users\<Username>\.wslconfig`

```shell
[wsl2]
networkingMode=mirrored
autoProxy=true
```



###### Close restart

```shell
wsl --shutdown
```



###### Test

```shell
curl google.com
```



### <img src="./images/linux.png" alt="linux" style="zoom:5%;" />Linux

```shell
sudo apt update
sudo apt install gcc
sudo apt install git 
sudo apt install neovim
```

```shell
sudo apt full-upgrade -y
```

- Automatically upgrade all upgradable packages and handle changes in dependedcies



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





### <img src="./images/Tree-sitter.png" alt="Tree-sitter" style="zoom: 25%;" />[Tree-sitter](https://tree-sitter.github.io/tree-sitter/)



##### 🛠️Install

```shell
sudo apt install tree-sitter-cli
```









*****




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
        left = 35,
        right = 30,
        top = 30,
        bottom = 20,
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





****



# ![Lazyvim](./images/Lazyvim.png)💤[Lazy.vim](https://www.lazyvim.org/)

> Manage plugins & updates
>
> 
>
> `Lazy.nivm` is a plugin for nvim

## 🛠️Installation

```shell
git clone https://github.com/LazyVim/starter ~/.config/nvim
```

```shell
rm -rf ~/.config/nvim/.git
```





## Configuration



### Clean || Backup

```bash
rm -rf ~/.config/nivm			#自定义配置&插件配置
rm -rf ~/.local/share/nvim		#下载的插件&扩展
rm -rf ~/.local/state/nivm		#会话&历史记录		
rm -rf ~/.cache/nvim			#临时存储文件&加快启动速度
```



### Dependencies



##### <img src="./images/Lazygit.png" alt="Lazygit" align="left" style="zoom: 5%;" />[lazygit](https://github.com/jesseduffield/lazygit?tab=readme-ov-file)



> Simple terminal UI for git commands



###### Install

```bash
LAZYGIT_VERSION=$(curl -s "https://api.github.com/repos/jesseduffield/lazygit/releases/latest" | grep -Po '"tag_name": "v\K[^"]*')
curl -Lo lazygit.tar.gz "https://github.com/jesseduffield/lazygit/releases/latest/download/lazygit_${LAZYGIT_VERSION}_Linux_x86_64.tar.gz"
tar xf lazygit.tar.gz lazygit
sudo install lazygit /usr/local/bin
```



```bash
lazygit --version
```






##### [Ripgrep](https://github.com/BurntSushi/ripgrep)

> Super fast ==text search== tool the respects `.gitignore` by default



###### Install

```bash
curl -LO https://github.com/BurntSushi/ripgrep/releases/download/14.1.0/ripgrep_14.1.0-1_amd64.deb
sudo dpkg -i ripgrep_14.1.0-1_amd64.deb
```



```bash
rg --version
```



##### fd

> ==File search== tool with a more user-friendly syntax than `find`



###### Install

```bash
sudo apt install fd-find
```



```bash
fdfind --version
```





## Use Starter Repo

```bash
git clone https://github.com/LazyVim/starter ~/.config/nvim
rm -rf ~/.config/nvim/.git
```



#### Doshboard



##### `nvim`

<img src="./images/Clip_2024-09-23_18-41-43.png" alt="Clip_2024-09-23_18-41-43" align="left" style="zoom:33%;" />



##### Plugin manager



###### Start up

>   -  `<Space> l`
>
>   
>
>   - `nvim l` 
>
>     <img src="./images/Clip_2024-10-11_21-28-54.png" align="left" alt="Clip_2024-10-11_21-28-54" style="zoom: 60%;" />
>
>   
>
>   -  `:Lazy`
>
>     ![Clip_2024-10-11_21-34-18](./images/Clip_2024-10-11_21-34-18.png)

<img src="./images/Clip_2024-09-23_23-19-56.png" alt="Clip_2024-09-23_23-19-56" style="zoom:80%;" />

- `Sync(S)` - Synchronization

  Equivalent to running **install**, **cleanup**, and **update** simultaneously



****



##  Modal Editing

> Each ==mode== allows for ==specific operations==



### Introduction



**clipboard**(i.e. “Registers” mini-mode) 	

- `Ctrl-r`(in <img src="./images/INSERT.png" alt="INSERT" style="zoom:25%;" />)
- `"` (in <img src="./images/NORMAL.png" alt="NORMAL" style="zoom:25%;" />) 

<img src="./images/Clip_2024-10-14_11-14-47.png" align="left" alt="Clip_2024-10-14_11-14-47" style="zoom:40%;" />

- Paste: `Ctrl-r` followed by the `+`
- In <img src="./images/NORMAL.png" alt="NORMAL" style="zoom: 25%;" />mode, `Ctrl-r` is used to “**redo**”(i.e. undo an undo)



> p	put	paste
>



I i	$\Longleftrightarrow$	aA

gi(<img src="./images/goto.png" alt="goto" style="zoom:35%;" />the last place)



O

o





Visual Mode



Find Files

<img src="./images/Clip_2024-10-11_22-12-17.png" align="left" alt="Clip_2024-10-11_22-12-17" style="zoom:35%;" />

- Double click on the space
- <space> ff









#### Command mode

> Work in Insert mode also work in Command mode(include `Ctrl-r` to paste)



q!



:wq = :x



:w file.name

> will save the file with the given name



`:e` or `:edit`

> Open on filesystem
>
> 
>
> `:e foo/baz/fizz.txt`		-	Open the `fizz.txt` file
>
> - Can use ==Tab== completion
>
>   > :e ==/==<Tab>f<Tab>b<Tab>f<Tab>

```bash
/
└── foo
    ├── bar
    └── baz
    │   └── fizz.txt
```





`TAB`	-	competion

![Clip_2024-10-15_11-31-34](./images/Clip_2024-10-15_11-31-34.png)

- Use ⬅/➡ to move the cursor Up/Down

- **Suggest** using ==Tab== and ==Shift-Tab== to select different entries from the menu
