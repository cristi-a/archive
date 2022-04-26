set number
set background=dark
set autoindent
set autochdir
set tabstop=4

color gruvbox -> ERASE THIS (https://vimcolorschemes.com/morhetz/gruvbox)

nnoremap <F9> :make %< <CR>
nnoremap <F5> :!./%< <CR>
nnoremap <c-s> :w<CR>
imap <c-s> <Esc> :w<CR>
