# >>> conda initialize >>>
# !! Contents within this block are managed by 'conda init' !!
__conda_setup="$('/Users/hyungjaekim/opt/anaconda3/bin/conda' 'shell.bash' 'hook' 2> /dev/null)"
if [ $? -eq 0 ]; then
    eval "$__conda_setup"
else
    if [ -f "/Users/hyungjaekim/opt/anaconda3/etc/profile.d/conda.sh" ]; then
        . "/Users/hyungjaekim/opt/anaconda3/etc/profile.d/conda.sh"
    else
        export PATH="/Users/hyungjaekim/opt/anaconda3/bin:$PATH"
    fi
fi
unset __conda_setup
# <<< conda initialize <<<


##
# Your previous /Users/hyungjaekim/.bash_profile file was backed up as /Users/hyungjaekim/.bash_profile.macports-saved_2021-08-11_at_13:17:43
##

export PATH=$PATH:~/scripts/
export PATH=$PATH:~/cp/library/
ulimit -s unlimited

find ~/scripts/ -type f -iname "*.sh" -exec chmod +x {} \;
find ~/cp/library/ -type f -iname "*.cpp" -exec chmod +x {} \;
find ~/cp/library/ -type f -iname "*py" -exec chmod +x {} \;

# MacPorts Installer addition on 2021-08-11_at_13:17:43: adding an appropriate PATH variable for use with MacPorts.
export PATH="/opt/local/bin:/opt/local/sbin:$PATH"
# Finished adapting your PATH environment variable for use with MacPorts.

