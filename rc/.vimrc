set tabstop=4
set nocompatible
set shiftwidth=4
set expandtab
set autoindent
set smartindent
set ruler
set showcmd
set incsearch
set shellslash
set number
set relativenumber
set cino+=L0
syntax on
filetype indent on
filetype off
setlocal indentkeys-=:

inoremap {<CR> {<CR>}<Esc>O
inoremap {} {}
imap jk <Esc>
map <C-a> <esc>ggVG<CR>
set belloff=all

autocmd BufNewFile *.cpp 0r /home/hkim/cp/library/template.cpp

autocmd filetype cpp nnoremap <F9> :w <bar> !build.sh %:r <CR>
autocmd filetype cpp imap <buffer> <F9> <esc>:w<bar> !build.sh %:r <CR>
autocmd filetype cpp nnoremap <F10> :!./%:r<CR>
autocmd filetype cpp imap <buffer> <F10> <esc>:w<CR>:!./%:r<CR>
autocmd FileType python map <buffer> <F8> :w<CR>:exec '!python3' shellescape(@%, 1)<CR>
autocmd FileType python imap <buffer> <F8> <esc>:w<CR>:exec '!python3' shellescape(@%, 1)<CR>

autocmd FileType tex :NoMatchParen
autocmd FileType tex :set tw=110

set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
Plugin 'VundleVim/Vundle.vim'
Plugin 'lervag/vimtex'
Plugin 'octol/vim-cpp-enhanced-highlight'
Plugin 'NLKNguyen/papercolor-theme'
call vundle#end()
filetype plugin indent on
let g:vimtex_view_general_viewer = 'SumatraPDF'
let g:vimtex_view_general_options = '-reuse-instance @pdf'
let g:vimtex_view_general_options_latexmk = '-reuse-instance'
let g:tex_flavor = 'latex'
let g:vimtex_motion_matchparen = 0
let g:vimtex_fold_manual = 1
let g:vimtex_matchparen_enabled = 0

set t_Co=256
set background=light
colorscheme PaperColor

let s:clip = '/mnt/c/Windows/System32/clip.exe'  " change this path according to your mount point
if executable(s:clip)
        augroup WSLYank
                    autocmd!
                            autocmd TextYankPost * if v:event.operator ==# 'y' | call system(s:clip, @0) | endif
                                augroup END
                            endif

        au BufNewFile,BufRead *.tex
            \ set nocursorline |
            \ set nornu |
            \ set number |
            \ let g:loaded_matchparen=1 |
