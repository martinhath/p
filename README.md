#p

A really small unix utility that prints `stdin` to `stdout` and `stderr`.
This might be useful when piping stuff, and you want to check the data that's
comming though.

```bash
echo "martiniscool" | wc
      1       1      13 #wtf happend?
```

```bash
echo "martiniscool" | p | wc
----- p begin -----
martiniscool
----- p end   -----
      1       1      13 #oh, okay.
```

## Command line arguments
| argument | long form | function|
|----------|-----------|---------|
| `-p`     | `--prints`| Shows header and footer |
| `-c`     | `--color` | Colors the text |

### Screenshot

![screenshot](http://i.imgur.com/FhVlAty.png)
