set number
set background=dark
set autoindent
set autochdir
set tabstop=4

color gruvbox

nnoremap <F9> :! make "%:r"<CR>
nnoremap <F5> :!./%< <CR>
nnoremap <F4> :! submit "%:r"<CR>
nnoremap <c-s> :w<CR>
imap <c-s> <Esc> :w<CR>

ERASE THIS (https://vimcolorschemes.com/morhetz/gruvbox)
