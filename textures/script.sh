#!/bin/sh

for file in *.png
do
    [ -f "$file" ] || continue
    base="${file%.png}"
    echo "Conversion de $file -> $base.xpm"
    magick "$file" -compress none XPM:"$base.xpm"
done
