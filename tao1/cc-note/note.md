# C

_Program Library Howto_

# vim
## my vim slide

     http://vim-showoff-peter.heroku.com

## general command rule

command = operator + number + motion
## vimrc

~/.vimrc

## get peter's config

http://happypeter.github.com/GitBeijing/vim-conf-share.html

## vim mode
	
	:h vim-modes

save and quit:

	:wq

quit without saving

	:q!
## vim ctags
    
    ctags hello.c
    vim hello.c
    # move to the function call
    Ctrl-]
    Ctrl-o

## insert mode commands

    Ctrl-n

    Ctrl-x-l

    Ctrl-x-k ## :set spell

    Ctrl-x-f

    check :h i_Ctrl-<tab>


# Bash
## hen 

https://github.com/happypeter/hen.git

GUI -> Command Line
ls -> list
cd -> Change Directroy (No folder)
## script language

- usually is interpreted language
- run some fucntions of a specific program

## tab completion

	cd first-<tab>

## path

abs path

rel path

##pkg

		sudo apt-get install git-core
### install mannually

	chmod +x tool.sh
	sudo mv tool.sh /bin

		wget 122.115.61.189/tmp/cc-note

# git

	git pull # get the latest updates

### video

    wget 122.115.61.189/happycasts/happygit-zh/git_start.ogv

## TODO

    Ctrl-x-k ## :set spell
    git branch 

### ~/.gitconfig

    [user]
    name = Peter Wang
    email = happypeter1983@gmail.com
    [core]
    editor = vim
    [alias]
    ci = commit -a -v
    co = checkout
    st = status
    br = branch
    throw = reset --hard HEAD
    throwh = reset --hard HEAD^
    [color]
    ui = true

    [commit]
    template = ./.commit-template
    [push]
    default = current
## LGCB

http://happypeter.github.com/LGCB

## for fun

search "steve jobs stanford" in youku.com

check the book _The art of unix programming_

## peter job hunting

http://happypeter.users.sourceforge.net/asianux_get_job.html

### Markdown

	# h1
	## h2

	content
	__bold__ _it_


run these:

	vim xx.md
	markdown xx.md > xx.html
	firefox xx.html
### music

serach "the pretty reckless"

### video

www.akae.cn
