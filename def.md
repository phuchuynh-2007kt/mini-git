git - vsc 

older vscs only record the difference over time while git literally take a snap shot of the of the entire new file, hashes it and store it as brand new entity. 
-> that's the main reason git uses 
blob( binary large object): raw files 'content
tree: a list of mapping names
commit: the top of the tree, it holds the current data and point to the previous one 

innit 
.minigit/
├── objects/     (Where Blobs, Trees, and Commits will be stored)
└── refs/        (Where branch pointers, like 'main', will live)
    └── heads/
