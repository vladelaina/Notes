





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
			  Ubuntu-24.04
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



```shell
git clone https://github.com/tree-sitter/tree-sitter-c.git
cd tree-sitter-c
gcc -shared -o parser.so parser.c -fPIC
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







# Pending

推荐你安装 Node.js 的原因主要是因为它是使用 Tree-sitter CLI 的一个常见依赖。Tree-sitter CLI 是一个用于构建和管理语言解析器的工具，它需要 Node.js 环境来运行。因此，如果你希望使用 Tree-sitter 进行代码高亮、语法分析等功能，安装 Node.js 是必要的步骤。

此外，Node.js 在开发中有很多其他用途，例如构建后端服务、命令行工具等，安装它后，你将能够使用 npm 安装和管理其他 JavaScript 库和工具。

总之，安装 Node.js 可以让你更好地利用 Tree-sitter 的功能，同时也为你提供了一个强大的开发环境。

你可以通过以下步骤在 Ubuntu 上安装 npm（Node.js 的包管理器）：

1. **更新包列表**：

   ```bash
   sudo apt update
   ```

2. **安装 Node.js 和 npm**：

   你可以直接使用 `apt` 安装 Node.js，它通常会附带 npm：

   ```bash
   sudo apt install nodejs npm
   ```

   如果你想要安装最新版本的 Node.js，可以使用 NodeSource 提供的脚本：

   ```bash
   curl -fsSL https://deb.nodesource.com/setup_16.x | sudo -E bash -
   sudo apt install -y nodejs
   ```

   这里的 `16.x` 是 Node.js 的版本号，你可以根据需要选择不同的版本（例如 `18.x` 或 `20.x`）。

3. **验证安装**：

   安装完成后，可以通过以下命令检查 Node.js 和 npm 是否成功安装：

   ```bash
   node -v
   npm -v
   ```

   这将显示安装的版本号。

完成这些步骤后，你就可以使用 npm 来安装 Tree-sitter CLI 或其他 Node.js 包了。如果有其他问题，随时告诉我！





是的，如果你在使用 Tree-sitter 的功能，但没有安装它，可能会导致错误。要安装 Tree-sitter，你可以按照以下步骤进行：

1. **安装 Tree-sitter CLI**：首先，确保你已经安装了 Tree-sitter 的命令行工具。在终端中运行以下命令：

   ```bash
   npm install -g tree-sitter-cli
   ```

   这需要你先安装 Node.js 和 npm。

2. **安装 Neovim 的 Tree-sitter 插件**：在你的 Neovim 配置中，确保已经包含了适用于 Tree-sitter 的插件，比如 `nvim-treesitter`。如果你使用 LazyVim，可以在配置文件中添加类似以下内容：

   ```lua
   require'nvim-treesitter.configs'.setup {
       ensure_installed = {"c", "lua", "python"}, -- 在这里指定你需要的语言
       highlight = {
           enable = true,              -- 开启高亮功能
       },
   }
   ```

3. **安装需要的语言解析器**：使用以下命令安装你需要的语言解析器（以 C 语言为例）：

   ```bash
   :TSInstall c
   ```

4. **重新启动 Neovim**：完成安装后，重新启动 Neovim，检查是否还存在错误。

这样，你就可以在 Neovim 中使用 Tree-sitter 的高亮和其他功能了。如果还有其他问题，随时问我！
