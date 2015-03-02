# fdelta, fapply
fdelta and fapply are command-line tools for creating and applying delta 
files in [Fossil delta format](http://fossil-scm.org/index.html/doc/trunk/www/delta_format.wiki).

### Installation
    git clone https://github.com/olov/fdelta.git
    cd fdelta
    ./build.sh
    cp dist/fdelta dist/fapply ~/bin # or wherever

### Usage
    fapply original delta (modified is written to stdout)
    fdelta original modified (delta is written to stdout)

### Example
`./fdelta fdelta.c fapply.c` produces
```
Gh
Aj@0,U:apply original delta\nmodified1k@BC,M:delta;
  int64_t deltaN@DD,8:delta);
L@C~,O:delta_output_size(delta,7@Ez,5:len);9@Df,1W:mod = calloc(1, mod_len + 1);
  delta_apply(orig, orig_len, delta, delta_len, mod);

  fputs(modQ@Fz,35RCZe;
```

### License
See [LICENSE](LICENSE) file.
