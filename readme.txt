To handle the memory allocation requests, a new memory allocator was written. 

How it works:

The 512KB RAM module uses 32 16KB "virtual" RAM pages, mapped to one of 4 "physical" pages 0000-3FFF, 4000-7FFF, 8000-BFFF and C000-FFFF. Any virtual page can be mapped to any physical page.

The memory physical area from 8000H to BFFFH (let's name-it "work area") is used to load one of the 32 "virtual" 16KB pages from the 512KB RAM, and the memory allocator returns a pointer to the available buffer and a byte containing the index of the 16KB page that contains this buffer (let's name-it "page index"). 

When that buffer needs to be accessed for read/write operations, the 16KB RAM page must be first loaded into the "work area", using a function call with the "page index" as parameter.

Of course, to "free" the allocated buffer, this "page index" must be provided too.

Text files up to 350KB can be edited.

The 521KB version can be run on any CP/M version, regardless of its TPA area size.
