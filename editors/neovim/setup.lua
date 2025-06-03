local configs = require('lspconfig.configs')
local lspconfig = require('lspconfig')

vim.filetype.add({
  extension = {
    pl = "prolog",
  }
})

configs.pls = {
  default_config = {
    -- Cmd that can startup pls server: in this case make sure that pls executable in the shell
    cmd = { "pls" },
    filetypes = { "prolog" },
    root_dir = lspconfig.util.root_pattern(".git", ".mylangroot"),
    settings = {},
  }
}

-- Setup The Server
lspconfig.pls.setup({})

