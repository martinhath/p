#p

A really small unix utility that prints `stdin` to `stdout` and `stderr`.
This might be useful when piping stuff, and you want to check the data that's
comming though.

```bash
echo "martiniscool" | wc
      1       1      13 #wtf happend?
```

```bash
> ehco "martiniscool" | p | wc
> ----- p begin -----
> martiniscool
> ----- p end   -----
>     1       4      31 #oh, okay.
```
